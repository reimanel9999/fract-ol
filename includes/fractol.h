/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarvalh <mcarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 11:06:24 by mcarvalh          #+#    #+#             */
/*   Updated: 2025/01/10 12:26:05 by mcarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "include/MLX42/MLX42.h"
#include "libft/libft.h"

// Dimensions
#define WIDTH 700
#define HEIGHT 600
#define MAX_ITE 60

// Fractol sets
# define MANDELBROT 1
# define JULIA 2

// Event handler keys + mouse
# define ESC 65307
# define UP 65362
# define DOWN 65364
# define LEFT 65361
# define RIGHT 65363
# define PLUS 61
# define MINUS 45

typedef struct s_fractol
{
	mlx_t		*mlx;
	mlx_image_t	*image;
//	void	*window;
// 	void	*image_ptr;
	int		set;
	double	cx;
	double	cy;
	double	min_i;
	double	max_i;
	double	min_r;
	double	max_r;
	int		colour;
	double	off_x;
	double	off_y;
	double	zoom;
	int		max_ite;
	int		error;
}	t_fractol;

//Initialize fractol
void	init_fractol(t_fractol *fractol);
void	init_mlx(t_fractol *fractol);
void	args_handler(t_fractol *fractol, int argc, char **argv);
void	map_complex(t_fractol *fractol);

//Rendering fractols
void	draw_fractol(t_fractol *fractol);
int	fractal_calc(t_fractol *fractol);
int	set_colour(t_fractol *fractol, int nbr_ite);

// Clean exit of fractols
void	exit_handler(void *param, int exit_code);
void	error_handler(t_fractol *fractol);
void	close_window(void *param);

// Events handler keys + mouse
void	key_handler(mlx_key_data_t key_data, void *param);

//Mandelbrot
int	mandel_calc(t_fractol *fractol);

//Julia
