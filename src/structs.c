/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaspari <sgaspari@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 14:53:52 by sgaspari          #+#    #+#             */
/*   Updated: 2025/08/22 11:11:40 by sgaspari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "structs.h"
#include "libft.h"

#define NUM_BUILT_INS 7

/* It creates and dynamically allocates the main structure.
 * It stores the environment variables in the structure. */
t_data	*create_data(char **envp)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	if (data == NULL)
		return (NULL);
	data->envp = envp;
	return (data);
}

/* It creates and dynamically allocates an array containing
 * the built-in commands strings */
char	**create_built_ins(void)
{
	char	**arr;

	arr = malloc(sizeof(char *) * NUM_BUILT_INS + 1);
	if (arr == NULL)
		return (NULL);
	arr[0] = ft_strdup("echo");
	arr[1] = ft_strdup("cd");
	arr[2] = ft_strdup("pwd");
	arr[3] = ft_strdup("export");
	arr[4] = ft_strdup("unset");
	arr[5] = ft_strdup("env");
	arr[6] = ft_strdup("exit");
	arr[NUM_BUILT_INS] = NULL;
	return (arr);
}
/* It creates and dynamically allocates the structure containing
 * the path of the command and the argument vector. */
t_cmd	*create_cmd(char *s)
{
	t_cmd	*cmd;

	cmd = malloc(sizeof(t_cmd));
	if (cmd == NULL)
		return (NULL);
	cmd->argv = ft_split(s, ' ');
	cmd->path = ft_strjoin("/bin/", cmd->argv[0]);
	return (cmd);
}
