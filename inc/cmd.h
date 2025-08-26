/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duccello <duccello@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 16:07:48 by duccello          #+#    #+#             */
/*   Updated: 2025/08/25 15:20:19 by sgaspari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CMD_H
# define CMD_H

# include "data.h"
# include "get_next_line.h"
# include "libft.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <unistd.h>

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
