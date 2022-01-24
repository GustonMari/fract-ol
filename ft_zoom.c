/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_zoom.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmary <gmary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 14:26:53 by gmary             #+#    #+#             */
/*   Updated: 2022/01/24 14:31:36 by gmary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

int	mouse_scroll(int mouse, int x, int y, t_ptr *pgm)
{
	double	zoom;

	if (mouse == 4 || mouse == 5)
	{
		pgm->mouse.move_x = pgm->mouse.min_re + (x * pgm->mouse.scale_re);
		pgm->mouse.move_y = pgm->mouse.max_cp - (y * pgm->mouse.scale_cp);
		if (mouse == 5)
			zoom = 1.2;
		else
			zoom = 0.8;
		pgm->mouse.min_re = pgm->mouse.move_x + (pgm->mouse.min_re - pgm->mouse.move_x) * zoom;
		pgm->mouse.max_re = pgm->mouse.move_x + (pgm->mouse.max_re - pgm->mouse.move_x) * zoom;
		pgm->mouse.min_cp = pgm->mouse.move_y + (pgm->mouse.min_cp - pgm->mouse.move_y) * zoom;
		pgm->mouse.max_cp = pgm->mouse.move_y + (pgm->mouse.max_cp - pgm->mouse.move_y) * zoom;
		print_julia(pgm);
	}
	return (0);
}

int	mouse_scroll_2(int mouse, int x, int y, t_ptr *pgm)
{
	double	zoom;

	if (mouse == 4 || mouse == 5)
	{
		pgm->mouse.move_x = pgm->mouse.min_re + (x * pgm->mouse.scale_re);
		pgm->mouse.move_y = pgm->mouse.max_cp - (y * pgm->mouse.scale_cp);
		if (mouse == 5)
			zoom = 1.2;
		else
			zoom = 0.8;
		pgm->mouse.min_re = pgm->mouse.move_x + (pgm->mouse.min_re - pgm->mouse.move_x) * zoom;
		pgm->mouse.max_re = pgm->mouse.move_x + (pgm->mouse.max_re - pgm->mouse.move_x) * zoom;
		pgm->mouse.min_cp = pgm->mouse.move_y + (pgm->mouse.min_cp - pgm->mouse.move_y) * zoom;
		pgm->mouse.max_cp = pgm->mouse.move_y + (pgm->mouse.max_cp - pgm->mouse.move_y) * zoom;
		print_mandelbrot(pgm);
	}
	return (0);
}

int	mouse_scroll_3(int mouse, int x, int y, t_ptr *pgm)
{
	double	zoom;

	if (mouse == 4 || mouse == 5)
	{
		pgm->mouse.move_x = pgm->mouse.min_re + (x * pgm->mouse.scale_re);
		pgm->mouse.move_y = pgm->mouse.max_cp - (y * pgm->mouse.scale_cp);
		if (mouse == 5)
			zoom = 1.2;
		else
			zoom = 0.8;
		pgm->mouse.min_re = pgm->mouse.move_x + (pgm->mouse.min_re - pgm->mouse.move_x) * zoom;
		pgm->mouse.max_re = pgm->mouse.move_x + (pgm->mouse.max_re - pgm->mouse.move_x) * zoom;
		pgm->mouse.min_cp = pgm->mouse.move_y + (pgm->mouse.min_cp - pgm->mouse.move_y) * zoom;
		pgm->mouse.max_cp = pgm->mouse.move_y + (pgm->mouse.max_cp - pgm->mouse.move_y) * zoom;
		print_gustave(pgm);
	}
	return (0);
}

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
