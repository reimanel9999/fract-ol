/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manelcarvalho <manelcarvalho@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 14:07:54 by mcarvalh          #+#    #+#             */
/*   Updated: 2025/01/20 00:48:36 by manelcarval      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_fractol(t_fractol *fractol)
{
	fractol->cx = 0.0;
	fractol->cy = 0.0;
	fractol->set = 0;
	fractol->colour = 0xADD8E6;
	fractol->zoom = 300;
	fractol->off_x = 0.0;
	fractol->off_y = 0.0;
	fractol->max_ite = 100;
	fractol->min_r = 0.0;
	fractol->max_r = 0.0;
	fractol->max_i = 0.0;
	fractol->min_i = 0.0;
	fractol->error = 0;
	fractol->palette = 0;
	fractol->palette_idx = 0;
}

void	init_mlx(t_fractol *fractol)
{
	fractol->mlx = mlx_init(WIDTH, HEIGHT, "fract-ol", true);
	if (!fractol->mlx)
		error_handler(fractol);
	fractol->image = mlx_new_image(fractol->mlx, WIDTH, HEIGHT);
	if (!fractol->image || !fractol->image->pixels)
		error_handler(fractol);
	fractol->palette = malloc(sizeof(uint32_t) * fractol->max_ite);
    if (!fractol->palette)
		error_handler(fractol);
    generate_palette(fractol);
	map_complex(fractol);
}

void	map_complex(t_fractol *fractol)
{
	if (fractol->set == MANDELBROT || fractol->set == JULIA)
	{
		fractol->min_r = -2.0;
		fractol->max_r = 1.0;
		fractol->max_i = -1.5;
		fractol->min_i = fractol->max_i + (fractol->max_r - fractol->min_r) * HEIGHT / WIDTH;
	}
}

void	args_handler(t_fractol *fractol, int argc, char **argv)
{
	if (ft_strcmp(argv[1], "mandelbrot") == 0 ||\
	ft_strcmp(argv[1], "mandel") == 0)
		fractol->set = MANDELBROT;
	else if (ft_strcmp(argv[1], "julia") == 0)
		fractol->set = JULIA;
	else
		error_handler(fractol);
	if (fractol->set != JULIA && argc > 2)
		error_handler(fractol);
	else if (fractol->set == JULIA && (argc > 4 || argc == 3))
		error_handler(fractol);
	if (fractol->set == JULIA)
		julia_start_value(fractol, argc, argv);
}

void	julia_start_value(t_fractol *fractol, int argc, char **argv)
{
	if (argc < 5 && argc != 3)
	{
		fractol->j_cr = ft_atof(argv[2]);
		if (fractol->j_ci == -42 || fractol->j_ci > 2.0 || fractol->j_ci < -2.0)
			error_handler(fractol);
		fractol->j_ci = ft_atof(argv[3]);
		if (fractol->j_cr == -42 || fractol->j_ci > 2.0 || fractol->j_ci < -2.0)
			error_handler(fractol);
	}
	else
	{
		fractol->j_ci = -0.090000;
		fractol->j_cr = -0.766667;
	}
}