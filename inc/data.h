/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaspari <sgaspari@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 10:24:54 by sgaspari          #+#    #+#             */
/*   Updated: 2025/09/03 10:25:08 by sgaspari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_H
# define DATA_H

# include "libft.h"
# include "list.h"
# include <stdlib.h>
# include <stdbool.h>

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
bool					check_input(char *s);

#endif
