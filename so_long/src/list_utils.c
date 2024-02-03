/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touahman <touahman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 11:56:15 by touahman          #+#    #+#             */
/*   Updated: 2024/01/25 11:56:16 by touahman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

t_node	*create_list(char *data)
{
	t_node	*new_line;

	new_line = malloc(sizeof(t_node));
	if (new_line == NULL)
		return (NULL);
	new_line->data = f_strdup(data);
	new_line->next = NULL;
	return (new_line);
}

void	add_new_line(t_node **head, char *data)
{
	t_node	*new_line;
	t_node	*temp;

	new_line = create_list(data);
	if (*head == NULL)
		*head = new_line;
	else
	{
		temp = *head;
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = new_line;
	}
}

int	ft_lstsize(t_node *head)
{
	t_node	*temp;
	int		size;

	temp = head;
	size = 0;
	while (temp != NULL)
	{
		size++;
		temp = temp->next;
	}
	return (size);
}

void	free_list(t_node *head)
{
	t_node	*temp;

	while (head)
	{
		temp = head;
		head = head->next;
		free(temp->data);
		free(temp);
	}
}

void	ft_free(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}
