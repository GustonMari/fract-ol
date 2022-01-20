/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_zoom.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmary <gmary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 14:26:53 by gmary             #+#    #+#             */
/*   Updated: 2022/01/20 11:41:03 by gmary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

double	inter(double start, double end, double zoom)
{
	return (start + ((end - start) * zoom));
}

void	ft_zoom_in(t_ptr	*pgm, double zoom_f)
{
	ft_black(pgm);
	double	zoom = 1.0 / zoom_f;
	pgm->mouse.min_re = inter(pgm->mouse.move_x, pgm->mouse.min_re, zoom);
	pgm->mouse.min_cp = inter(pgm->mouse.move_y, pgm->mouse.min_cp, zoom);
	pgm->mouse.max_re = inter(pgm->mouse.move_x, pgm->mouse.max_re, zoom);
	pgm->mouse.max_cp = inter(pgm->mouse.move_y, pgm->mouse.max_cp, zoom);
	//faire un if de securite pour proteger si on essaie de zoomer dans le sens inf a 1 
	//changer move seulment si zoom activer
}

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
		print_mandelbrot(pgm);
	}
	return (0);
}