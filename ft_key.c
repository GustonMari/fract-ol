/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmary <gmary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 14:33:29 by gmary             #+#    #+#             */
/*   Updated: 2022/01/24 15:21:04 by gmary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

int	key_julia(int key, t_ptr *pgm)
{
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
	print_julia(pgm);
	return (0);
}

int	key_mandel(int key, t_ptr *pgm)
{
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
	print_mandelbrot(pgm);
	return (0);
}

int	key_gus(int key, t_ptr *pgm)
{
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
	print_gustave(pgm);
	return (0);
}

int key_esc(int key, t_ptr *pgm)
{
	//if (key == XK_Escape)
}