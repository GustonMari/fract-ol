/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmary <gmary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 13:21:13 by gmary             #+#    #+#             */
/*   Updated: 2022/01/19 11:43:13 by gmary            ###   ########.fr       */
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
# define HT 1000
# define WT 1000

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
	double	move_x;
	double	move_y;
	double	min_re;
	double	max_re;
	double	min_cp;
	double	max_cp;
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


void	ft_zoom_in(t_ptr	*pgm, double zoom_f);
int	create_color(int t, int r, int g, int b);
//int	print_mandelbrot(t_data image, t_ptr *pgm, double	width, double height);
//int	print_mandelbrot(t_data *image, t_ptr *pgm, double	width, double height);
int	print_mandelbrot(t_ptr *pgm);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);

#endif