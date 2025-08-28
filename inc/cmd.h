/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duccello <duccello@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 16:07:48 by duccello          #+#    #+#             */
/*   Updated: 2025/08/26 14:57:30 by sgaspari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CMD_H
# define CMD_H

# include "data.h"

typedef struct s_cmd
{
	char	**paths;
	char	**envp;
	char	**argv;
	char	*infile;
	char	*outfile;
	char	*limiter;
	int		in_fd;
	int		out_fd;
	int		heredoc;
	int		append;
	int		current_in;
	int		current_out;
}			t_cmd;

void		execute_cmds(t_data *data);
void		set_fds(t_cmd *c);
void		initiate_cmds(t_cmd *c, char **envp, char *segment);

#endif
