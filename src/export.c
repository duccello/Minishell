/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaspari <sgaspari@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 12:48:38 by sgaspari          #+#    #+#             */
/*   Updated: 2025/08/23 12:52:58 by sgaspari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"
#include "structs.h"

void	export(t_data *data)
{
	t_node	*node;

	node = create_node(data->cmd->argv[1]);
	append_node(&data->envp, node);
}
