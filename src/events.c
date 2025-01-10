/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarvalh <mcarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 18:52:33 by mcarvalh          #+#    #+#             */
/*   Updated: 2025/01/09 18:52:45 by mcarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

// void	mouse_handler()

// void	key_handler(mlx_key_data_t key_data, void *param)
// {
// 	t_fractol *fractol = (t_fractol *)param;

// 	if (key_data.key == ESC && key_data.action == MLX_PRESS)
// 	{
// 		mlx_close_window(fractol->mlx);
// 		exit_handler(fractol);
// 	}
// 	else if (key_data.action == MLX_PRESS || key_data.action == MLX_REPEAT)
// 	{
// 		if (key_data.key == LEFT)
// 			fractol->off_x -= 0.1 / fractol->zoom;
// 		else if (key_data.key == RIGHT)
// 			fractol->off_x += 0.1 / fractol->zoom;
// 		else if (key_data.key == UP)
// 			fractol->off_y -= 0.1 / fractol->zoom;
// 		else if (key_data.key == DOWN)
// 			fractol->off_y += 0.1 / fractol->zoom;

// 		draw_fractol(fractol); // Redraw fractal with updated offsets
// 	}
// }
