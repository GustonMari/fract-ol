/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmary <gmary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 13:21:13 by gmary             #+#    #+#             */
/*   Updated: 2022/01/13 10:20:01 by gmary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTAL_H
# define FRACTAL_H

//for mac_os
//# include "minilibx/mlx.h"
# include "minilibx_linux/mlx.h"
# include <stdio.h>

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bpp;
	int		line_length;
	int		endian;
}				t_data;

typedef struct	s_ptr
{
	void	*mlx;
	void	*win;
}				t_ptr;

#endif