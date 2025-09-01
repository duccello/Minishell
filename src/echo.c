/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaspari <sgaspari@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 12:24:36 by sgaspari          #+#    #+#             */
/*   Updated: 2025/09/01 15:21:31 by sgaspari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cmd.h"
#include "ft_fprintf.h"
#include "libft.h"
#include <unistd.h>

void	echo(t_cmd *cmd)
{
	int	i;

	if (ft_strncmp(cmd->argv[1], "-n", ft_strlen(cmd->argv[1]) + 1) == 0)
	{
		i = 2;
		while (cmd->argv[i] != NULL)
		{
			ft_fprintf(cmd->current_out, "%s", cmd->argv[i++]);
			if (cmd->argv[i] != NULL)
				ft_fprintf(cmd->current_out, " ");
		}
		ft_fprintf(cmd->current_out, "\n");
	}
	else
	{
		i = 1;
		while (cmd->argv[i] != NULL)
		{	
			ft_fprintf(cmd->current_out, "%s", cmd->argv[i++]);
			if (cmd->argv[i] != NULL)
				ft_fprintf(cmd->current_out, " ");
		}
		ft_fprintf(cmd->current_out, "\n");
	}
}
