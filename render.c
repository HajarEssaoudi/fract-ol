/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hes-saou <hes-saou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 06:57:40 by hes-saou          #+#    #+#             */
/*   Updated: 2025/03/01 10:56:54 by hes-saou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#define MAX_ITER 100

static int	get_pink_shade(int i)
{
	int	colors[] = {0x9A8695, 0xC997A9, 0xDFC0BC, 0xF5EBCE};
	int	color_count;
	int	index;

	if (i == MAX_ITER)
		return (0xFDF2F6);
	color_count = sizeof(colors) / sizeof(colors[0]);
	index = (i * color_count) / MAX_ITER;
	return (colors[index % color_count]);
}

void	render_mandelbrot(t_data *data)
{
	// TODO: l'algorithme Mandelbrot
	printf("Affichage de Mandelbrot...\n");
}

void	render_julia(t_data *data)
{
	t_complex	z;
	int			color;
	double		tmp;
	int 		x, y, i;

	z.c_re = 0.285;
	z.c_im = 0;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			z.z_re = ((x - WIDTH / 2) / (0.5 * WIDTH) * data->zoom) + data->move_x;
			z.z_im = ((y - HEIGHT / 2) / (0.5 * HEIGHT) * data->zoom) + data->move_y;
			i = 0;
			while (z.z_re * z.z_re + z.z_im * z.z_im < 4 && i < MAX_ITER)
			{
				tmp = z.z_re * z.z_re - z.z_im * z.z_im + z.c_re;
				z.z_im  = 2.0 * z.z_re * z.z_im + z.c_im;
				z.z_re = tmp;
				i++;
			}
			color = get_pink_shade(i);
			my_mlx_pixel_put(data, x, y, color);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
}
