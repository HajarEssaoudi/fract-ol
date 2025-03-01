/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hes-saou <hes-saou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 07:10:40 by hes-saou          #+#    #+#             */
/*   Updated: 2025/03/01 10:57:03 by hes-saou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	close_window(t_data *data)
{
	mlx_destroy_image(data->mlx, data->img);
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	exit(0);
	return (0);
}

int	key_hook(int keycode, t_data *data)
{
	if (keycode == ESC)
		close_window(data);
	return (0);
}

int	mouse_hook(int button, int x, int y, t_data *data)
{
	double	re_center;
	double	im_center;
	double zoom_factor = 1.2;

	re_center = (x - WIDTH / 2.0) / (0.5 * WIDTH) * data->zoom + data->move_x;
	im_center = (y - HEIGHT / 2.0) / (0.5 * HEIGHT) * data->zoom + data->move_y;
	if (button == 4)
	{
		data->zoom /= zoom_factor;
		data->move_x = re_center - (re_center - data->move_x) / zoom_factor;
		data->move_y = im_center - (im_center - data->move_y) / zoom_factor;
	}
	else if (button == 5)
	{
		data->zoom *= zoom_factor;
		data->move_x = re_center - (re_center - data->move_x) * zoom_factor;
		data->move_y = im_center - (im_center - data->move_y) * zoom_factor;
	}
	if (data->type == 0)
		render_julia(data);
	else
		render_mandelbrot(data);
	return (0);
}
