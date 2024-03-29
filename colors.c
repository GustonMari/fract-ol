/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmary <gmary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 11:38:10 by gmary             #+#    #+#             */
/*   Updated: 2022/01/24 16:33:57 by gmary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

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

/* 0xTTRRGGBB, 0x00FF0000 => red equivaut a (0,255,0,0), 0xFFFFFF => white */
int	create_color(int t, int r, int g, int b)
{
	int	colors;

	colors = 0;
	colors |= b;
	colors |= g << 8;
	colors |= r << 16;
	colors |= t << 24;
	return (colors);
}

int	palette(int i)
{
	const int	tab[27] = {0xfaf3dd, 0xc8d5b9, 0x8fc0a9, 0x68b0ab, 0x4a7c59,
		0x454851, 0x73956f, 0x7bae7f, 0x95d7ae, 0xfceff9, 0x313628, 0x73956f,
		0x595358, 0x22aed1, 0xeeeeff, 0xff0000, 0xff8000, 0xffff00, 0x80ff00,
		0x00ff00, 0x00ff80, 0x00ffff, 0x0080ff, 0x0000ff, 0x8000ff, 0xff00ff,
		0xff0080};

	i = i % 27;
	return (tab[i]);
}
