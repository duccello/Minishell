#ifndef UTILS_H
# define UTILS_H

# include "data.h"
# include <stdlib.h>

void	free_array(char **c);
void	free_data(t_data *p);
int		char_counter(char *input, char c);
void	free_cmd(t_cmd *c);

#endif