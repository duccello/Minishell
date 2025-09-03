/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaspari <sgaspari@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 12:24:36 by sgaspari          #+#    #+#             */
/*   Updated: 2025/09/03 11:51:07 by sgaspari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cmd.h"
#include "ft_fprintf.h"
#include "libft.h"
#include <unistd.h>

void	echo(t_cmd *cmd)
{
	int	i;

	if (cmd->argv[1] != NULL && ft_strncmp(cmd->argv[1], "-n",
				ft_strlen(cmd->argv[1]) + 1) == 0)
	{
		i = 2;
		while (cmd->argv[i] != NULL)
		{
			ft_fprintf(cmd->current_out, "%s ", cmd->argv[i]);
			i++;
		}
	}
	else
	{
		i = 1;
		while (cmd->argv[i] != NULL)
		{	
			ft_fprintf(cmd->current_out, "%s ", cmd->argv[i]);
			i++;
		}
		ft_fprintf(cmd->current_out, "\n");
	}
}
