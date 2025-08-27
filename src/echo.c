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
#include "data.h"
#include "ft_fprintf.h"
#include "libft.h"
#include <unistd.h>

void	echo(t_data *data, t_cmd *p)
{
	if (p->argv[1] == NULL)
		return ;
	if (data->amount > 1)
	{
		if (ft_strncmp(p->argv[1], "-n", ft_strlen(p->argv[1]) + 1) == 0)
		{
			if (p->argv[2] == NULL)
				return ;
			ft_fprintf(STDOUT_FILENO, "%s", p->argv[2]);
		}
		else
			ft_fprintf(STDOUT_FILENO, "%s\n", p->argv[1]);
	}
	else
	{
		if (ft_strncmp(p->argv[1], "-n", ft_strlen(p->argv[1]) + 1) == 0)
		{
			if (p->argv[2] == NULL)
				return ;
			ft_fprintf(p->current_out, "%s", p->argv[2]);
		}
		else
			ft_fprintf(p->current_out, "%s\n", p->argv[1]);
	}
}
