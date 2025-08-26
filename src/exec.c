/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duccello <duccello@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 13:02:00 by duccello          #+#    #+#             */
/*   Updated: 2025/08/26 15:45:17 by sgaspari         ###   ########.fr       */
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
	int	status;
	int	*pids;

	i = 0;
	pids = NULL;
	pids = malloc(data->bins * sizeof(int));
	if (!*pids)
		return ;
	assign_in_out(cmds, data);
	if (cmd_is_built_in(cmds[i]->argv[0], data->built_ins) == true)
		handle_built_in(data, cmds[i]);
	else
		pids[i] = exec_binary(cmds[i]->current_in, cmds[i]->current_out,
				cmds[i]->argv, cmds[i]);
	i = 0;
	while (i < data->amount)
		waitpid(pids[i++], &status, 0);
	free(pids);
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
		if (i != 0)
			close(data->pipfd[i - 1][0]);
		if (i < data->amount - 1)
			close(data->pipfd[i][1]);
		i++;
	}
}
