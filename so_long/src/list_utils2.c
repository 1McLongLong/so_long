/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touahman <touahman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 11:58:29 by touahman          #+#    #+#             */
/*   Updated: 2024/01/25 17:50:20 by touahman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	count_str(char *arr[])
{
	int	i;

	i = 0;
	while (arr[i] != NULL)
		i++;
	return (i);
}

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

void	find_p(char **str, t_data *gg)
{
	int	i;
	int	j;

	i = 0;
	while (str[i])
	{
		j = 0;
		while (str[i][j] && str[i][j] != '\n')
		{
			if (str[i][j] == 'P')
			{
				gg->y = j;
				gg->x = i;
			}
			if (str[i][j] == 'C')
				gg->col_count++;
			j++;
		}
		i++;
	}
}

char	*f_strdup(char *s1)
{
	int		i;
	int		size;
	char	*copy;

	size = ft_strlen(s1);
	copy = malloc(sizeof(char) * size + 1);
	if (copy == 0)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		copy[i] = s1[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}
