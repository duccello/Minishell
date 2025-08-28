/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duccello <duccello@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 17:09:47 by duccello          #+#    #+#             */
/*   Updated: 2025/08/26 12:37:26 by sgaspari         ###   ########.fr       */
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
	//	if (c->envp != NULL)
	//		free_array(c->envp); we will move this
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
	free_array(data->built_ins); // not efficient
	free(data->pipfd);
	free(data);
}
