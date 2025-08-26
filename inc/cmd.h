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
}			t_cmd;

void		initiate_cmds(t_cmd *c, char **envp, char *segment);
t_cmd		*parse_cmds(char *segment, char **envp);
char		*path_start(char **envp);
char		**parse_path(char **envp);
char		*joint_path(char *cmd, char **paths, t_cmd *c);
void		set_fds(t_cmd *c);
int			char_counter(char *input, char c);
void		execute_cmds(t_cmd **cmds, t_data *data);
void		free_cmd(t_cmd *c);

#endif
