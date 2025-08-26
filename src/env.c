/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaspari <sgaspari@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 12:54:55 by sgaspari          #+#    #+#             */
/*   Updated: 2025/08/25 12:17:48 by sgaspari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cmd.h"
#include "data.h"
#include "ft_fprintf.h"
#include "list.h"
#include "structs.h"
#include <stdio.h>

void	env(t_data *data, t_cmd *cmd)
{
	t_node	*curr;

	curr = data->envp;
	while (curr != NULL)
	{
		ft_fprintf(cmd->out_fd, "%s\n", curr->s);
		curr = curr->next;
	}
}
