/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mandelbrot.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmary <gmary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 12:28:46 by gmary             #+#    #+#             */
/*   Updated: 2022/01/13 13:53:34 by gmary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

void	print_mandelbrot(t_data image, t_ptr pgm, double width, double height)
{
	(void)pgm;
	double	min_re = -2;
	double	max_re = 1;
	double	min_cp = -1.2;
	//il y a une version alternative pour ne pas avoir limage deformer de max_cp
	double	max_cp = 1.2;
	double	c_cp;
	double	c_re;
	double	y = 0;
	double	x;
	
	while (y < width)
	{
		c_cp = max_cp - (y *(max_cp - min_cp)/height);
		x = 0;
		while (x < height)
		{
			c_re = min_re + (x *(max_re - min_re)/width);
			my_mlx_pixel_put(&image, c_re, c_cp, create_color(0,255,0,0));
			//mlx_put_image_to_window(pgm.mlx, pgm.win, image.img, 0, 0);
			//calculate if appartient ou pas et print si appartient
			x++;
		}
		
		y++;
	}
}