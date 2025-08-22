/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaspari <sgaspari@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 14:53:52 by sgaspari          #+#    #+#             */
/*   Updated: 2025/08/22 15:26:24 by sgaspari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "structs.h"
#include "libft.h"
#include "macros.h"
#include "list.h"

/* It creates and dynamically allocates the main structure.
 * It calls the other create function to create its elements. */
t_data	*create_data(char **envp)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	if (data == NULL)
		return (NULL);
	data->envp = create_list(envp);
	data->built_ins = create_built_ins();
	return (data);
}

/* It creates and dynamically allocates an array containing
 * the built-in commands strings. */
char	**create_built_ins(void)
{
	char	**arr;

	arr = malloc(sizeof(char *) * NUM_BUILT_INS + 1);
	if (arr == NULL)
		return (NULL);
	arr[ECHO] = ft_strdup("echo");
	arr[CD] = ft_strdup("cd");
	arr[PWD] = ft_strdup("pwd");
	arr[EXPORT] = ft_strdup("export");
	arr[UNSET] = ft_strdup("unset");
	arr[ENV] = ft_strdup("env");
	arr[EXIT] = ft_strdup("exit");
	arr[NUM_BUILT_INS] = NULL;
	return (arr);
}

/* It creates and dynamically allocates the structure containing
 * the path of the command, its argument vector, and its name. */
t_cmd	*create_cmd(char *s)
{
	t_cmd	*cmd;

	cmd = malloc(sizeof(t_cmd));
	if (cmd == NULL)
		return (NULL);
	cmd->argv = ft_split(s, ' ');
	cmd->path = ft_strjoin("/bin/", cmd->argv[0]);
	cmd->name = cmd->argv[0];
	return (cmd);
}
