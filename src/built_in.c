/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_in.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaspari <sgaspari@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 11:00:31 by sgaspari          #+#    #+#             */
/*   Updated: 2025/08/25 12:12:45 by sgaspari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "built_in.h"
#include "libft.h"
#include "macros.h"
#include <stddef.h>
#include <stdlib.h>

/* Wrapper that handles built-in commands.
 * It checks the name of the command and calls a function accordingly. */
void	handle_built_in(t_data *data, t_pipe *pipe)
{
	if (ft_strncmp(pipe->cmd[0], data->built_ins[ECHO],
			ft_strlen(pipe->cmd[0]) + 1) == 0)
		echo(data);
	if (ft_strncmp(pipe->cmd[0], data->built_ins[CD],
			ft_strlen(pipe->cmd[0]) + 1) == 0)
		cd(data);
	if (ft_strncmp(pipe->cmd[0], data->built_ins[PWD],
			ft_strlen(pipe->cmd[0]) + 1) == 0)
		pwd();
	if (ft_strncmp(pipe->cmd[0], data->built_ins[EXPORT],
			ft_strlen(pipe->cmd[0]) + 1) == 0)
		export(data);
	if (ft_strncmp(pipe->cmd[0], data->built_ins[UNSET],
			ft_strlen(pipe->cmd[0]) + 1) == 0)
		unset(data);
	if (ft_strncmp(pipe->cmd[0], data->built_ins[ENV],
			ft_strlen(pipe->cmd[0]) + 1) == 0)
		env(data);
	if (ft_strncmp(pipe->cmd[0], data->built_ins[EXIT],
			ft_strlen(pipe->cmd[0]) + 1) == 0)
		exit(EXIT_SUCCESS);
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
