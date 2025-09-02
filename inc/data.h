#ifndef DATA_H
# define DATA_H
# define WRITE 1
# define READ 0
# include "libft.h"
# include "list.h"
# include <stdlib.h>

typedef struct s_cmd	t_cmd;

typedef struct s_data
{
	char				**segments;
	t_cmd				**cmds;
	char				**built_ins;
	int 				(*pipfd)[2];
	t_node				*envp;
	int					amount;
	int					bins;
	int					built_cmd;
	int					total_cmds;
	int					ret_val;
}						t_data;

t_data					*create_data(char **envp);
void					init_data(t_data *data, char *s);

#endif
