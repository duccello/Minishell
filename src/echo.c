/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaspari <sgaspari@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 12:24:36 by sgaspari          #+#    #+#             */
/*   Updated: 2025/08/26 14:29:00 by sgaspari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cmd.h"
#include "ft_fprintf.h"
#include "libft.h"
<<<<<<< HEAD
#include <unistd.h>
=======
#include "macros.h"
#include "structs.h"
#include <stdio.h>
>>>>>>> origin/dante

void	echo(t_cmd *cmd)
{
	if (cmd->argv[1] == NULL)
		return ;
	if (ft_strncmp(cmd->argv[1], "-n", ft_strlen(cmd->argv[1]) + 1) == 0)
	{
		if (cmd->argv[2] == NULL)
			return ;
<<<<<<< HEAD
		ft_fprintf(cmd->current_out, "%s", cmd->argv[2]);
	}
	else
		ft_fprintf(cmd->current_out, "%s\n", cmd->argv[1]);
=======
		ft_fprintf(p->current_out, "%s", p->argv[2]);
	}
	else
		ft_fprintf(p->current_out, "%s\n", p->argv[1]);
>>>>>>> origin/dante
}
