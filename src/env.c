/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaspari <sgaspari@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 12:54:55 by sgaspari          #+#    #+#             */
/*   Updated: 2025/08/23 12:58:16 by sgaspari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"
#include "structs.h"
#include "ft_printf.h"

void	env(t_data *data)
{
	t_node *curr;

	curr = data->envp;
	while (curr != NULL)
	{
		ft_printf("%s\n", curr->s);
		curr = curr->next;
	}
}

