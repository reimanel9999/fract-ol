/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarvalh <mcarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 18:24:15 by mcarvalh          #+#    #+#             */
/*   Updated: 2025/01/09 18:50:35 by mcarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	mandel_calc(t_fractol *fractol)
{
	int		m;
	double	zx;
	double	zy;
	double	temp;

	zx = 0;
	zy = 0;
	m = 0;
	while (m < fractol->max_ite)
	{
		if ((zx * zx + zy * zy) > 4.0)
			break ;
		temp = 2 * zx * zy + fractol->cy;
		zx = zx * zx - zy * zy + fractol->cx;
		zy = temp;
		m++;
	}
	return (m);
}
