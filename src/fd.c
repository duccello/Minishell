/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaspari <sgaspari@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 13:46:10 by sgaspari          #+#    #+#             */
/*   Updated: 2025/09/03 10:26:14 by sgaspari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cmd.h"
#include "data.h"
#include "get_next_line.h"
#include "utils.h"
#include <fcntl.h>
#include <stdbool.h>
#include <stdlib.h>
#include <unistd.h>

#define READ 0
#define WRITE 1

void	delimiter(t_cmd *c)
{
	int		fd[2];
	char	*line;

	if (pipe(fd) == -1)
		exit(1);
	line = get_next_line(STDIN_FILENO);
	while (line && ft_strncmp(line, c->limiter, ft_strlen(c->limiter)) != 0)
	{
		write(fd[WRITE], line, ft_strlen(line));
		free(line);
		line = get_next_line(STDIN_FILENO);
	}
	free(line);
	close(fd[WRITE]);
	c->in_fd = fd[READ];
}

void	set_fds(t_cmd *c)
{
	if (c->infile != NULL && c->heredoc == false)
		c->in_fd = open(c->infile, O_RDONLY);
	else if (c->heredoc == true)
		delimiter(c);
	else
		c->in_fd = STDIN_FILENO;
	if (c->outfile != NULL && c->append == false)
		c->out_fd = open(c->outfile, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	else if (c->outfile != NULL && c->append == true)
		c->out_fd = open(c->outfile, O_WRONLY | O_CREAT | O_APPEND, 0644);
	else
		c->out_fd = STDOUT_FILENO;
	if (c->in_fd == -1 || c->out_fd == -1)
		exit(1);
}
