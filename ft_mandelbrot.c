/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mandelbrot.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmary <gmary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 12:28:46 by gmary             #+#    #+#             */
/*   Updated: 2022/01/18 15:36:13 by gmary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

int	check_if_belong(double c_re, double c_cp, int max)
{
	double	z_re;
	double	z_cp;
	double	temp;
	int		count;

	count = 0;
	z_re = c_re;
	z_cp = c_cp;
	while (count < max)
	{
		temp = z_re * z_re - z_cp * z_cp + c_re;
		z_cp = 2 * z_re * z_cp + c_cp;
		z_re = temp;
		if (((z_cp * z_cp) + (z_re * z_re)) > 4)
		{
			return (0);
		}
		count++;
	}
	return (1);
}

int	ft_black(t_ptr *pgm)
{
	int	x;
	int	y;

	y = 0;
	while (y < 1000)
	{
		x = 0;
		while (x < 1000)
		{
			my_mlx_pixel_put(&pgm->image, x, y, create_color(0, 0, 0, 0));
			x++;
		}
		y++;
	}
	return (0);
}

int	print_mandelbrot(t_ptr *pgm)
{
	//(void)pgm;
	ft_black(pgm);
	double	width = 1000;
	double height = 1000;
	double	min_re = -2;
	double	max_re = 1;
	double	min_cp = -1.2;
	//il y a une version alternative pour ne pas avoir limage deformer de max_cp
	double	max_cp = 1.2;
	//double	max_cp = min_cp + (max_re - min_re) * (1000 / 1000);
	double	c_cp;
	double	c_re;
	double	y;
	double	x;
	int n;
	int	col = 0;
	double	zoom = pgm->mouse.zoom;
	//double	zoom = 1.5;
	double	move_y = 0;
	double	move_x = -1;
//
	//move_y = pgm->mouse.y;
	//move_x = pgm->mouse.x;
		//printf("outside x = %d, y = %d, zoom = %f\n\n", pgm->mouse.x, pgm->mouse.y, pgm->mouse.zoom);
		//printf("outside x = %f, y = %f, zoom = %f\n\n", pgm->mouse.move_x, pgm->mouse.move_y, pgm->mouse.zoom);
		printf("outside x = %f, y = %f, zoom = %f\n\n", move_x, move_y, pgm->mouse.zoom);
	n = 2;
	// 29 ou 49 ??
	while (n < 35)
	{
		y = 0;
		while (y < width)
		{
	//	printf("inside x = %d, y = %d, zoom = %f\n", pgm->mouse.x, pgm->mouse.y, pgm->mouse.zoom);
			c_cp = max_cp - (y *(max_cp - min_cp)/(height * zoom)) + move_y;
			//c_cp = max_cp - (y *(max_cp - min_cp)/(height * zoom));
			x = 0;
			while (x < height)
			{
				//c_re = min_re + (x *(max_re - min_re)/(width * zoom));
				c_re = min_re + (x *(max_re - min_re)/(width * zoom)) + move_x;
				if (check_if_belong(c_re, c_cp, 1 + n))
					my_mlx_pixel_put(&pgm->image, x, y, create_color(0,32 + col, col, 20 + col));
					//my_mlx_pixel_put(image, x, y, create_color(0,32 + col, col, 20 + col));
				x++;
			}
			y++;
		}
		n++;
		col += 5;
	}
	mlx_put_image_to_window(pgm->mlx, pgm->win, pgm->image.img, 0, 0);
	return (0);
}
