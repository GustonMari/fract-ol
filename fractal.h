/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmary <gmary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 13:21:13 by gmary             #+#    #+#             */
/*   Updated: 2022/01/14 14:57:27 by gmary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTAL_H
# define FRACTAL_H

//for mac_os
//# include "minilibx/mlx.h"
# include "minilibx_linux/mlx.h"
# include <stdio.h>


typedef struct	s_mouse
{
	int	*x;
	int	*y;
}				t_mouse;


typedef struct	s_data 
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_length;
	int		endian;
	int		width;
	int		height;
}				t_data;

typedef struct	s_ptr
{
	void	*mlx;
	void	*win;
	t_mouse	*mouse;
}				t_ptr;

int	create_color(int t, int r, int g, int b);
int	print_mandelbrot(t_data image, t_ptr pgm, double	width, double height);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);

#endif