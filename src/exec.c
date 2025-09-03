/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duccello <duccello@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 13:02:00 by duccello          #+#    #+#             */
/*   Updated: 2025/09/03 15:53:03 by duccello         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bin.h"
#include "built_in.h"
#include "cmd.h"
#include "data.h"
#include "exec.h"
#include <stdint.h>
#include "ft_fprintf.h"
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

#define READ 0
#define WRITE 1

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
		if (cmds[i]->argv[0] == NULL)
		{
			ft_fprintf(STDERR_FILENO, "syntax error\n");
			break ;
		}
		if (cmd_is_built_in(cmds[i]->argv[0], data->built_ins) == true)
			handle_built_in(data, cmds[i]);
		else
			pid[j++] = exec_binary(cmds[i]);
		if (i != 0)
			close(data->pipfd[i - 1][READ]);
		if (i < data->amount - 1)
			close(data->pipfd[i][WRITE]);
		i++;
	}
	pids_and_ret(pid, j, data);
}

void	allocate_pids(t_data *data, int **pid)
{
	if (data->bins > 0)
		*pid = malloc(sizeof(int) * data->bins);
	else
		*pid = NULL;
}

uint8_t	get_return_val(int status)
{
	uint8_t	ret_val;

	if ((status & 127) == 0)
		ret_val = (status >> 8);
	else
		ret_val = 128 + (status & 127);
	return (ret_val);
}

void	pids_and_ret(int *pid, int j, t_data *data)
{
	int	i;
	int	status;

	i = 0;
	if (pid != NULL)
	{
		while (i < j)
			waitpid(pid[i++], &status, 0);
		data->ret_val = get_return_val(status);
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
			cmds[i]->current_in = data->pipfd[i - 1][READ];
		if (i == data->amount - 1)
			cmds[i]->current_out = cmds[i]->out_fd;
		else
			cmds[i]->current_out = data->pipfd[i][WRITE];
		i++;
	}
}
