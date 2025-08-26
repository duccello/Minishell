/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bin.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaspari <sgaspari@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 15:32:36 by sgaspari          #+#    #+#             */
/*   Updated: 2025/08/26 15:40:50 by sgaspari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "signals.h"
#include <stdio.h>
#include "bin.h"
#include "clean.h"
#include <stdlib.h>
#include <unistd.h>

int	exec_binary(int in, int out, char **argv, t_cmd *c)
{
	int		pid;
	char	*path;

	g_flag = 0;
	pid = fork();
	if (pid == 0)
	{
		g_flag = 1;
		if (in != STDIN_FILENO)
		{
			dup2(in, STDIN_FILENO);
			close(in);
		}
		if (out != STDOUT_FILENO)
		{
			dup2(out, STDOUT_FILENO);
			close(out);
		}
		path = join_path(argv[0], c->paths, c);
		execve(path, argv, c->envp);
		perror("execve");
		free(path);
		exit(EXIT_FAILURE);
	}
	return (pid);
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
