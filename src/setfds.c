void	initiate_cmds(t_cmd *c, char **envp, char *segment)
{
	c->infile = NULL;
	c->outfile = NULL;
	c->heredoc = 0;
	c->limiter = NULL;
	c->append = 0;
	c->argv = malloc((char_counter(segment, ' ') + 1) * sizeof(char *));
	c->ind = 0;
	c->paths = parse_path(envp);
	c->envp = envp;
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