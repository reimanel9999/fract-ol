/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarvalh <mcarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 16:11:23 by mcarvalh          #+#    #+#             */
/*   Updated: 2025/01/10 11:43:39 by mcarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	close_window(void *param)
{
	t_fractol *fractol;

	fractol = (t_fractol *)param;
	exit_handler(fractol, EXIT_SUCCESS);
}

void	error_handler(t_fractol *fractol)
{
	ft_putendl_fd("************ERROR************", 1);
	ft_putendl_fd("Usage: ./fractol <fractol>", 1);
	ft_putendl_fd("Available fractols:", 1);
	ft_putendl_fd("\tmandel/mandelbrot", 1);
	ft_putendl_fd("\tjulia <param> <param> , param between -2 and 2", 1);
	// fractol->error = EXIT_FAILURE;
	// mlx_close_window(fractol->mlx);
	// puts(mlx_strerror(mlx_errno));
	exit_handler(fractol, EXIT_FAILURE);
}

void	exit_handler(void *param, int exit_code)
{
	t_fractol *fractol;

	fractol = (t_fractol *)param;
	if (fractol)
	{
		if (fractol->image && fractol->mlx)
			mlx_delete_image(fractol->mlx, fractol->image);
		if (fractol->mlx)
		{
			mlx_close_window(fractol->mlx);
			mlx_terminate(fractol->mlx);
		}
		free(fractol);
	}
	exit(exit_code);
}
