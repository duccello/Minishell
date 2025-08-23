/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaspari <sgaspari@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 12:24:36 by sgaspari          #+#    #+#             */
/*   Updated: 2025/08/23 12:32:10 by sgaspari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"
#include "ft_printf.h"
#include "structs.h"
#include "macros.h"

void	echo(t_data *data)
{
	if (ft_strncmp(data->cmd->argv[1], "-n",
			ft_strlen(data->cmd->argv[1]) + 1) == 0)
		ft_printf("%s", data->cmd->argv[2]);
	else
		ft_printf("%s\n", data->cmd->argv[1]);
}
