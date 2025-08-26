#ifndef PARSING_H
# define PARSING_H

#include "data.h"
# include "libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <unistd.h>

char	**parse_path(char **envp);
char	*joint_path(char *cmd, char **paths, t_cmd *c);
char	*path_start(char **envp);
t_cmd	*parse_cmds(char *segment, char **envp);

#endif