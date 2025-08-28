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

<<<<<<< HEAD
#include "ft_fprintf.h"
=======
#include "cmd.h"
#include "ft_fprintf.h"
#include <stdio.h>
>>>>>>> origin/dante
#include <stdlib.h>
#include <unistd.h>
#include "cmd.h"

/* It calls getcwd(), prints its return value and then frees it. */
<<<<<<< HEAD
void	pwd(t_cmd *cmd)
=======
void	pwd(t_cmd *p)
>>>>>>> origin/dante
{
	char	*s;

	s = getcwd(NULL, 0);
<<<<<<< HEAD
		ft_fprintf(cmd->current_out, "%s\n", s);
=======
	ft_fprintf(p->current_out, "%s\n", s);
>>>>>>> origin/dante
	free(s);
}
