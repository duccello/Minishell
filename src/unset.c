/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaspari <sgaspari@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 13:31:40 by sgaspari          #+#    #+#             */
/*   Updated: 2025/08/25 12:28:27 by sgaspari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include "list.h"
#include "structs.h"
#include <stdlib.h>
#include "pipex.h"

void	unset(t_data *data, t_cmd *p)
{
	char	*s;

	s = ft_strjoin(p->argv[1], "=");
	delete_node(&data->envp, s);
	if (s != NULL)
		free(s);
}
