/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duccello <duccello@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 13:02:00 by duccello          #+#    #+#             */
/*   Updated: 2025/08/25 15:38:11 by sgaspari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "built_in.h"
#include "cmd.h"
#include "data.h"
#include "list.h"
#include "parsing.h"
#include "signal_handler.h"

int	exect_binary(int in, int out, char **argv, t_cmd *c)
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
		path = joint_path(argv[0], c->paths, c);
		execve(path, argv, c->envp);
		perror("Exec");
		free(path);
		exit(EXIT_FAILURE);
	}
	return (pid);
}

void	separate_exc(t_cmd **cmds, t_data *data, int *pids)
{
	int	i;
	int	current_in;
	int	current_out;

	i = 0;
	while (i < data->amount)
	{
		if (i == 0)
			current_in = cmds[i]->in_fd;
		else
			current_in = data->pipfd[i - 1][0];
		if (i == data->amount - 1)
			current_out = cmds[i]->out_fd;
		else
			current_out = data->pipfd[i][1];
		if (cmd_is_built_in(cmds[i]->argv[0], data->built_ins) == true)
			handle_built_in(data, cmds[i]);
		else
			pids[i] = exect_binary(current_in, current_out, cmds[i]->argv,
					cmds[i]);
		if (i != 0)
			close(data->pipfd[i - 1][0]);
		if (i < data->amount - 1)
			close(data->pipfd[i][1]);
		i++;
	}
}

void	execute_cmds(t_cmd **cmds, t_data *data)
{
	int	i;
	int	status;
	int	*pids;

	i = 0;
	pids = NULL;
	pids = malloc(data->bins * sizeof(int));
	if (!*pids)
		return ;
	separate_exc(cmds, data, pids);
	i = 0;
	while (i < data->amount)
		waitpid(pids[i++], &status, 0);
	free(pids);
}
