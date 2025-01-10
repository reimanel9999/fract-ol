/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarvalh <mcarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 16:11:23 by mcarvalh          #+#    #+#             */
/*   Updated: 2025/01/09 18:46:28 by mcarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	error_handler(t_fractol *fractol)
{
	ft_putendl_fd("************ERROR************", 1);
	ft_putendl_fd("Usage: ./fractol <fractol>", 1);
	ft_putendl_fd("Available fractols:", 1);
	ft_putendl_fd("\tmandel/mandelbrot", 1);
	ft_putendl_fd("\tjulia <param> <param> , param between -2 and 2", 1);
	exit_handler(fractol);
}

void	exit_handler(void *param)
{
	t_fractol *fractol;

	fractol = (t_fractol *)param;
	if (fractol)
	{
		if (fractol->image && fractol->mlx)
			mlx_delete_image(fractol->mlx, fractol->image);
		if (fractol->mlx)
			mlx_terminate(fractol->mlx);
		free(fractol);
	}
	exit(EXIT_SUCCESS);
}
