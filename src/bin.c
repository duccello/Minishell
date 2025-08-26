/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bin.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaspari <sgaspari@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 15:32:36 by sgaspari          #+#    #+#             */
/*   Updated: 2025/08/26 16:35:41 by sgaspari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "signals.h"
#include <stdio.h>
#include "bin.h"
#include "clean.h"
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

void	exec_binary(t_cmd *c)
{
	int		pid;
	char	*path;

	g_flag = 0;
	pid = fork();
	if (pid == 0)
	{
		g_flag = 1;
		if (c->current_in != STDIN_FILENO)
		{
			dup2(c->current_in, STDIN_FILENO);
			close(c->current_in);
		}
		if (c->current_out != STDOUT_FILENO)
		{
			dup2(c->current_out, STDOUT_FILENO);
			close(c->current_out);
		}
		path = join_path(c->argv[0], c->paths, c);
		execve(path, c->argv, c->envp);
		perror("execve");
		free(path);
		exit(EXIT_FAILURE);
	}
	else
		wait(NULL);
}

char	*join_path(char *cmd, char **paths, t_cmd *c)
{
	char	*tmp;
	char	*full;
	int		i;

	i = 0;
	if (cmd == NULL)
	{
		free_cmd(c);
		return (NULL);
	}
	if (ft_strchr(cmd, '/'))
		return (ft_strdup(cmd));
	while (paths[i])
	{
		tmp = ft_strjoin(paths[i++], "/");
		full = ft_strjoin(tmp, cmd);
		free(tmp);
		if (access(full, X_OK) == 0)
			return (full);
		free(full);
	}
	free_cmd(c);
	unlink(c->outfile);
	perror("access");
	return (NULL);
}
