/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_zoom.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmary <gmary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 14:26:53 by gmary             #+#    #+#             */
/*   Updated: 2022/01/24 14:49:05 by gmary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

int	mouse_scroll(int mse, int x, int y, t_ptr *pgm)
{
	double	z;

	if (mse == 4 || mse == 5)
	{
		pgm->mse.mvx = pgm->mse.min_re + (x * pgm->mse.scale_re);
		pgm->mse.mvy = pgm->mse.max_cp - (y * pgm->mse.scale_cp);
		if (mse == 5)
			z = 1.2;
		else
			z = 0.8;
		pgm->mse.min_re = pgm->mse.mvx + (pgm->mse.min_re - pgm->mse.mvx) * z;
		pgm->mse.max_re = pgm->mse.mvx + (pgm->mse.max_re - pgm->mse.mvx) * z;
		pgm->mse.min_cp = pgm->mse.mvy + (pgm->mse.min_cp - pgm->mse.mvy) * z;
		pgm->mse.max_cp = pgm->mse.mvy + (pgm->mse.max_cp - pgm->mse.mvy) * z;
		print_julia(pgm);
	}
	return (0);
}

int	mouse_scroll_2(int mse, int x, int y, t_ptr *pgm)
{
	double	z;

	if (mse == 4 || mse == 5)
	{
		pgm->mse.mvx = pgm->mse.min_re + (x * pgm->mse.scale_re);
		pgm->mse.mvy = pgm->mse.max_cp - (y * pgm->mse.scale_cp);
		if (mse == 5)
			z = 1.2;
		else
			z = 0.8;
		pgm->mse.min_re = pgm->mse.mvx + (pgm->mse.min_re - pgm->mse.mvx) * z;
		pgm->mse.max_re = pgm->mse.mvx + (pgm->mse.max_re - pgm->mse.mvx) * z;
		pgm->mse.min_cp = pgm->mse.mvy + (pgm->mse.min_cp - pgm->mse.mvy) * z;
		pgm->mse.max_cp = pgm->mse.mvy + (pgm->mse.max_cp - pgm->mse.mvy) * z;
		print_mandelbrot(pgm);
	}
	return (0);
}

int	mouse_scroll_3(int mse, int x, int y, t_ptr *pgm)
{
	double	z;

	if (mse == 4 || mse == 5)
	{
		pgm->mse.mvx = pgm->mse.min_re + (x * pgm->mse.scale_re);
		pgm->mse.mvy = pgm->mse.max_cp - (y * pgm->mse.scale_cp);
		if (mse == 5)
			z = 1.2;
		else
			z = 0.8;
		pgm->mse.min_re = pgm->mse.mvx + (pgm->mse.min_re - pgm->mse.mvx) * z;
		pgm->mse.max_re = pgm->mse.mvx + (pgm->mse.max_re - pgm->mse.mvx) * z;
		pgm->mse.min_cp = pgm->mse.mvy + (pgm->mse.min_cp - pgm->mse.mvy) * z;
		pgm->mse.max_cp = pgm->mse.mvy + (pgm->mse.max_cp - pgm->mse.mvy) * z;
		print_gustave(pgm);
	}
	return (0);
}
