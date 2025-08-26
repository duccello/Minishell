#include "cmd.h"
#include <stdbool.h>

void	delimiter(t_cmd *c)
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

void	set_fds(t_cmd *c)
{
	if (c->infile != NULL && c->heredoc == false)
		c->in_fd = open(c->infile, O_RDONLY);
	else if (c->heredoc == true)
	{
		delimiter(c);
	}
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