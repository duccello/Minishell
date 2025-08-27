/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaspari <sgaspari@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 15:37:40 by sgaspari          #+#    #+#             */
/*   Updated: 2025/08/26 15:45:33 by sgaspari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXEC_H
# define EXEC_H

# include "cmd.h"
# include "data.h"

void	exec_cmd(t_cmd **cmds, t_data *data);
void	assign_in_out(t_cmd **cmds, t_data *data);
void	wait_pids(int *pid, int j);
void	allocate_pids(t_data *data, int **pid);

#endif
