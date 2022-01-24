/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_julia.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmary <gmary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 16:58:26 by gmary             #+#    #+#             */
/*   Updated: 2022/01/24 17:49:07 by gmary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

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

void	ft_julia(t_ptr *pgm, int n, int col)
{
	double	c_cp;
	double	c_re;
	double	y;
	double	x;

	while (n < 35)
	{
		y = -1;
		while (++y < WT)
		{
			c_cp = pgm->mse.max_cp
				- (y *(pgm->mse.max_cp - pgm->mse.min_cp) / (HT)) + pgm->mv_y;
			x = -1;
			while (++x < HT)
			{
				c_re = (x *(pgm->mse.max_re - pgm->mse.min_re) / (WT))
					+ pgm->mse.min_re + 0.8 + pgm->mv_x;
				if (check_if_julia(c_re, c_cp, 1 + n, pgm))
					my_mlx_pixel_put(&pgm->image, x, y, palette(n + col));
			}
		}
		n++;
		col += pgm->col;
	}
	mlx_put_image_to_window(pgm->mlx, pgm->win, pgm->image.img, 0, 0);
}

int	print_julia(t_ptr *pgm, int n, int col)
{
	pgm->mse.max_re = (HT / WT * (pgm->mse.max_cp - pgm->mse.min_cp)
			+ pgm->mse.min_re);
	pgm->mse.scale_re = (pgm->mse.max_re - pgm->mse.min_re) / HT;
	pgm->mse.scale_cp = (pgm->mse.max_cp - pgm->mse.min_cp) / WT;
	ft_black(pgm);
	ft_julia(pgm, n, col);
	return (0);
}
