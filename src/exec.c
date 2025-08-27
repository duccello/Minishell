/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duccello <duccello@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 13:02:00 by duccello          #+#    #+#             */
/*   Updated: 2025/08/27 13:10:03 by sgaspari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bin.h"
#include "built_in.h"
#include "cmd.h"
#include "data.h"
#include "exec.h"
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

void	exec_cmd(t_cmd **cmds, t_data *data)
{
	int	i;
	int	*pid;
	int	j;

	i = 0;
	j = 0;
	allocate_pids(data, &pid);
	assign_in_out(cmds, data);
	while (i < data->amount)
	{
		if (cmds[i]->argv[i] == NULL)
		{
			i++;
			continue ;
		} 
		if (cmd_is_built_in(cmds[i]->argv[0], data->built_ins) == true
			&& data->total_cmds == 1)
			handle_built_in(data, cmds[i]);
		else if (cmd_is_built_in(cmds[i]->argv[0], data->built_ins) == true
			&& data->total_cmds > 1)
			pid[j++] = fork_built_in(data, cmds[i]);
		else 
			pid[j++] = exec_binary(cmds[i]);
		if (i != 0)
			close(data->pipfd[i - 1][0]);
		if (i < data->amount - 1)
			close(data->pipfd[i][1]);
		i++;
	}
	wait_pids(pid, j);
}

void	allocate_pids(t_data *data, int **pid)
{
	if (data->total_cmds > 1)
		*pid = malloc(sizeof(int) * data->total_cmds);
	else
		*pid = NULL;
}

void	wait_pids(int *pid, int j)
{
	int	i;
	int	status;

	i = 0;
	if (pid != NULL)
	{
		while (i < j)
			waitpid(pid[i++], &status, 0);
		free(pid);
	}
	else
		status = 0;
}

void	assign_in_out(t_cmd **cmds, t_data *data)
{
	int	i;

	i = 0;
	while (i < data->amount)
	{
		if (i == 0)
			cmds[i]->current_in = cmds[i]->in_fd;
		else
			cmds[i]->current_in = data->pipfd[i - 1][0];
		if (i == data->amount - 1)
			cmds[i]->current_out = cmds[i]->out_fd;
		else
			cmds[i]->current_out = data->pipfd[i][1];
		i++;
	}
}
