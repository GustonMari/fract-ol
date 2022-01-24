/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmary <gmary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 14:33:29 by gmary             #+#    #+#             */
/*   Updated: 2022/01/24 18:25:30 by gmary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

int	ft_close(t_ptr *pgm)
{
	mlx_destroy_image(pgm->mlx, pgm->image.img);
	mlx_destroy_window(pgm->mlx, pgm->win);
	mlx_destroy_display(pgm->mlx);
	free(pgm->mlx);
	exit(0);
}

void	key_main(int key, t_ptr *pgm)
{
	if (key == XK_Escape)
		ft_close(pgm);
	if (key == XK_w)
	{
		pgm->k_cp += 0.005;
		pgm->k_re += 0.010;
	}
	if (key == XK_s)
	{
		pgm->k_cp += 0.008;
		pgm->k_re += 0.013;
	}
	if (key == XK_a)
		pgm->col += 5;
	if (key == XK_d)
		pgm->col += 10;
	if (key == XK_Left)
		pgm->mv_x -= 0.2;
	if (key == XK_Right)
		pgm->mv_x += 0.2;
	if (key == XK_Up)
		pgm->mv_y += 0.2;
	if (key == XK_Down)
		pgm->mv_y -= 0.2;
}

int	key_julia(int key, t_ptr *pgm)
{
	key_main(key, pgm);
	print_julia(pgm, 2, 0);
	return (0);
}

int	key_mandel(int key, t_ptr *pgm)
{
	key_main(key, pgm);
	print_mandelbrot(pgm, 2, 0);
	return (0);
}

int	key_gus(int key, t_ptr *pgm)
{
	key_main(key, pgm);
	print_gustave(pgm, 2, 0);
	return (0);
}
