/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaspari <sgaspari@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 13:34:32 by sgaspari          #+#    #+#             */
/*   Updated: 2025/09/04 13:39:16 by sgaspari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cmd.h"
#include "list.h"
#include "libft.h"
#include <stdlib.h>

char	**parse_path(t_node *envp)
{
	char	**paths;
	char	*start;

	start = path_start(envp);
	if (!start)
		return (NULL);
	paths = ft_split(start, ':');
	return (paths);
}

char	*path_start(t_node *envp)
{
	t_node	*curr;

	curr = envp;
	while (curr != NULL)
	{
		if (ft_strncmp(curr->s, "PATH=", 5) == 0)
			return (curr->s + 5);
		curr = curr->next;
	}
	return (NULL);
}
