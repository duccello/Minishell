/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaspari <sgaspari@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 14:28:37 by sgaspari          #+#    #+#             */
/*   Updated: 2025/08/21 17:46:53 by sgaspari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

typedef struct s_cmd
{
	char	*path;
	char	**argv;
}	t_cmd;

typedef struct s_data
{
	char	*line;
	t_cmd	*cmd;
	pid_t	pid;
}	t_data;

t_data	*create_data(void);
t_cmd	*create_cmd(char *s);

#endif
