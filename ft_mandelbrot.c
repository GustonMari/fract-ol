/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mandelbrot.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmary <gmary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 12:28:46 by gmary             #+#    #+#             */
/*   Updated: 2022/01/24 11:43:14 by gmary            ###   ########.fr       */
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

int	check_if_julia(double c_re, double c_cp, int max, t_ptr *pgm)
{
	double	z_re;
	double	z_cp;
	double	temp;
	int		count;

	count = 0;
	z_re = c_re;
	z_cp = c_cp;
	c_re = pgm->k_re;
	c_cp = pgm->k_cp;
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

int	print_julia(t_ptr *pgm)
{
	double	min_re = pgm->mouse.min_re;
	double	min_cp = pgm->mouse.min_cp;
	double	max_cp = pgm->mouse.max_cp;
	double max_re = (HT / WT * (pgm->mouse.max_cp - pgm->mouse.min_cp) + pgm->mouse.min_re);	
	//marche mais deforme le zoom.	
	//double	max_cp = pgm->mouse.min_cp + (pgm->mouse.max_cp - pgm->mouse.min_re) * (1000 / 1000); 
	pgm->mouse.scale_re = (pgm->mouse.max_re - pgm->mouse.min_re) / HT;
	pgm->mouse.scale_cp = (pgm->mouse.max_cp - pgm->mouse.min_cp) / WT;	
	double	c_cp;
	double	c_re;
	double	y;
	double	x;
	int n;
	int	col = 0;
	ft_black(pgm);
	//double	zoom = pgm->mouse.zoom;
	//double move_y = 0;
	//double move_x = 0;
	n = 2;
	while (n < 35)
	{
		y = 0;
		while (y < WT)
		{
			//c_cp = max_cp - (y *(max_cp - min_cp)/(HT * pgm->mouse.zoom));
			c_cp = max_cp - (y *(max_cp - min_cp)/(HT));
			x = 0;
			while (x < HT)
			{
				//c_re = min_re + (x *(max_re - min_re)/(WT * pgm->mouse.zoom));
				c_re = min_re + (x *(max_re - min_re)/(WT)) + 0.8;
				//if (check_if_belong(c_re, c_cp, 1 + n))
				if (check_if_julia(c_re, c_cp, 1 + n, pgm))
					my_mlx_pixel_put(&pgm->image, x, y, palette(n + col));
					//my_mlx_pixel_put(&pgm->image, x, y, create_color(0,32 + col, col, 20 + col));
				x++;
			}
			y++;
		}
		n++;
		col += pgm->col;
	}
	mlx_put_image_to_window(pgm->mlx, pgm->win, pgm->image.img, 0, 0);
	return (0);
}

int	print_mandelbrot(t_ptr *pgm)
{
	double	min_re = pgm->mouse.min_re;
	double	min_cp = pgm->mouse.min_cp;
	double	max_cp = pgm->mouse.max_cp;
	double max_re = (HT / WT * (pgm->mouse.max_cp - pgm->mouse.min_cp) + pgm->mouse.min_re);	
	//marche mais deforme le zoom.	
	//double	max_cp = pgm->mouse.min_cp + (pgm->mouse.max_cp - pgm->mouse.min_re) * (1000 / 1000); 
	pgm->mouse.scale_re = (pgm->mouse.max_re - pgm->mouse.min_re) / HT;
	pgm->mouse.scale_cp = (pgm->mouse.max_cp - pgm->mouse.min_cp) / WT;	
	double	c_cp;
	double	c_re;
	double	y;
	double	x;
	int n;
	int	col = 0;
	ft_black(pgm);
	//double	zoom = pgm->mouse.zoom;
	//double move_y = 0;
	//double move_x = 0;
	n = 2;
	while (n < 35)
	{
		y = 0;
		while (y < WT)
		{
			//c_cp = max_cp - (y *(max_cp - min_cp)/(HT * pgm->mouse.zoom));
			c_cp = max_cp - (y *(max_cp - min_cp)/(HT));
			x = 0;
			while (x < HT)
			{
				//c_re = min_re + (x *(max_re - min_re)/(WT * pgm->mouse.zoom));
				c_re = min_re + (x *(max_re - min_re)/(WT));
				//if (check_if_belong(c_re, c_cp, 1 + n))
				//if (check_if_julia(c_re, c_cp, 1 + n))
				if (check_if_belong(c_re, c_cp, 1 + n))
					my_mlx_pixel_put(&pgm->image, x, y, palette(n + col));
					//my_mlx_pixel_put(&pgm->image, x, y, create_color(0,32 + col, col, 20 + col));
				x++;
			}
			y++;
		}
		n++;
		col += pgm->col;
	}
	mlx_put_image_to_window(pgm->mlx, pgm->win, pgm->image.img, 0, 0);
	return (0);
}