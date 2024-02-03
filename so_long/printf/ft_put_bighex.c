/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_bighex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touahman <touahman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 14:04:28 by touahman          #+#    #+#             */
/*   Updated: 2023/11/22 10:53:44 by touahman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_put_bighex(unsigned int n, int *count)
{
	char	*base;

	base = "0123456789ABCDEF";
	if (n < 16)
		ft_putchar(base[n % 16], count);
	else
	{
		ft_put_bighex(n / 16, count);
		ft_put_bighex(n % 16, count);
	}
}
