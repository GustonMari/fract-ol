/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmary <gmary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 09:20:55 by gmary             #+#    #+#             */
/*   Updated: 2022/01/24 18:26:02 by gmary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bpp / 8));
	*(unsigned int *)dst = color;
}

void	pgm_image_init(t_ptr *pgm, t_data *image)
{
	pgm->mlx = mlx_init();
	pgm->win = mlx_new_window(pgm->mlx, 1000, 1000, "hello");
	pgm->image.img = mlx_new_image(pgm->mlx, 1000, 1000);
	pgm->image.addr = mlx_get_data_addr(image->img,
			&image->bpp, &image->line_length, &image->endian);
	pgm->mse.min_re = -2.0;
	pgm->mse.min_cp = -1.2;
	pgm->mse.max_cp = 1.2;
	pgm->mse.max_re = (HT / WT
			* (pgm->mse.max_cp - pgm->mse.min_cp) + pgm->mse.min_re);
	pgm->k_cp = 0.596;
	pgm->k_re = 0.128;
	pgm->mse.x = 0;
	pgm->mse.y = 0;
	pgm->mse.zoom = 1.0;
	pgm->col = 0;
	pgm->mv_x = 0;
	pgm->mv_y = 0;
}

int	ft_check(int ac, char **av)
{
	int	nothing;

	nothing = 0;
	if (ac != 2 || (ft_strcmp(av[1], "julia")
			&& ft_strcmp(av[1], "mandelbrot")
			&& ft_strcmp(av[1], "gustave")))
	{
		nothing = write(1, "Error choose:\njulia\nmandelbrot\ngustave\n", 39);
		exit(0);
	}
	return (nothing);
}

int	main(int ac, char **av)
{
	t_ptr	pgm;

	ft_check(ac, av);
	pgm_image_init(&pgm, &pgm.image);
	if (!ft_strcmp(av[1], "julia"))
	{
		print_julia(&pgm, 2, 0);
		mlx_key_hook(pgm.win, &key_julia, &pgm);
		mlx_mouse_hook(pgm.win, &mouse_scroll, &pgm);
	}
	if (!ft_strcmp(av[1], "mandelbrot"))
	{
		print_mandelbrot(&pgm, 2, 0);
		mlx_key_hook(pgm.win, &key_mandel, &pgm);
		mlx_mouse_hook(pgm.win, &mouse_scroll_2, &pgm);
	}
	if (!ft_strcmp(av[1], "gustave"))
	{
		print_gustave(&pgm, 2, 0);
		mlx_key_hook(pgm.win, &key_gus, &pgm);
		mlx_mouse_hook(pgm.win, &mouse_scroll_3, &pgm);
	}
	mlx_hook(pgm.win, 17, 02, ft_close, &pgm);
	mlx_loop(pgm.mlx);
	return (0);
}
