/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_in.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaspari <sgaspari@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 11:00:31 by sgaspari          #+#    #+#             */
/*   Updated: 2025/08/23 12:53:46 by sgaspari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stddef.h>
#include "libft.h"
#include "built_in.h"
#include "macros.h"

/* Wrapper that handles built-in commands.
 * It checks the name of the command and calls a function accordingly. */
void	handle_built_in(t_data *data)
{
	if (ft_strncmp(data->cmd->name, data->built_ins[EXIT],
				ft_strlen(data->cmd->name) + 1) == 0)
		exit (EXIT_SUCCESS);
	if (ft_strncmp(data->cmd->name, data->built_ins[CD],
				ft_strlen(data->cmd->name) + 1) == 0)
		cd(data);
	if (ft_strncmp(data->cmd->name, data->built_ins[PWD],
				ft_strlen(data->cmd->name) + 1) == 0)
		pwd();
	if (ft_strncmp(data->cmd->name, data->built_ins[ECHO],
				ft_strlen(data->cmd->name) + 1) == 0)
		echo(data);
	if (ft_strncmp(data->cmd->name, data->built_ins[EXPORT],
				ft_strlen(data->cmd->name) + 1) == 0)
		export(data);
	if (ft_strncmp(data->cmd->name, data->built_ins[ENV],
				ft_strlen(data->cmd->name) + 1) == 0)
		env(data);
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
