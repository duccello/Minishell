/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bin.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaspari <sgaspari@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 15:34:49 by sgaspari          #+#    #+#             */
/*   Updated: 2025/08/26 15:35:59 by sgaspari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BIN_H
# define BIN_H

# include "cmd.h"

int		exec_binary(int in, int out, char **argv, t_cmd *c);
char	*join_path(char *cmd, char **paths, t_cmd *c);

#endif
