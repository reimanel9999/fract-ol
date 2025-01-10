/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarvalh <mcarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 14:09:56 by mcarvalh          #+#    #+#             */
/*   Updated: 2025/01/10 12:26:08 by mcarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	set_colour(t_fractol *fractol, int nbr_ite)
{
	if (nbr_ite == fractol->max_ite)
		return (0x000000FF);
	int red = (nbr_ite * 9) % 256;
	int green = (nbr_ite * 7) % 256;
	int blue = (nbr_ite * 13) % 256;
	return (red << 24 | green << 16 | blue << 8 | 0xFF);
}

int	fractal_calc(t_fractol *fractol)
{
	int	nbr_ite;

	if (fractol->set == MANDELBROT)
		nbr_ite = mandel_calc(fractol);
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

	pixels = (uint32_t *)fractol->image->pixels;
	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			fractol->cx = fractol->min_r + fractol->off_x + x * (fractol->max_r - fractol->min_r) / WIDTH;
			fractol->cy = fractol->max_i + fractol->off_y +y * (fractol->min_i - fractol->max_i) / HEIGHT;
			nbr_ite = fractal_calc(fractol);
			pixels[(int)y * WIDTH + (int)x] = set_colour(fractol, nbr_ite);
			x++;
		}
		y++;
	}
	mlx_image_to_window(fractol->mlx, fractol->image, 0, 0);
}

