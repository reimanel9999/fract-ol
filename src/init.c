/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarvalh <mcarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 14:07:54 by mcarvalh          #+#    #+#             */
/*   Updated: 2025/01/09 18:49:28 by mcarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_fractol(t_fractol *fractol)
{
	fractol->mlx = NULL;
	fractol->image = NULL;
	fractol->cx = 0;
	fractol->cy = 0;
	fractol->colour = 0xADD8E6;
	fractol->zoom = 300;
	fractol->off_x = 0;
	fractol->off_y = 0;
	fractol->max_ite = 60;
	fractol->min_r = 0;
	fractol->max_r = 0;
	fractol->max_i = 0;
	fractol->min_i = 0;
}

void	init_mlx(t_fractol *fractol)
{
	fractol->mlx = mlx_init(WIDTH, HEIGHT, "fract-ol", true);
	if (!fractol->mlx)
		error_handler(fractol);
	fractol->image = mlx_new_image(fractol->mlx, WIDTH, HEIGHT);
	if (!fractol->image)
		error_handler(fractol);	
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
	// julia_start_value();
}
