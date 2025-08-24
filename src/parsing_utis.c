/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utis.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duccello <duccello@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 17:08:42 by duccello          #+#    #+#             */
/*   Updated: 2025/08/24 17:09:14 by duccello         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pipex.h"

int	count_things(char *input, char c)
{
	int	i;
	int	amount;

	i = 0;
	amount = 0;
	while (input[i])
	{
		if (input[i] == c)
			amount++;
		i++;
	}
	return (amount);
}

void	delimiter(t_pipe *c)
{
	int		fd[2];
	char	*line;

	if (pipe(fd) == -1)
		exit(1);
	line = get_next_line(STDIN_FILENO);
	while (line && ft_strncmp(line, c->limiter, ft_strlen(c->limiter)) != 0)
	{
		write(fd[1], line, ft_strlen(line));
		free(line);
		line = get_next_line(STDIN_FILENO);
	}
	free(line);
	close(fd[1]);
	c->in_fd = fd[0];
}

void	initiate_cmds(t_pipe *c, char **envp, char *segment)
{
	c->infile = NULL;
	c->outfile = NULL;
	c->heredoc = FALSE;
	c->limiter = NULL;
	c->append = FALSE;
	c->cmd = malloc((count_things(segment, ' ') + 1) * sizeof(char *));
	c->ind = 0;
	c->paths = parse_path(envp);
	c->envp = envp;
}

void	set_fds(t_pipe *c)
{
	if (c->infile != NULL && c->heredoc == FALSE)
		c->in_fd = open(c->infile, O_RDONLY);
	else if (c->heredoc == TRUE)
	{
		delimiter(c);
	}
	else
		c->in_fd = STDIN_FILENO;
	if (c->outfile != NULL && c->append == FALSE)
		c->out_fd = open(c->outfile, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	else if (c->outfile != NULL && c->append == TRUE)
		c->out_fd = open(c->outfile, O_WRONLY | O_CREAT | O_APPEND, 0644);
	else
		c->out_fd = STDOUT_FILENO;
	if (c->in_fd == -1 || c->out_fd == -1)
		exit(1);
}
