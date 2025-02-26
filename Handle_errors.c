/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Handle_errors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hes-saou <hes-saou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 06:11:10 by hes-saou          #+#    #+#             */
/*   Updated: 2025/02/26 08:23:01 by hes-saou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	check_input(char *input)
{
	if (ft_strcmp(input, "mandelbrot") == 0 || ft_strcmp(input, "julia") == 0)
		return (1);
	return (0);
}
