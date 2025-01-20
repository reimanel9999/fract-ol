/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manelcarvalho <manelcarvalho@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 14:09:56 by mcarvalh          #+#    #+#             */
/*   Updated: 2025/01/20 00:49:13 by manelcarval      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	set_colour(t_fractol *fractol, int nbr_ite)
{
	// int m;

	// m = 5;
	if (nbr_ite == fractol->max_ite)
		return (0x000000FF);
	return (fractol->palette[nbr_ite]);
	
    // if (nbr_ite == fractol->max_ite)
    //     return 0x000000FF; // A fixed color for max iterations

    // // Normalize nbr_ite to ensure consistent mapping
    // double t = (double)nbr_ite / fractol->max_ite;

    // int red = (int)(9 * (1 - t) * t * t * t * 255);    // Smooth color transition
    // int green = (int)(15 * (1 - t) * (1 - t) * t * t * 255);
    // int blue = (int)(8.5 * (1 - t) * (1 - t) * (1 - t) * t * 255);

    // return (red << 24 | green << 16 | blue << 8 | 0xFF);
}

int	fractal_calc(t_fractol *fractol)
{
	int	nbr_ite;

	nbr_ite = 0;
	if (fractol->set == MANDELBROT)
		nbr_ite = mandelbrot(fractol);
	// else if (fractol->set == JULIA)
	// 	nbr_ite = julia_calc(fractol);
	return (nbr_ite);
}

void	draw_fractol(t_fractol *fractol)
{
	uint32_t	*pixels;
	double		x;
	double		y;
	int			nbr_ite;

	nbr_ite = 0;
	pixels = (uint32_t *)fractol->image->pixels;
	ft_memset(pixels, 0, sizeof(u_int32_t));
	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
		{
			fractol->cx = fractol->min_r + x * (fractol->max_r - fractol->min_r) / WIDTH;
			fractol->cy = fractol->max_i + y * (fractol->min_i - fractol->max_i) / HEIGHT;
			nbr_ite = fractal_calc(fractol);
			pixels[(int)y * WIDTH + (int)x] = set_colour(fractol, nbr_ite);
			// mlx_put_pixel(fractol->image, x, y, set_colour(fractol, nbr_ite));
		}
	}
	mlx_image_to_window(fractol->mlx, fractol->image, 0, 0);
}

