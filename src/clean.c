/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duccello <duccello@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 17:09:47 by duccello          #+#    #+#             */
/*   Updated: 2025/09/01 10:38:07 by sgaspari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cmd.h"
#include "data.h"

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
	//free(c[i]);
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
	{
		free(c->limiter);
		c->limiter = NULL;
	}
	if (c->infile != NULL)
	{
		free(c->infile);
		c->infile = NULL;
	}
	if (c->outfile != NULL)
	{
		free(c->outfile);
		c->outfile = NULL;
	}
	free(c);
	c = NULL;
}

void	clean_data(t_data *data)
{
	int	i;

	i = 0;
	if (data->cmds != NULL)
	{
		while (i < data->amount)
			free_cmd(data->cmds[i++]);
		free(data->cmds);
		data->cmds = NULL;
	}
	if (data->segments != NULL)
		free_array(data->segments);
	if (data->pipfd != NULL)
	{
		free(data->pipfd);
		data->pipfd = NULL;
	}
	data->amount = 0;
	data->bins = 0;
	data->built_cmd = 0;
	data->total_cmds = 0;
}
