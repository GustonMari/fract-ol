/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmary <gmary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 09:20:55 by gmary             #+#    #+#             */
/*   Updated: 2022/01/24 14:24:47 by gmary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

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




int	ft_close(t_ptr *pgm)
{
	//mlx_destroy_image(pgm->mlx, pgm->win);
	mlx_destroy_window(pgm->mlx, pgm->win);
	mlx_destroy_display(pgm->mlx);
	free(pgm->mlx);
	exit(0);
	//return (0);
}


// PREMIER PB A GERER EST PQ LA FONCTION ZOOM DEFONCAIS MON MOUSE_GET_POS ????? surement mlx_loop_hook

void	pgm_image_init(t_ptr *pgm, t_data *image)
{
	pgm->mlx = mlx_init();
	pgm->win = mlx_new_window(pgm->mlx, 1000, 1000, "hello");
	image->img = mlx_new_image(pgm->mlx, 1000, 1000);
	image->addr = mlx_get_data_addr(image->img, &image->bpp, &image->line_length, &image->endian);
	pgm->mouse.min_re = -2.0;
	pgm->mouse.min_cp = -1.2;
	pgm->mouse.max_cp = 1.2;
	pgm->mouse.max_re = (HT / WT * (pgm->mouse.max_cp - pgm->mouse.min_cp) + pgm->mouse.min_re);	
	pgm->k_cp = 0.596;
	pgm->k_re = 0.128;
	pgm->mouse.x = 0;
	pgm->mouse.y = 0;
	pgm->mouse.zoom = 1.0;
	pgm->col = 0;
	pgm->mv_x = 0;
	pgm->mv_y = 0;
}

//pour julia juste utiliser key_hook pas besoin davoir print avant dans le main


//int	ft_julia()

int	main(int ac, char **av)
{
	t_ptr	pgm;
	
	if (ac != 2)
		return (write(1, "Error\n", 6));
	pgm_image_init(&pgm, &pgm.image);
	//mlx_key_hook(pgm.win, deal_key, &pgm);
	
	if (!ft_strcmp(av[1], "julia"))
	{
		print_julia(&pgm);
		mlx_key_hook(pgm.win, &key_julia, &pgm);
		mlx_mouse_hook(pgm.win, &mouse_scroll, &pgm);
	}
	if (!ft_strcmp(av[1], "mandelbrot"))
	{
		print_mandelbrot(&pgm);
		mlx_key_hook(pgm.win, &key_mandel, &pgm);
		mlx_mouse_hook(pgm.win, &mouse_scroll_2, &pgm);
	}
	if (!ft_strcmp(av[1], "gustave"))
	{
		print_gustave(&pgm);
		mlx_key_hook(pgm.win, &key_gus, &pgm);
		mlx_mouse_hook(pgm.win, &mouse_scroll_3, &pgm);
	}
	//mlx_loop_hook(pgm.mlx, &print_mandelbrot, &pgm);
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