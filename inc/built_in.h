/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_in.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaspari <sgaspari@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 17:57:46 by sgaspari          #+#    #+#             */
/*   Updated: 2025/09/01 12:09:21 by sgaspari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILT_IN_H
# define BUILT_IN_H

# include "cmd.h"
# include "data.h"
# include <stdbool.h>

char	**create_built_ins(void);
void	handle_built_in(t_data *data, t_cmd *cmd);
bool	cmd_is_built_in(char *s, char **built_ins);
int		cd(t_cmd *cmd);
void	pwd(void);
void	echo(t_cmd *cmd);
void	ft_export(t_cmd *cmd);
void	env(t_cmd *cmd);
void	unset(t_cmd *cmd);
void	ft_exit(t_cmd *cmd);

#endif
