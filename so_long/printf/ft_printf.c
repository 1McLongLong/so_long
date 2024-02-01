/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touahman <touahman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 18:34:26 by touahman          #+#    #+#             */
/*   Updated: 2024/01/27 15:18:14 by touahman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	print(const char format, va_list eve, int *count)
{
	if (format == 'c')
		ft_putchar(va_arg(eve, int), count);
	else if (format == 's')
		ft_putstr(va_arg(eve, char *), count);
	else if (format == 'd' || format == 'i')
		ft_putnbr(va_arg(eve, int), count);
	else if (format == 'x')
		ft_put_hex(va_arg(eve, unsigned int), count);
	else if (format == 'X')
		ft_put_bighex(va_arg(eve, unsigned int), count);
	else if (format == 'u')
		ft_putnbr_u(va_arg(eve, unsigned int), count);
	else if (format == 'p')
		ft_print_add(va_arg(eve, void *), count);
	else
		ft_putchar(format, count);
}

int	ft_printf(const char *format, ...)
{
	int		count;
	va_list	eve;

	va_start(eve, format);
	count = 0;
	while (*format != '\0')
	{
		if (*format == '%')
		{
			if (*(format + 1) == '\0')
				break ;
			print(*(format + 1), eve, &count);
			format++;
		}
		else
			ft_putchar(*format, &count);
		format++;
	}
	va_end(eve);
	return (count);
}
