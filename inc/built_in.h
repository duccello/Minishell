/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_in.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaspari <sgaspari@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 17:57:46 by sgaspari          #+#    #+#             */
/*   Updated: 2025/08/23 13:32:28 by sgaspari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILT_IN_H
# define BUILT_IN_H

# include <stdbool.h>
# include "structs.h"

void	handle_built_in(t_data *data);
bool	cmd_is_built_in(char *s, char **built_ins);
int		cd(t_data *data);
void	pwd(void);
void	echo(t_data *data);
void	export(t_data *data);
void	env(t_data *data);
void	unset(t_data *data);

#endif
