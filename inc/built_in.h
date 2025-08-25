/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_in.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaspari <sgaspari@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 17:57:46 by sgaspari          #+#    #+#             */
/*   Updated: 2025/08/25 12:16:26 by sgaspari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILT_IN_H
# define BUILT_IN_H

# include "pipex.h"
# include "structs.h"
# include <stdbool.h>

void	handle_built_in(t_data *data, t_pipe *p);
bool	cmd_is_built_in(char *s, char **built_ins);
int		cd(t_pipe *p);
void	pwd(void);
void	echo(t_pipe *p);
void	export(t_data *data, t_pipe *p);
void	env(t_data *data);
void	unset(t_data *data, t_pipe *p);

#endif
