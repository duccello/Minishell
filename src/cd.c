/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaspari <sgaspari@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 17:49:22 by sgaspari          #+#    #+#             */
/*   Updated: 2025/08/22 12:09:02 by sgaspari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "structs.h"
#include "libft.h"

/* It changes the working directory by checking argv[1].
 * If name[0] is '/', it calls chdir() directly, otherwise it calls
 * getcwd() and appends to its return value the string.
 * The dynamically allocated strings (cwd, nd) are also freed. */
int	cd(t_data *data)
{
	char	*cwd;
	char	*nd;

	if (data->cmd->argv[1][0] == '/')
	{
		if (chdir(data->cmd->argv[1]) == -1)
		{
			perror("chdir");
			return (-1);
		}
	}
	else
	{
		cwd = getcwd(NULL, 0);
		if (cwd == NULL)
		{
			perror("getcwd");
			return (-1);
		}
		cwd = ft_strjoin(cwd, "/");
		nd = ft_strjoin(cwd, data->cmd->argv[1]);
		if (chdir(nd) == -1)
		{
			perror("chdir");
			return (-1);
		}
		free(cwd);
		free(nd);
	}
	return (0);
}
