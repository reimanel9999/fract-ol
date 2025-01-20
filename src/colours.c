/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colours.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manelcarvalho <manelcarvalho@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 23:15:46 by manelcarval       #+#    #+#             */
/*   Updated: 2025/01/20 00:29:25 by manelcarval      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	generate_palette(t_fractol *fractol)
{
	int	m;
	int	red;
	int	green;
	int	blue;

	m = 0;
	while (m < fractol->max_ite)
	{
		if (fractol->palette_idx == 0)
		{
            red = (m * 9) % 256;
            green = (m * 7) % 256;
            blue = (m * 13) % 256;
        }
        else if (fractol->palette_idx == 1)
        {
            red = 0;
            green = (m * 12) % 256;
            blue = (m * 18) % 256;
        }
        else if (fractol->palette_idx == 2)
        {
            red = (m * 15) % 256;
            green = (m * 6) % 256;
            blue = 0;
        }
		fractol->palette[m] = (red << 24 | green << 16 | blue << 8 | 0xFF);
        m++;
	}
}
