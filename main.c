/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmary <gmary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 09:20:55 by gmary             #+#    #+#             */
/*   Updated: 2022/01/12 18:36:08 by gmary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

int	deal_key(int key, void *param)
{
	//(void)key;
	(void)param;
	if (key == 37)
		printf("left\n");
	if (key == 38)
		printf("up\n");
	if (key == 39)
		printf("right\n");
	if (key == 40)
		printf("down\n");
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

int	main()
{
	void	*ptr;
	void	*win_ptr;
	t_data	image;
	t_ptr	pgm;

	ptr = mlx_init();
	win_ptr = mlx_new_window(ptr, 500, 500, "hello");
	pgm.mlx = ptr;
	pgm.win = win_ptr;
	
	image.img = mlx_new_image(ptr, 500, 500);
	//pq get_data_addr return un char ??
	image.addr = mlx_get_data_addr(image.img, &image.bpp, &image.line_length, &image.endian);

	my_mlx_pixel_put(&image, 20, 10, create_color(0,255,0,0));
	mlx_put_image_to_window(ptr, win_ptr, image.img, 0, 0);
	mlx_key_hook(win_ptr, deal_key, &pgm);
	
	mlx_loop(ptr);
	return (0);
}

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