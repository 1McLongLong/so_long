/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touahman <touahman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 11:59:12 by touahman          #+#    #+#             */
/*   Updated: 2024/02/03 15:51:31 by touahman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	move_a(t_data *gg)
{
	if (gg->map[gg->x][gg->y - 1] == '1')
		return ;
	if (gg->map[gg->x][gg->y - 1] == 'E' && gg->col_count != 0)
		return ;
	if (gg->map[gg->x][gg->y - 1] == 'E' && gg->col_count == 0)
	{
		ft_printf("Congrats!!! You finished the map in %d moves.\n",
			gg->move_count);
		exit(0);
	}
	if (gg->map[gg->x][gg->y - 1] == 'C')
	{
		gg->map[gg->x][gg->y - 1] = 'P';
		gg->map[gg->x][gg->y] = '0';
		gg->col_count--;
		gg->y = gg->y - 1;
		ft_printf("%d move\n", gg->move_count++);
	}
	else
	{
		gg->map[gg->x][gg->y - 1] = 'P';
		gg->map[gg->x][gg->y] = '0';
		gg->y = gg->y - 1;
		ft_printf("%d move\n", gg->move_count++);
	}
}

void	move_s(t_data *gg)
{
	if (gg->map[gg->x + 1][gg->y] == '1')
		return ;
	if (gg->map[gg->x + 1][gg->y] == 'E' && gg->col_count != 0)
		return ;
	if (gg->map[gg->x + 1][gg->y] == 'E' && gg->col_count == 0)
	{
		ft_printf("Congrats!!! You finished the map in %d moves.\n",
			gg->move_count);
		exit(0);
	}
	if (gg->map[gg->x + 1][gg->y] == 'C')
	{
		gg->map[gg->x + 1][gg->y] = 'P';
		gg->map[gg->x][gg->y] = '0';
		gg->col_count--;
		gg->x = gg->x + 1;
		ft_printf("%d move\n", gg->move_count++);
	}
	else
	{
		gg->map[gg->x + 1][gg->y] = 'P';
		gg->map[gg->x][gg->y] = '0';
		gg->x = gg->x + 1;
		ft_printf("%d move\n", gg->move_count++);
	}
}

void	move_w(t_data *gg)
{
	if (gg->map[gg->x - 1][gg->y] == '1')
		return ;
	if (gg->map[gg->x - 1][gg->y] == 'E' && gg->col_count != 0)
		return ;
	if (gg->map[gg->x - 1][gg->y] == 'E' && gg->col_count == 0)
	{
		ft_printf("Congrats!!! You finished the map in %d moves.\n",
			gg->move_count);
		exit(0);
	}
	if (gg->map[gg->x - 1][gg->y] == 'C')
	{
		gg->map[gg->x - 1][gg->y] = 'P';
		gg->map[gg->x][gg->y] = '0';
		gg->col_count--;
		gg->x = gg->x - 1;
		ft_printf("%d move\n", gg->move_count++);
	}
	else
	{
		gg->map[gg->x - 1][gg->y] = 'P';
		gg->map[gg->x][gg->y] = '0';
		gg->x = gg->x - 1;
		ft_printf("%d move\n", gg->move_count++);
	}
}

void	move_d(t_data *gg)
{
	if (gg->map[gg->x][gg->y + 1] == '1')
		return ;
	if (gg->map[gg->x][gg->y + 1] == 'E' && gg->col_count != 0)
		return ;
	if (gg->map[gg->x][gg->y + 1] == 'E' && gg->col_count == 0)
	{
		ft_printf("Congrats!!! You finished the map in %d moves.\n",
			gg->move_count);
		exit(0);
	}
	if (gg->map[gg->x][gg->y + 1] == 'C')
	{
		gg->map[gg->x][gg->y + 1] = 'P';
		gg->map[gg->x][gg->y] = '0';
		gg->col_count--;
		gg->y = gg->y + 1;
		ft_printf("%d move\n", gg->move_count++);
	}
	else
	{
		gg->map[gg->x][gg->y + 1] = 'P';
		gg->map[gg->x][gg->y] = '0';
		gg->y = gg->y + 1;
		ft_printf("%d move\n", gg->move_count++);
	}
}
