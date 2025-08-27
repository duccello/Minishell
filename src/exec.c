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
	int *pid;

	pid = malloc(sizeof(int) * data->bins);
	assign_in_out(cmds, data);
	i = 0;
	while (i < data->amount)
	{
		if (cmd_is_built_in(cmds[i]->argv[0], data->built_ins) == true)
			handle_built_in(data, cmds[i]);
		else
			exec_binary(cmds[i]);
		i++;
	}
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
