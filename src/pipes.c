/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_pipes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaspari <sgaspari@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 12:21:01 by sgaspari          #+#    #+#             */
/*   Updated: 2025/08/26 12:23:44 by sgaspari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipes.h"
#include "data.h"

void	create_pipes(t_data *data)
{
	int	i;

	i = 0;
    allocate_fds(data);
	while (i < data->amount - 1)
	{
		if (pipe(data->pipfd[i++]) == -1)
		{
			perror("pipe");
			return ;
		}
	}
}

void	allocate_fds(t_data *data)
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

