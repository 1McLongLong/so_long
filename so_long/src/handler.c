/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touahman <touahman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 11:56:44 by touahman          #+#    #+#             */
/*   Updated: 2024/01/27 15:17:45 by touahman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	handle_exit(t_data *data)
{
	(void)data;
	exit(0);
}

static int	esc(int keycode, t_data *data)
{
	if (keycode == 53)
		mlx_destroy_window(data->mlx, data->mlx_win);
	exit (0);
}

int	key_handler(int keycode, t_data *data)
{
	if (keycode == 53)
	{
		esc(keycode, data);
	}
	else if (keycode == 0 || keycode == 123)
	{
		move_a(data);
	}
	else if (keycode == 2 || keycode == 124)
	{
		move_d(data);
	}
	else if (keycode == 13 || keycode == 126)
	{
		move_w(data);
	}
	else if (keycode == 1 || keycode == 125)
	{
		move_s(data);
	}
	return (0);
}
