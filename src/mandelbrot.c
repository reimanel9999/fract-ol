/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manelcarvalho <manelcarvalho@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 18:24:15 by mcarvalh          #+#    #+#             */
/*   Updated: 2025/01/17 17:13:32 by manelcarval      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	mandelbrot(t_fractol *fractol)
{
	int		ite;
	double	zx;
	double	zy;
	double	temp;

	zx = 0;
	zy = 0;
	ite = 0;
	while (ite < fractol->max_ite)
	{
		if ((zx * zx + zy * zy) > 4.0)
			break ;
		temp = 2 * zx * zy + fractol->cy;
		zx = zx * zx - zy * zy + fractol->cx;
		zy = temp;
		ite++;
	}
	return (ite);
}
