/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmary <gmary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 09:20:55 by gmary             #+#    #+#             */
/*   Updated: 2022/01/14 13:22:18 by gmary            ###   ########.fr       */
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

int	mouse_scroll(int mouse, void *param)
{
	static int i = 0;
	(void)param;
	if (mouse == 4)
		printf("%d\n", i++);
	if (mouse == 5)
		printf("%d\n", i++);
	return (0);
}

int	close(t_ptr *pgm)
{
	mlx_destroy_window(pgm->mlx, pgm->win);
	return (0);
}

int	main()
{
	t_data	image;
	t_ptr	pgm;

	pgm.mlx = mlx_init();
	pgm.win = mlx_new_window(pgm.mlx, 1000, 1000, "hello");
	image.img = mlx_new_image(pgm.mlx, 1000, 1000);
	image.addr = mlx_get_data_addr(image.img, &image.bpp, &image.line_length, &image.endian);
	

	
	
	//integrer t r g b a la structure image et avant de faire ca utiliser le hook afin de definir les couleurs
	//mlx_key_hook(pgm.win, deal_key, &pgm);
	mlx_mouse_hook(pgm.win, mouse_scroll, &pgm);
	print_mandelbrot(image, pgm, 1000, 1000);
	
	
	

	
	mlx_put_image_to_window(pgm.mlx, pgm.win, image.img, 0, 0);
	//integrer la touhe esc pour quitter la fenetre
	mlx_hook(pgm.win,17, 02, close, &pgm);
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