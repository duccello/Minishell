/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaspari <sgaspari@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 13:31:40 by sgaspari          #+#    #+#             */
/*   Updated: 2025/09/01 15:07:21 by sgaspari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "list.h"
#include "data.h"
#include "cmd.h"

void	unset(t_cmd *p)
{
	char	*s;

	//fix this
	s = ft_strjoin(p->argv[1], "=");
	if (s != NULL)
		free(s);
	delete_node(&p->data->envp, s);
}
