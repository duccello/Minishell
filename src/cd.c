/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaspari <sgaspari@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 17:49:22 by sgaspari          #+#    #+#             */
/*   Updated: 2025/08/22 14:26:26 by sgaspari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "structs.h"
#include "libft.h"

static int	handle_abs_path(char *s);
static int	handle_rel_path(char *s);

/* It checks the second element of the argv array and:
 * - if it is NULL, the function does nothing
 * - if it starts with '/', it calls the function
 *   responsible for the absolute path
 * - otherwise calls the function responsible for
 *   the relative path */
int	cd(t_data *data)
{
	if (data->cmd->argv[1] == NULL)
		;
	else if (data->cmd->argv[1][0] == '/')
	{
		if (handle_abs_path(data->cmd->argv[1]) == -1)
			return (-1);
	}
	else
	{
		if (handle_rel_path(data->cmd->argv[1]) == -1)
			return (-1);
	}
	return (0);
}

/* It calls chdir() passing as parameter the string given. */
static int	handle_abs_path(char *s)
{
	if (chdir(s) == -1)
	{
		perror("chdir");
		return (-1);
	}
	return (0);
}

/* It appends the relative path to the current working directory
 * and passes the obtained string to chdir(). 
 * It also frees the two dynamically allocated strings. */
static int	handle_rel_path(char *s)
{
	char	*cwd;
	char	*nd;

	cwd = getcwd(NULL, 0);
	if (cwd == NULL)
	{
		perror("getcwd");
		return (-1);
	}
	cwd = ft_strjoin(cwd, "/");
	nd = ft_strjoin(cwd, s);
	if (chdir(nd) == -1)
	{
		perror("chdir");
		return (-1);
	}
	if (cwd != NULL)
		free(cwd);
	if (nd != NULL)
		free(nd);
	return (0);
}
