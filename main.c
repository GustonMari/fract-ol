/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmary <gmary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 09:20:55 by gmary             #+#    #+#             */
/*   Updated: 2022/01/18 16:29:35 by gmary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

int	deal_key(int key, void *param)
{
	//(void)key;
	(void)param;
	if (key)
		printf("jkdhjfdhskfjhdskjhfkjhfkdhskfj\n");
	return (0);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bpp / 8));
	*(unsigned int*)dst = color;
}


/* 0xTTRRGGBB, 0x00FF0000 => red equivaut a (0,255,0,0), 0xFFFFFF => white */
int	create_color(int t, int r, int g, int b)
{
	int colors;

	colors = 0;
	colors |= b;
	colors |= g << 8;
	colors |= r << 16;
	colors |= t << 24;
	return (colors);
}

int	mouse_scroll(int mouse, int x, int y, t_ptr *pgm)
{
	//static int i = 0;
	(void)pgm;
	(void)x;
	(void)y;
	//double	temp;
	if (mouse == 4)
	{
		mlx_mouse_get_pos(pgm->mlx, pgm->win, &pgm->mouse.x, &pgm->mouse.y);
		//	pgm->mouse.move_y = 1.2 - (y *(1.2 - 1.2)/(1000 * pgm->mouse.zoom));
		pgm->mouse.move_y = (0.625 / pgm->mouse.zoom) * ((500 - y) / 64);
		pgm->mouse.move_x = (0.0625 / pgm->mouse.zoom) * ((666 - x) / 64);
		pgm->mouse.zoom += 0.1;
	}
	if (mouse == 5)
	{	
		if (pgm->mouse.zoom > 1)
		{
			mlx_mouse_get_pos(pgm->mlx, pgm->win, &pgm->mouse.x, &pgm->mouse.y);
			pgm->mouse.zoom -= 0.2;
		}
	}
	return (0);
}

int	ft_close(t_ptr *pgm)
{
	mlx_destroy_window(pgm->mlx, pgm->win);
	return (0);
}


// PREMIER PB A GERER EST PQ LA FONCTION ZOOM DEFONCAIS MON MOUSE_GET_POS ????? surement mlx_loop_hook

void	pgm_image_init(t_ptr *pgm, t_data *image)
{
	pgm->mlx = mlx_init();
	pgm->win = mlx_new_window(pgm->mlx, 1000, 1000, "hello");
	image->img = mlx_new_image(pgm->mlx, 1000, 1000);
	image->addr = mlx_get_data_addr(image->img, &image->bpp, &image->line_length, &image->endian);
	//pgm->mouse->img = mlx_new_image(pgm->mlx, 1000, 1000);
	//printf("1");
	//pgm->mouse->addr = mlx_get_data_addr(pgm->mouse->img, &pgm->mouse->bpp, &pgm->mouse->line_length, &pgm->mouse->endian);
	//printf("2");
	pgm->mouse.x = 0;
	pgm->mouse.y = 0;
	pgm->mouse.zoom = 1.0;
}

//void	ft_infinit_pos(t_ptr *pgm)

int	main()
{
	//t_data	image;
	t_ptr	pgm;
	
	pgm_image_init(&pgm, &pgm.image);
	//pgm_image_init(&pgm, &pgm.imge);
	//pgm.mlx = mlx_init();
	//pgm.win = mlx_new_window(pgm.mlx, 1000, 1000, "hello");
	//image.img = mlx_new_image(pgm.mlx, 1000, 1000);
	//image.addr = mlx_get_data_addr(image.img, &image.bpp, &image.line_length, &image.endian);
	

	

	//integrer t r g b a la structure image et avant de faire ca utiliser le hook afin de definir les couleurs
	//mlx_key_hook(pgm.win, deal_key, &pgm);

	mlx_mouse_hook(pgm.win, &mouse_scroll, &pgm);
	mlx_loop_hook(pgm.mlx, &print_mandelbrot, &pgm);
	//print_mandelbrot(&image, &pgm);
	//print_mandelbrot(&image, &pgm, 1000, 1000);
	//print_mandelbrot(&pgm);
	//mlx_put_image_to_window(pgm.mlx, pgm.win, pgm.image.img, 0, 0);
								//mlx_put_image_to_window(pgm.mlx, pgm.win, pgm.mouse->img, 0, 0);
	//integrer la touhe esc pour quitter la fenetre
	mlx_hook(pgm.win, 17, 02, ft_close, &pgm);
	mlx_loop(pgm.mlx);
	return (0);
}

/*
1) la distance de z par rapport a 0 + 0i ne doit pas depasser 2 sinon on pointe vers linfini
2) ici on parle de 50 iterations max pour check 1) sur geek for geek 30 suffit (la definition doit surement avoir avec ca)


on utilise + pour les reel car onse deplace de gauche a droite
et le - car on par de bas en haut, 
(MaxRe-MinRe)/(ImageWidth-1) enfaite correspond a une sorte de facteur 
qui permet le deplacement de x a partir du point minre dans ce cas

c_re = MinRe + x*(MaxRe-MinRe)/(ImageWidth-1);
c_im = MaxIm - y*(MaxIm-MinIm)/(ImageHeight-1);

au lieu d'utiliser sqrt(Zr2+Zi2) > 2 pour savoir si le point tend vers linfini 
on peu tout mettre au carre et se debarasser de la racine carre on a donc (Zr2+Zi2) > 4

integrer t r g b a la structure image et avant de faire ca utiliser le hook afin de definir les couleurs
----------------------------------------------------------------------------------------------------------------------------------
ZOOM:

pour convertir la position de la souris sur un autres plan:
double mouseRe = (double)mouse_x / (WIN_L / (e->Re.max - e->Re.min)) + e->Re.min;
double mouseIm = (double)mouse_y / (WIN_H / (e->Im.max - e->Im.min)) + e->Im.min;
-------------------------------------------------------------------------------
OFFSET = 0.0625
// Ma fractale était affichée dans une section de 800x800 pixels
// Prenant pour origine le pixel [399,399] comme origine du repère orthogonal
// La formule suivante est pour le cas où la coordonnée de ton écran sur
// Laquelle tu zoomes correspondrait à un complexe avec une partie réelle
// Négative et une partie complexe négative (quart du repère à droite de
// Des absices et à gauche de celui des ordonnées

// y et x sont les coordonnées de ta souris
// le zoom est arbitraire et la division par 64 ainsi que l'OFFSET permettent
// de mitiger l'effet exponentiel du zoom sans que t'ai besoin de scroller
// des plombes pour progresser

offset_y = (OFFSET / zoom) * ((400 - y) / 64)
offset_x = (OFFSET / zoom) * ((400 - x) / 64)
zoom *= 1.1
----------------------------------------------------------------------
mlx_do_sync(mlx_ptr)
mlx_mouse_pos
mlx_mouse_move





*/


/*
	void	*ptr;
	void	*win_ptr;
	t_data	image;

	ptr = mlx_init();
	win_ptr = mlx_new_window(ptr, 500, 500, "hello");
	image.img = mlx_new_image(ptr, 500, 500);
	image.addr = mlx_get_data_addr(image.img, &image.bpp, &image.line_length, &image.endian);
	//mlx_pixel_put(ptr, win_ptr, 100, 100, 0xFFFFFF);
	my_mlx_pixel_put(&image, 20, 10, create_color(0,255,0,0));
	mlx_put_image_to_window(ptr, win_ptr, image.img, 0, 0);
	mlx_key_hook(win_ptr, deal_key, (void *)NULL);
	mlx_loop(ptr);
	return (0);
*/