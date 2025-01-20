/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manelcarvalho <manelcarvalho@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 14:15:13 by mcarvalh          #+#    #+#             */
/*   Updated: 2025/01/19 22:27:55 by manelcarval      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int argc, char **argv)
{
	t_fractol	*fractol;

	fractol = ft_calloc(1, sizeof(t_fractol));
	if (argc < 2 || !argv[1])
		error_handler(fractol);
	init_fractol(fractol);
	args_handler(fractol, argc, argv);
	init_mlx(fractol);
	if (fractol->error == 0)
		draw_fractol(fractol);
	mlx_key_hook(fractol->mlx, key_handler, fractol);
	// mlx_scroll_hook();
	// mlx_mouse_hook();
	// mlx_hook();
	mlx_close_hook(fractol->mlx, close_window, fractol);
	mlx_loop(fractol->mlx);
	return (0);
}

// // Callback function to terminate the program when the window is closed
// void close_program(mlx_t *mlx)
// {
//     printf("Exiting program.\n");
//     mlx_terminate(mlx); // Clean up and free MLX resources
//     exit(EXIT_SUCCESS);
// }

// int main(void)
// {
//     // Initialize MLX42 and create a window (800x600 resolution)
//     mlx_t *mlx = mlx_init(800, 600, "MLX42 Window", true);
//     if (!mlx)
//     {
//         fprintf(stderr, "MLX initialization failed\n");
//         return EXIT_FAILURE;
//     }

//     // Hook a function to close the program on window close
//     mlx_close_hook(mlx, (void *)close_program, mlx);

//     // Start the MLX42 main loop (keeps the window open)
//     mlx_loop(mlx);

//     // Terminate MLX42 (this won't be reached unless the loop breaks)
//     mlx_terminate(mlx);
//     return EXIT_SUCCESS;
// }