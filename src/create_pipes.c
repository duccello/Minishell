void	allocating_fds(t_data *data)
{
	int	i;

	i = 0;
	data->pipfd = malloc((data->amount - 1) * sizeof(int *));
	if (!data->pipfd)
		return ;
	while (i < data->amount - 1)
	{
		data->pipfd[i] = malloc(2 * sizeof(int));
		i++;
	}
}

void	create_pipes(t_data *data)
{
	int	i;

	i = 0;
    allocating_fds(data);
	while (i < data->amount - 1)
	{
		if (pipe(data->pipfd[i++]) == -1)
		{
			perror("Pipes");
			return ;
		}
	}
}