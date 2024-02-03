/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touahman <touahman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 12:01:11 by touahman          #+#    #+#             */
/*   Updated: 2024/02/03 16:38:07 by touahman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	print_error(char *str)
{
	while (*str)
		write(2, str++, 1);
	exit(1);
}

int	check_map(char **str)
{
	int	i;
	int	first_line_len;
	int	new_len;

	if (count_str(str) > 136 || ft_strlen(str[0]) > 137)
		print_error("Error\nWrong MAP\n");
	if (!(check_first_last_line(str)))
		print_error("Error\nWrong MAP\n");
	first_line_len = ft_strlen(str[0]) - 1;
	i = 0;
	while (str[i] && i < count_str(str) - 1)
	{
		new_len = ft_strlen(str[i]) - 1;
		if (new_len != first_line_len)
			print_error("Error\nWrong MAP\n");
		if (str[i][0] != '1' || str[i][new_len - 1] != '1')
			print_error("Error\nWrong MAP\n");
		i++;
	}
	if (check_cep(str) || check_collec(str) || check_exit(str)
		|| check_inside_map(str))
		print_error("Error\nWrong MAP\n");
	return (1);
}

void	add_to_arr(t_node *head, char **arr, int size)
{
	int	i;

	i = 0;
	while (head && i < size)
	{
		arr[i] = f_strdup(head->data);
		head = head->next;
		i++;
	}
	arr[i] = NULL;
}

char	**read_from_file(int fd)
{
	t_node	*head;
	int		list_len;
	char	*line;
	char	**arr;

	head = NULL;
	line = get_next_line(fd);
	if (!line)
		print_error("Error\nWrong FILE\n");
	while (line)
	{
		add_new_line(&head, line);
		free(line);
		line = get_next_line(fd);
	}
	list_len = ft_lstsize(head);
	arr = malloc((list_len + 1) * sizeof(char *));
	if (!arr)
		exit(1);
	add_to_arr(head, arr, list_len);
	free_list(head);
	return (arr);
}

char	**parse_args(char **argv)
{
	char	*str;
	char	**arr;
	int		fd;
	int		len;

	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		print_error("Error\nWrong FILE\n");
	str = argv[1];
	len = ft_strlen(str);
	if ((str[len - 1] != 'r') || (str[len - 2] != 'e')
		|| (str[len - 3] != 'b') || (str[len - 4] != '.'))
	{
		print_error("Error\nWrong FILE\n");
	}
	arr = read_from_file(fd);
	close(fd);
	return (arr);
}
