/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaspari <sgaspari@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 12:48:38 by sgaspari          #+#    #+#             */
/*   Updated: 2025/08/26 14:02:51 by sgaspari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"
#include "cmd.h"
#include "data.h"

void	export(t_data *data, t_cmd *p)
{
	t_node	*node;

	node = create_node(p->argv[1]);
	append_node(&data->envp, node);
}
