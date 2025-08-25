/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duccello <duccello@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 13:02:00 by duccello          #+#    #+#             */
/*   Updated: 2025/08/20 13:02:02 by duccello         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pipex.h"

int	piping(int in, int out, char **cmd, t_pipe *c)
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
		path = joint_path(cmd[0], c->paths, c);
		if (!path)
			exit(EXIT_FAILURE);
		execve(path, cmd, c->envp);
		perror("Error");
		free(path);
		exit(EXIT_FAILURE);
	}
	return (pid);
}

void	pipex(t_pipe **cmds, int amount, int i)
{
	int	pipfd[amount - 1][2];
	int	status;
	int	pids[amount];
	int	current_in;
	int	current_out;

	while (i < amount)
		set_fds(cmds[i++]);
	i = 0;
	while (i < amount - 1)
	{
		if (pipe(pipfd[i++]) == -1)
		{
			perror("Error");
			return ;
		}
	}
	i = 0;
	while (i < amount)
	{
		if (i == 0)
			current_in = cmds[i]->in_fd;
		else
			current_in = pipfd[i - 1][0];
		if (i == amount - 1)
			current_out = cmds[i]->out_fd;
		else
			current_out = pipfd[i][1];
		pids[i] = piping(current_in, current_out, cmds[i]->cmd, cmds[i]);
		if (i != 0)
			close(pipfd[i - 1][0]);
		if (i < amount - 1)
			close(pipfd[i][1]);
		i++;
	}
	i = 0;
	while (i < amount)
		waitpid(pids[i++], &status, 0);
}

int	pipes(char *input, char **envp)
{
	t_pipex	*p;
	int		i;

	i = 0;
	p = malloc(sizeof(t_pipex));
	p->segments = ft_split(input, '|');
	p->amount = count_things(input, '|') + 1;
	p->pipes = malloc(p->amount * sizeof(t_pipe *));
	while (i < p->amount)
	{
		p->pipes[i] = parse_pipes(p->segments[i], envp);
		i++;
	}
	pipex(p->pipes, p->amount, 0);
	free_everything(p);
	return (0);
}
