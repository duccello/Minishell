/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaspari <sgaspari@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 15:05:43 by sgaspari          #+#    #+#             */
/*   Updated: 2025/08/26 15:05:56 by sgaspari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

#include "cmd.h"

char	**parse_path(char **envp);
char	*joint_path(char *cmd, char **paths, t_cmd *c);
char	*path_start(char **envp);
t_cmd	*parse_cmds(char *segment, char **envp);

#endif
