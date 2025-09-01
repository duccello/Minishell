/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaspari <sgaspari@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 12:48:38 by sgaspari          #+#    #+#             */
/*   Updated: 2025/09/01 10:55:17 by sgaspari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "list.h"
#include "cmd.h"
#include "data.h"

void	export(t_cmd *p)
{
	t_node	*node;

	node = create_node(p->argv[1]);
	append_node(&p->data->envp, node);
}
