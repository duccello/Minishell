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
#include "list.h"
#include "pipex.h"
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

void	separate_exc(t_cmd **cmds, t_data *data, int **pipfd, int *pids)
{
	int	i;

	i = 0;
	while (i < data->amount)
	{
		if (i == 0)
			cmds[i]->current_in = cmds[i]->in_fd;
		else
			cmds[i]->current_in = pipfd[i - 1][0];
		if (i == data->amount - 1)
			cmds[i]->current_out = cmds[i]->out_fd;
		else
			cmds[i]->current_out = pipfd[i][1];
		if (cmd_is_built_in(cmds[i]->argv[0], data->built_ins) == true)
			handle_built_in(data, cmds[i]);
		else
			pids[i] = exect_binary(cmds[i]->current_in, cmds[i]->current_out,
					cmds[i]->argv, cmds[i]);
		if (i != 0)
			close(pipfd[i - 1][0]);
		if (i < data->amount - 1)
			close(pipfd[i][1]);
		i++;
	}
}

void	allocating_fds(int ***pipfd, int **pids, t_data *data)
{
	int	i;

	i = 0;
	*pipfd = malloc((data->amount - 1) * sizeof(int *));
	if (!*pipfd)
		return ;
	while (i < data->amount - 1)
	{
		(*pipfd)[i] = malloc(2 * sizeof(int));
		i++;
	}
	*pids = malloc(data->amount * sizeof(int));
	if (!*pids)
		return ;
}

void	create_pipes(t_data *data, int **pipfd)
{
	int	i;

	i = 0;
	while (i < data->amount - 1)
	{
		if (pipe(pipfd[i++]) == -1)
		{
			perror("Pipes");
			return ;
		}
	}
}
void	execute_cmds(t_cmd **cmds, t_data *data)
{
	int	i;
	int	**pipfd;
	int	status;
	int	*pids;

	i = 0;
	pipfd = NULL;
	pids = NULL;
	while (i < data->amount)
		set_fds(cmds[i++]);
	allocating_fds(&pipfd, &pids, data);
	create_pipes(data, pipfd);
	separate_exc(cmds, data, pipfd, pids);
	i = 0;
	while (i < data->amount)
		waitpid(pids[i++], &status, 0);
	i = 0;
 	while (i < data->amount - 1)
		free(pipfd[i++]);
	free(pipfd);
	free(pids);
}
