/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmary <gmary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 13:21:13 by gmary             #+#    #+#             */
/*   Updated: 2022/01/24 14:24:18 by gmary            ###   ########.fr       */
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
# include <X11/keysym.h>
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
	double	scale_cp;
	double	scale_re;
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
	double	k_re;
	double	k_cp;
	int		col;
	double	mv_x;
	double	mv_y;
}				t_ptr;


int	mouse_scroll_3(int mouse, int x, int y, t_ptr *pgm);
int	key_gus(int key, t_ptr *pgm);
int	print_gustave(t_ptr *pgm);
int	key_mandel(int key, t_ptr *pgm);
int	mouse_scroll_2(int mouse, int x, int y, t_ptr *pgm);
int	ft_black(t_ptr *pgm);
void	ft_zoom_in(t_ptr	*pgm, double zoom_f);
int	create_color(int t, int r, int g, int b);
int	mouse_scroll(int mouse, int x, int y, t_ptr *pgm);
//int	print_mandelbrot(t_data image, t_ptr *pgm, double	width, double height);
//int	print_mandelbrot(t_data *image, t_ptr *pgm, double	width, double height);
int	palette(int i);
int	print_mandelbrot(t_ptr *pgm);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
int	print_julia(t_ptr *pgm);
int	key_julia(int key, t_ptr *pgm);

#endif