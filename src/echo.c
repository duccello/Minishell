/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaspari <sgaspari@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 12:24:36 by sgaspari          #+#    #+#             */
/*   Updated: 2025/08/25 19:04:04 by sgaspari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cmd.h"
#include "ft_fprintf.h"
#include "libft.h"
#include "macros.h"
#include "structs.h"
#include <stdio.h>

void	echo(t_cmd *p)
{
	if (p->argv[1] == NULL)
		return ;
	if (ft_strncmp(p->argv[1], "-n", ft_strlen(p->argv[1]) + 1) == 0)
	{
		if (p->argv[2] == NULL)
			return ;
		ft_fprintf(p->current_out, "%s", p->argv[2]);
	}
	else
		ft_fprintf(p->current_out, "%s\n", p->argv[1]);
}
