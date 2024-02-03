/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touahman <touahman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 17:31:06 by touahman          #+#    #+#             */
/*   Updated: 2024/02/03 15:50:45 by touahman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	upload_image(t_data *gg)
{
	int	width;
	int	height;

	width = 60;
	height = 60;
	gg->player = mlx_xpm_file_to_image(gg->mlx,
			"./textures/player.xpm", &width, &height);
	if (!gg->player)
		print_error("Error\nWrong TEXTURE\n");
	gg->land = mlx_xpm_file_to_image(gg->mlx,
			"./textures/land11.xpm", &width, &height);
	if (!gg->land)
		print_error("Error\nWrong TEXTURE\n");
	gg->wall = mlx_xpm_file_to_image(gg->mlx,
			"./textures/wall11.xpm", &width, &height);
	if (!gg->wall)
		print_error("Error\nWrong TEXTURE\n");
	gg->coin = mlx_xpm_file_to_image(gg->mlx,
			"./textures/collec.xpm", &width, &height);
	if (!gg->coin)
		print_error("Error\nWrong TEXTURE\n");
	gg->exit = mlx_xpm_file_to_image(gg->mlx,
			"./textures/door.xpm", &width, &height);
	if (!gg->exit)
		print_error("Error\nWrong TEXTURE\n");
}

void	render_map_elements(t_data *gg, int i, int j)
{
	if (gg->map[i][j] == '1')
		mlx_put_image_to_window(gg->mlx, gg->mlx_win, gg->wall, j * 60, i * 60);
	else if (gg->map[i][j] == 'C')
	{
		mlx_put_image_to_window(gg->mlx, gg->mlx_win, gg->land, j * 60, i * 60);
		mlx_put_image_to_window(gg->mlx, gg->mlx_win, gg->coin, j * 60, i * 60);
	}
	else if (gg->map[i][j] == 'P')
	{
		mlx_put_image_to_window(gg->mlx, gg->mlx_win, gg->land, j * 60, i * 60);
		mlx_put_image_to_window(gg->mlx, gg->mlx_win,
			gg->player, j * 60, i * 60);
	}
	else if (gg->map[i][j] == 'E')
	{
		mlx_put_image_to_window(gg->mlx, gg->mlx_win, gg->land, j * 60, i * 60);
		mlx_put_image_to_window(gg->mlx, gg->mlx_win, gg->exit, j * 60, i * 60);
	}
	else
		mlx_put_image_to_window(gg->mlx, gg->mlx_win, gg->land, j * 60, i * 60);
}

int	render(t_data *gg)
{
	int	i;
	int	j;

	i = 0;
	while (i < count_str(gg->map))
	{
		j = 0;
		while (j < ft_strlen(gg->map[0]) - 1)
		{
			render_map_elements(gg, i, j);
			j++;
		}
		i++;
	}
	return (0);
}
