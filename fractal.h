/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmary <gmary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 13:21:13 by gmary             #+#    #+#             */
/*   Updated: 2022/01/18 11:29:24 by gmary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTAL_H
# define FRACTAL_H

//for mac_os
//# include "minilibx/mlx.h"
# include "minilibx_linux/mlx.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct	s_save
{
	void	*img;
	char	*addr;
}				t_save;

typedef struct	s_mouse
{
	int	x;
	int	y;
	double	zoom;
	void	*img;
	char	*addr;
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
/*
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
*/

typedef struct	s_ptr
{
	void	*mlx;
	void	*win;

	//t_save	save;
	//t_data	*imge;
	t_data	image;
	t_mouse	mouse;
}				t_ptr;


void	ft_zoom(t_ptr	pgm);
int	create_color(int t, int r, int g, int b);
//int	print_mandelbrot(t_data image, t_ptr *pgm, double	width, double height);
//int	print_mandelbrot(t_data *image, t_ptr *pgm, double	width, double height);
int	print_mandelbrot(t_ptr *pgm);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);

#endif