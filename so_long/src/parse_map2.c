/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touahman <touahman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 17:36:43 by touahman          #+#    #+#             */
/*   Updated: 2024/02/03 16:37:02 by touahman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char	**duplicate_map(char **str, int size)
{
	char	**dup_map;
	int		i;

	dup_map = malloc(sizeof(char *) * (size + 1));
	if (!dup_map)
		return (NULL);
	i = 0;
	while (str[i])
	{
		dup_map[i] = f_strdup(str[i]);
		i++;
	}
	dup_map[i] = NULL;
	return (dup_map);
}

static int	flood_fill(char **str, int pos_x,
						int pos_y, char temp)
{
	int	exit_count;
	int	rows;
	int	cols;

	rows = count_str(str);
	cols = ft_strlen(str[0]);
	exit_count = 0;
	if (pos_x < 0 || pos_x >= rows || pos_y < 0 || pos_y >= cols)
		return (0);
	if (str[pos_x][pos_y] == '1' || str[pos_x][pos_y] == temp)
		return (0);
	if (str[pos_x][pos_y] == 'E')
		exit_count++;
	str[pos_x][pos_y] = temp;
	exit_count += flood_fill(str, pos_x + 1, pos_y, temp);
	exit_count += flood_fill(str, pos_x - 1, pos_y, temp);
	exit_count += flood_fill(str, pos_x, pos_y + 1, temp);
	exit_count += flood_fill(str, pos_x, pos_y - 1, temp);
	return (exit_count);
}

int	check_exit(char **str)
{
	int		i;
	int		j;
	int		exit_count;
	char	**dup_map;

	dup_map = duplicate_map(str, count_str(str));
	if (!dup_map)
		exit (1);
	i = -1;
	while (++i < count_str(str))
	{
		j = -1;
		while (++j < ft_strlen(str[0]) - 1)
		{
			if (str[i][j] == 'P')
				break ;
		}
		if (str[i][j] == 'P')
			break ;
	}
	exit_count = flood_fill(dup_map, i, j, 'F');
	ft_free(dup_map);
	if (exit_count != 1)
		return (1);
	return (0);
}

int	check_first_last_line(char **str)
{
	int	i;
	int	size;

	i = 0;
	while (str[0][i] && str[0][i] != '\n')
	{
		if (str[0][i] != '1')
			return (0);
		i++;
	}
	size = count_str(str) - 1;
	i = 0;
	while (str[size][i] && str[size][i] != '\n')
	{
		if (str[size][i] != '1')
			return (0);
		i++;
	}
	if ((ft_strlen(str[0]) - 1) != ft_strlen(str[size]))
			return (0);
	return (1);
}
