#ifndef DATA_H
# define DATA_H

# include "built_in.h"
# include "cmd.h"
# include "libft.h"
# include "list.h"
# include <stdlib.h>

typedef struct s_data
{
	char	**segments;
	t_cmd	**cmds;
	char	**built_ins;
	t_node	*envp;
	int		amount;
	int		**pipfd;
    int     c_bins;
    int     c_built_in;
}			t_data;

t_data		*create_data(char *s, char **envp);
t_cmd		*parse_cmds(char *segment, char **envp);
char		*path_start(char **envp);
char		**parse_path(char **envp);
char		*joint_path(char *cmd, char **paths, t_cmd *c);

#endif