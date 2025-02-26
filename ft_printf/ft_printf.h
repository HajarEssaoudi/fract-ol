/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+        
	+:+     */
/*   By: hes-saou <hes-saou@student.42.fr>          +#+  +:+      
	+#+        */
/*                                                +#+#+#+#+#+  
	+#+           */
/*   Created: 2024/11/24 00:09:49 by hes-saou          #+#    #+#             */
/*   Updated: 2024/11/24 00:09:49 by hes-saou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int	ft_printf(const char *str, ...);
int	check_type(char c, va_list args);
int	ft_putchar(int c);
int	ft_putnbr(int nbr);
int	ft_putunbr(unsigned int nbr);
int	ft_putstr(char *s);
int	ft_puthex(char c, unsigned int nbr);
int	ft_putptr_hex(unsigned long n);
int	ft_putptr(void *ptr);
#endif