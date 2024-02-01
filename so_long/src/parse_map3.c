/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touahman <touahman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 17:36:34 by touahman          #+#    #+#             */
/*   Updated: 2024/02/01 16:20:59 by touahman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	check_init_c(char **str)
{
	int	i;
	int	j;
	int	c_count;

	i = 0;
	j = 0;
	c_count = 0;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			if (str[i][j] == 'C')
				c_count++;
			j++;
		}
		i++;
	}
	return (c_count);
}

int	find_row(char **str)
{
	int	cols;
	int	size;
	int	i;
	int	j;

	i = 0;
	cols = ft_strlen(str[0]) - 1;
	size = count_str(str);
	while (i < size)
	{
		j = 0;
		while (j < cols)
		{
			if (str[i][j] == 'P')
				break ;
			j++;
		}
		if (str[i][j] == 'P')
			break ;
		i++;
	}
	return (i);
}

int	find_col(char **str)
{
	int	cols;
	int	size;
	int	i;
	int	j;

	i = 0;
	cols = ft_strlen(str[0]) - 1;
	size = count_str(str);
	while (i < size)
	{
		j = 0;
		while (j < cols)
		{
			if (str[i][j] == 'P')
				break ;
			j++;
		}
		if (str[i][j] == 'P')
			break ;
		i++;
	}
	return (j);
}

static int	flood_fill2(char **str, int pos_x,
						int pos_y, char temp)
{
	int	collec_count;
	int	rows;
	int	cols;

	rows = count_str(str);
	cols = ft_strlen(str[0]);
	collec_count = 0;
	if (pos_x < 0 || pos_x >= rows || pos_y < 0 || pos_y >= cols)
		return (0);
	if (str[pos_x][pos_y] == '1' || str[pos_x][pos_y] == 'E'
		|| str[pos_x][pos_y] == temp)
		return (0);
	if (str[pos_x][pos_y] == 'C')
		collec_count++;
	str[pos_x][pos_y] = temp;
	collec_count += flood_fill2(str, pos_x + 1, pos_y, temp);
	collec_count += flood_fill2(str, pos_x - 1, pos_y, temp);
	collec_count += flood_fill2(str, pos_x, pos_y + 1, temp);
	collec_count += flood_fill2(str, pos_x, pos_y - 1, temp);
	return (collec_count);
}

int	check_collec(char **str)
{
	int		row;
	int		col;
	int		init_collec_count;
	int		collec_count;
	char	**dup_map;

	dup_map = duplicate_map(str, count_str(str));
	if (!dup_map)
		exit (1);
	init_collec_count = check_init_c(dup_map);
	row = find_row(dup_map);
	col = find_col(dup_map);
	collec_count = flood_fill2(dup_map, row, col, 'F');
	ft_free(dup_map);
	if (collec_count != init_collec_count)
		return (1);
	return (0);
}
