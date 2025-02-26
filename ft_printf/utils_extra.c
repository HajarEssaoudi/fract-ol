/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_extra.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hes-saou <hes-saou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 23:06:18 by hes-saou          #+#    #+#             */
/*   Updated: 2024/11/28 18:58:36 by hes-saou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex(char c, unsigned int n)
{
	char	*base_small;
	char	*base_upp;
	int		count;

	count = 0;
	base_small = "0123456789abcdef";
	base_upp = "0123456789ABCDEF";
	if (n >= 16)
		count += ft_puthex(c, n / 16);
	if (c == 'x')
		count += ft_putchar(base_small[n % 16]);
	else if (c == 'X')
		count += ft_putchar(base_upp[n % 16]);
	return (count);
}

int	ft_putptr_hex(unsigned long n)
{
	char	*base;
	int		count;

	count = 0;
	base = "0123456789abcdef";
	if (n >= 16)
		count += ft_putptr_hex(n / 16);
	count += ft_putchar(base[n % 16]);
	return (count);
}

int	ft_putptr(void *ptr)
{
	int	count;

	count = 0;
	if (!ptr)
		return (ft_putstr("(nil)"));
	count += ft_putstr("0x");
	count += ft_putptr_hex((unsigned long)ptr);
	return (count);
}
