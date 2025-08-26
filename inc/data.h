#ifndef DATA_H
# define DATA_H

#include "built_in.h"
#include "list.h"
#include "cmd.h"
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
}			t_data;


t_data		*create_data(char *s, char **envp);
void		free_array(char **c);
void		free_data(t_data *p);

#endif