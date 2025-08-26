/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freeing_pipes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duccello <duccello@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 17:09:47 by duccello          #+#    #+#             */
/*   Updated: 2025/08/25 12:14:57 by sgaspari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "data.h"
#include "cmd.h"

void	free_array(char **c)
{
	int	i;

	i = 0;
	while (c[i])
	{
		free(c[i]);
		c[i] = NULL;
		i++;
	}
	free(c[i]);
	free(c);
	c = NULL;
}

void	free_cmd(t_cmd *c)
{
	if (c->argv != NULL)
		free_array(c->argv);
	if (c->paths != NULL)
		free_array(c->paths);
	if (c->limiter != NULL)
		free(c->limiter);
	if (c->infile != NULL)
		free(c->infile);
	if (c->outfile != NULL)
		free(c->outfile);
	free(c);
}
void	free_everything(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->amount)
		free_cmd(data->cmds[i++]);
	free(data->cmds);
	free_array(data->segments);
	free(data);
	while (i < data->amount - 1)
		free(data->pipfd[i++]);
	free(data->pipfd);
}
