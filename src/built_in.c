/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_in.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaspari <sgaspari@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 11:00:31 by sgaspari          #+#    #+#             */
/*   Updated: 2025/08/22 11:36:42 by sgaspari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stddef.h>
#include "libft.h"
#include "built_in.h"

/* Wrapper that handles built-in commands. */
void	handle_built_in(t_data *data)
{
	(void)data;
	printf("handling built in command...\n");
}

/* It checks if the string given corresponds to any of the strings
 * predefined in the array. */
bool	cmd_is_built_in(char *s, char **built_ins)
{
	size_t	i;

	i = 0;
	while (built_ins[i] != NULL)
	{
		if (ft_strncmp(s, built_ins[i], ft_strlen(s) + 1) == 0)
			return (true);
		i++;
	}
	return (false);
}
