/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touahman <touahman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 17:42:15 by touahman          #+#    #+#             */
/*   Updated: 2024/02/03 16:38:54 by touahman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	setup_graphics(t_data *data)
{
	data->mlx = mlx_init();
	if (!data->mlx)
		exit(1);
	data->mlx_win = mlx_new_window(data->mlx, data->width, data->height, "SO_LONG");
	if (!data->mlx_win)
		exit(1);
	find_p(data->map, data);
	upload_image(data);
	mlx_hook(data->mlx_win, 17, 0, handle_exit, data);
	mlx_hook(data->mlx_win, 2, 0, key_handler, data);
	mlx_loop_hook(data->mlx, render, data);
}
int	main(int argc, char **argv)
{
	t_data	data;
	char	**str;

	if (argc != 2)
	{
		write(2, "Error\n", 6);
		return (1);
	}
	str = parse_args(argv);
	if (str == NULL)
		print_error("Error\n");
	check_map(str);
	data.map = str;
	data.move_count = 1;
	data.height = count_str(data.map) * 60;
	data.width = (ft_strlen(data.map[0]) - 1) * 60;
	setup_graphics(&data);
	mlx_loop(data.mlx);
	ft_free(str);
}
