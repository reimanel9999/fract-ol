/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manelcarvalho <manelcarvalho@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 18:52:33 by mcarvalh          #+#    #+#             */
/*   Updated: 2025/01/20 00:19:44 by manelcarval      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

// void	mouse_handler()

// void	move(mlx_key_data_t key_data, t_fractol fractol)
// {
// 	int 
// }

void	key_handler(mlx_key_data_t key_data, void *param)
{
	t_fractol *fractol = (t_fractol *)param;

	if (key_data.key == ESC && key_data.action == MLX_PRESS)
		exit_handler(fractol, EXIT_SUCCESS);
	else if ((key_data.key == LEFT || key_data.key == MLX_KEY_LEFT) && key_data.action == MLX_PRESS)
		move('L', 0.1, fractol);
	else if ((key_data.key == RIGHT || key_data.key == MLX_KEY_RIGHT) && key_data.action == MLX_PRESS)
		move('R', 0.1, fractol);
	else if ((key_data.key == UP || key_data.key == MLX_KEY_UP) && key_data.action == MLX_PRESS)
		move('U', 0.1, fractol);
	else if ((key_data.key == DOWN || key_data.key == MLX_KEY_DOWN) && key_data.action == MLX_PRESS)
		move('D', 0.1, fractol);
	else if (key_data.key == MLX_KEY_SPACE && key_data.action == MLX_PRESS)
	{
		fractol->palette_idx = (fractol->palette_idx + 1) % 3;
		generate_palette(fractol);	
	}
	else 
		return ;
	draw_fractol(fractol);
}

void	move(char direction, double distance, t_fractol *fractol)
{
	double	range_r;
	double	range_i;

	range_r = fractol->max_r - fractol->min_r;
	range_i = fractol->max_i - fractol->min_i;
	if (direction == 'L')
	{
		fractol->min_r -= distance * range_r;
		fractol->max_r -= distance * range_r;
	}
	else if (direction == 'R')
	{
		fractol->min_r += distance * range_r;
		fractol->max_r += distance * range_r;
	}
	else if (direction == 'U')
	{
		fractol->min_i += distance * range_i;
		fractol->max_i += distance * range_i;
	}
	else if (direction == 'D')
	{
		fractol->min_i -= distance * range_i;
		fractol->max_i -= distance * range_i;
	}
}
