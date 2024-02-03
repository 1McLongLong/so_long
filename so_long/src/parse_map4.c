/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map4.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touahman <touahman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 15:15:00 by touahman          #+#    #+#             */
/*   Updated: 2024/02/03 15:37:49 by touahman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	check_inside_map(char **str)
{
	int	i;
	int	j;

	i = 0;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			if (str[i][j] == '1' || str[i][j] == '0' || str[i][j] == 'P'
				|| str[i][j] == 'C' || str[i][j] == 'E' || str[i][j] == '\n')
				j++;
			else
				return (1);
		}
		i++;
	}
	return (0);
}

static int	check_c(char **str)
{
	int	i;
	int	c_count;
	int	j;

	c_count = 0;
	i = -1;
	while (str[++i])
	{
		j = -1;
		while (str[i][++j])
		{
			if (str[i][j] == 'C')
				c_count++;
		}
	}
	if (c_count < 1)
		return (1);
	return (0);
}

static int	check_e(char **str)
{
	int	i;
	int	e_count;
	int	j;

	e_count = 0;
	i = -1;
	while (str[++i])
	{
		j = -1;
		while (str[i][++j])
		{
			if (str[i][j] == 'E')
				e_count++;
		}
	}
	if (e_count != 1)
		return (1);
	return (0);
}

static int	check_p(char **str)
{
	int	i;
	int	p_count;
	int	j;

	p_count = 0;
	i = -1;
	while (str[++i])
	{
		j = -1;
		while (str[i][++j])
		{
			if (str[i][j] == 'P')
				p_count++;
		}
	}
	if (p_count != 1)
		return (1);
	return (0);
}

int	check_cep(char **str)
{
	if (check_c(str) || check_e(str) || check_p(str))
		return (1);
	return (0);
}
