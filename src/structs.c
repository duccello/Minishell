/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaspari <sgaspari@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 14:53:52 by sgaspari          #+#    #+#             */
/*   Updated: 2025/08/21 17:42:37 by sgaspari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "structs.h"
#include "libft.h"

/* It creates and dynamically allocates the main structure */
t_data	*create_data(void)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	if (data == NULL)
		return (NULL);
	return (data);
}
/* It creates and dynamically allocates the structure containing
 * the path of the command and the argument vector */
t_cmd	*create_cmd(char *s)
{
	t_cmd	*cmd;

	cmd = malloc(sizeof(t_cmd));
	if (cmd == NULL)
		return (NULL);
	cmd->argv = ft_split(s, ' ');
	cmd->path = ft_strjoin("/bin/", cmd->argv[0]);
	return (cmd);
}
