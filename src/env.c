/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaspari <sgaspari@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 12:54:55 by sgaspari          #+#    #+#             */
/*   Updated: 2025/08/26 14:29:43 by sgaspari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cmd.h"
#include "data.h"
#include "ft_fprintf.h"
#include "list.h"
#include <unistd.h>

void	env(t_data *data, t_cmd *cmd)
{
	t_node	*curr;

	curr = data->envp;
	if (data->amount > 1)
	{
		while (curr != NULL)
		{
			ft_fprintf(STDOUT_FILENO, "%s\n", curr->s);
			curr = curr->next;
		}
	}
	else
	{
		while (curr != NULL)
		{
			ft_fprintf(cmd->current_out, "%s\n", curr->s);
			curr = curr->next;
		}
	}
}
