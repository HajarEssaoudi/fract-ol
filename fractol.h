/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hes-saou <hes-saou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 23:26:34 by hes-saou          #+#    #+#             */
/*   Updated: 2025/03/01 10:00:32 by hes-saou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include "/usr/include/minilibx-linux/mlx.h"
# define WIDTH 1920
# define HEIGHT 1080
# define TITLE "fractol"
# define ESC 65307
# include "ft_printf/ft_printf.h"
# include "libft/libft.h"
# include <math.h>
# include <stdio.h>
# include <stdlib.h>

// a struct for complex number, with real and imaginary parts.
typedef struct complex
{
	double	z_re;
	double	z_im;
	double	c_re;
	double	c_im;
}			t_complex;

// a struct for graphical data
typedef struct s_data
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
	double	zoom;
	double	move_x;
	double	move_y;
	double	c_re;
	double	c_im;
	int		type;
}			t_data;

// check input
int			check_input(char *input);

// redring
void		my_mlx_pixel_put(t_data *data, int x, int y, int color);
void		render_mandelbrot(t_data *data);
void		render_julia(t_data *data);

// events
int			close_window(t_data *data);
int			key_hook(int keycode, t_data *data);
int			mouse_hook(int button, int x, int y, t_data *data);
#endif