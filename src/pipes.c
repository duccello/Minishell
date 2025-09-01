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

void	create_pipes(t_data *data)
{
	int	i;

	if (data->amount > 1)
	{
		data->pipfd = malloc((data->amount - 1) * sizeof(int[2]));
		if (!data->pipfd)
		{
			perror("pipe alloc");
			return ;
		}
	}
	else
		data->pipfd = NULL;
	i = 0;
	if (data->pipfd != NULL)
	{
		while (i < data->amount - 1)
		{
			if (pipe(data->pipfd[i++]) == -1)
			{
				perror("pipe init");
				return ;
			}
		}
	}
}
