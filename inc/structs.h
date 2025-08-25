/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaspari <sgaspari@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 14:28:37 by sgaspari          #+#    #+#             */
/*   Updated: 2025/08/22 15:27:18 by sgaspari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# include <unistd.h>
# include "list.h"

typedef struct s_cmd
{
	char	*name;
	char	*path;
	char	**argv;
}	t_cmd;

typedef struct s_data
{
	char	*line;
	t_cmd	*cmd;
	t_node	*envp;
	char	**built_ins;
	pid_t	pid;
}	t_data;

t_data	*create_data(char **envp);
t_node	*create_env_list(char **envp);
char	**create_built_ins(void);
t_cmd	*create_cmd(char *s);

#endif
