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
#include "data.h"
#include "ft_fprintf.h"
#include <stdlib.h>
#include <unistd.h>

/* It calls getcwd(), prints its return value and then frees it. */
void	pwd(t_data *data, t_cmd *p)
{
	char	*s;

	s = getcwd(NULL, 0);
	if (data->amount > 1)
		ft_fprintf(STDOUT_FILENO, "%s\n", s);
	else
		ft_fprintf(p->current_out, "%s\n", s);
	free(s);
}
