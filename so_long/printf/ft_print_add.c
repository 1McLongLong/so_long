/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_add.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touahman <touahman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 16:15:44 by touahman          #+#    #+#             */
/*   Updated: 2023/11/22 10:53:25 by touahman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_print_address(unsigned long int n, int *count)
{
	char	*base;

	base = "0123456789abcdef";
	if (n < 16)
		ft_putchar(base[n % 16], count);
	else
	{
		ft_print_address(n / 16, count);
		ft_print_address(n % 16, count);
	}
}

void	ft_print_add(void *ptr, int *count)
{
	unsigned long int	nbr;

	nbr = (unsigned long)ptr;
	ft_putstr("0x", count);
	ft_print_address(nbr, count);
}
