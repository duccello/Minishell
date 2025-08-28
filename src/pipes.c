/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaspari <sgaspari@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 13:23:59 by sgaspari          #+#    #+#             */
/*   Updated: 2025/08/26 15:14:18 by sgaspari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cmd.h"
#include "data.h"
#include <stdio.h>
#include <unistd.h>

void	allocating_fds(t_data *data)
{
	int	i;

	i = 0;
	if (data->amount > 1)
	{
		data->pipfd = malloc((data->amount - 1) * sizeof(int *));
		if (!data->pipfd)
			return ;
		while (i < data->amount - 1)
		{
			data->pipfd[i] = malloc(2 * sizeof(int));
			i++;
		}
	}
	else
		data->pipfd = NULL;
}

void	create_pipes(t_data *data)
{
	int	i;

	i = 0;
	allocating_fds(data);
	if (data->pipfd != NULL)
	{
		while (i < data->amount - 1)
		{
			if (pipe(data->pipfd[i++]) == -1)
			{
				perror("pipe");
				return ;
			}
		}
	}
}
