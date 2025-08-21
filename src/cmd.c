/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaspari <sgaspari@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 14:53:52 by sgaspari          #+#    #+#             */
/*   Updated: 2025/08/21 15:25:26 by sgaspari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "structs.h"
#include "libft.h"

/* It creates and dynamically allocates the structure containing
 * the path of the command and the argument vector */
t_cmd	*create_cmd(char *s)
{
	t_cmd	*cmd;

	cmd = malloc(sizeof(t_cmd));
	if (cmd == NULL)
		return (NULL);
	cmd->path = ft_strjoin("/bin/", s);
	cmd->argv = ft_split(s, ' ');
	return (cmd);
}
