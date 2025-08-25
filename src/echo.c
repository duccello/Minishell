/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaspari <sgaspari@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 12:24:36 by sgaspari          #+#    #+#             */
/*   Updated: 2025/08/25 12:25:38 by sgaspari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"
#include "structs.h"
#include "macros.h"
#include "pipex.h"

void	echo(t_pipe *p)
{
	if (ft_strncmp(p->cmd[1], "-n",
			ft_strlen(p->cmd[1]) + 1) == 0)
		printf("%s", p->cmd[1]);
	else
		printf("%s\n", p->cmd[1]);
}
