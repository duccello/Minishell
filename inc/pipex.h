/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duccello <duccello@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 16:07:48 by duccello          #+#    #+#             */
/*   Updated: 2025/08/25 12:15:18 by sgaspari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# define READ 0
# define WRITE 1
# define FALSE 0
# define TRUE 1
# include "get_next_line.h"
# include "libft.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <unistd.h>

typedef struct s_pipe
{
	char	*infile;
	int		in_fd;
	char	*outfile;
	int		out_fd;
	int		heredoc;
	char	*limiter;
	int		append;
	char	**cmd;
	int		ind;
	char	**paths;
	char	**envp;
}			t_pipe;

typedef struct s_data
{
	char	**segments;
	t_pipe	**pipes;
	char	**built_ins;
	int		amount;
}			t_data;

char		**parse_path(char **envp);
t_pipe		*parse_pipes(char *segment, char **envp);
char		*joint_path(char *cmd, char **paths, t_pipe *c);
char		*path_start(char **envp);
void		free_com(t_pipe *c);
void		initiate_cmds(t_pipe *c, char **envp, char *segment);
void		set_fds(t_pipe *c);
int			count_things(char *input, char c);
void		free_array(char **c);
t_data		*create_data(char *s, char **envp);
void		free_everything(t_data *p);


#endif
