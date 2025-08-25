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

#ifndef PIPEX_H
# define PIPEX_H

# include "get_next_line.h"
# include "libft.h"
# include "list.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <unistd.h>

typedef struct s_cmd
{
	char	*infile;
	int		in_fd;
	char	*outfile;
	int		out_fd;
	int		heredoc;
	char	*limiter;
	int		append;
	char	**argv;
	int		ind;
	char	**paths;
	char	**envp;
	int		current_in;
	int		current_out;
}			t_cmd;

typedef struct s_data
{
	char	**segments;
	t_cmd	**cmds;
	char	**built_ins;
	int		amount;
	t_node	*envp;
}			t_data;

char		**parse_path(char **envp);
t_cmd		*parse_cmds(char *segment, char **envp);
char		*joint_path(char *cmd, char **paths, t_cmd *c);
char		*path_start(char **envp);
void		free_cmd(t_cmd *c);
void		initiate_cmds(t_cmd *c, char **envp, char *segment);
void		set_fds(t_cmd *c);
int			char_counter(char *input, char c);
void		free_array(char **c);
t_data		*create_data(char *s, char **envp);
void		free_everything(t_data *p);
void		pipex(t_cmd **cmds, t_data *data, int i);

#endif
