/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duccello <duccello@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 13:02:00 by duccello          #+#    #+#             */
/*   Updated: 2025/08/25 12:13:47 by sgaspari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pipex.h"
#include "built_in.h"
#include "list.h"

int	exect_binary(int in, int out, char **argv, t_cmd *c)
{
	int		pid;
	char	*path;

	pid = fork();
	if (pid == 0)
	{
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
		if (!path)
			exit(EXIT_FAILURE);
		execve(path, argv, c->envp);
		perror("Error");
		free(path);
		exit(EXIT_FAILURE);
	}
	return (pid);
}

void	pipex(t_cmd **cmds, t_data *data, int i)
{
	int	pipfd[data->amount - 1][2];
	int	status;
	int	pids[data->amount];

	while (i < data->amount)
		set_fds(cmds[i++]);
	i = 0;
	while (i < data->amount - 1)
	{
		if (pipe(pipfd[i++]) == -1)
		{
			perror("Error");
			return ;
		}
	}
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
			pids[i] = exect_binary(cmds[i]->current_in, cmds[i]->current_out, cmds[i]->argv, cmds[i]);
		if (i != 0)
			close(pipfd[i - 1][0]);
		if (i < data->amount - 1)
			close(pipfd[i][1]);
		i++;
	}
	i = 0;
	while (i < data->amount)
		waitpid(pids[i++], &status, 0);
}

t_data	*create_data(char *input, char **envp)
{
	t_data	*p;
	int		i;

	i = 0;
	p = malloc(sizeof(t_data));
	if (p == NULL)
		return (NULL);
	p->segments = ft_split(input, '|');
	p->amount = char_counter(input, '|') + 1;
	p->cmds = malloc(p->amount * sizeof(t_cmd *));
	p->envp = create_list(envp);
	if (p->cmds == NULL)
	{
		free_everything(p);
		return (NULL);
	}
	p->built_ins = create_built_ins();
	while (i < p->amount)
	{
		p->cmds[i] = parse_cmds(p->segments[i], envp);
		i++;
	}
	pipex(p->cmds, p, 0);
	free_everything(p);
	return (p);
}
