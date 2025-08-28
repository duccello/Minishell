/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaspari <sgaspari@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 12:39:54 by sgaspari          #+#    #+#             */
/*   Updated: 2025/08/26 15:04:41 by sgaspari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cmd.h"
#include "ft_fprintf.h"
#include <stdlib.h>
#include <unistd.h>

/* It calls getcwd(), prints its return value and then frees it. */
void	pwd(t_cmd *cmd)
{
	char	*s;

	s = getcwd(NULL, 0);
	ft_fprintf(cmd->current_out, "%s\n", s);
	free(s);
}
