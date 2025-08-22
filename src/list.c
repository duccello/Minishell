/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaspari <sgaspari@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 14:46:31 by sgaspari          #+#    #+#             */
/*   Updated: 2025/08/22 15:28:45 by sgaspari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "list.h"
#include "structs.h"
#include "stddef.h"

t_node	*create_list(char **arr)
{
	t_node	*list;
	t_node	*node;
	size_t	i;

	list = NULL;
	i = 0;
	while (arr[i] != NULL)
	{
		node = create_node(arr[i]);
		append_node(&list, node);
		i++;
	}
	return (list);
}

t_node	*create_node(char *s)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	if (node == NULL)
		return (NULL);
	node->s = s;
	node->next = NULL;
	return (node);
}

void	append_node(t_node **list, t_node *node)
{
	t_node	*last_node;

	if (*list == NULL)
		*list = node;
	else
	{
		last_node = find_last_node(*list);
		last_node->next = node;
	}
}

t_node	*find_last_node(t_node *list)
{
	t_node	*curr;

	curr = list;
	while (curr->next != NULL)
		curr = curr->next;
	return (curr);
}
