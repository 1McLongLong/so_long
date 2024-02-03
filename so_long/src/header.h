/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touahman <touahman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 18:00:44 by touahman          #+#    #+#             */
/*   Updated: 2024/02/03 12:27:50 by touahman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <stdlib.h>
# include <mlx.h>
# include <fcntl.h>
# include <unistd.h>

typedef struct node
{
	char		*data;
	struct node	*next;
}				t_node;

typedef struct s_data
{
	int		x;
	int		y;
	char	**map;
	void	*mlx;
	void	*mlx_win;
	void	*land;
	void	*wall;
	void	*player;
	void	*coin;
	void	*exit;
	int		width;
	int		height;
	int		col_count;
	int		all_col;
	int		move_count;
}			t_data;

void	upload_image(t_data *gg);
void	find_p(char **str, t_data *gg);
int		key_handler(int keycode, t_data *data);
int		handle_exit(t_data *data);
int		ft_strlen(char *s);
char	*f_strdup(char *s1);
int		render(t_data *gg);
int		check_collec(char **str);
int		check_exit(char **str);
char	**duplicate_map(char **str, int size);
char	*get_next_line(int fd);
int		ft_printf(const char *format, ...);
t_node	*create_list(char *data);
void	add_new_line(t_node **head, char *data);
char	**parse_args(char **argv);
int		check_map(char **str);
int		check_first_last_line(char **str);
int		check_cep(char **str);
int		ft_lstsize(t_node *head);
void	free_list(t_node *head);
int		count_str(char *arr[]);
void	ft_free(char **arr);
void	print_error(char *str);

void	move_a(t_data *gg);
void	move_s(t_data *gg);
void	move_d(t_data *gg);
void	move_w(t_data *gg);

#endif
