/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaspari <sgaspari@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 15:55:10 by sgaspari          #+#    #+#             */
/*   Updated: 2025/08/23 16:31:17 by sgaspari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <readline/readline.h>
#include <readline/history.h>
#include "structs.h"
#include "libft.h"
#include "built_in.h"
#include "binary_exec.h"
#include "banner.h"

int	main(int argc, char *argv[], char *envp[])
{
	t_data	*data;

	(void)argc;
	(void)argv;
	banner();
	data = create_data(envp);
	while (1)
	{
		data->line = readline("> ");
		if (data->line == NULL)
			break ;
		if (data->line[0] == '\0')
			;
		else
		{
			add_history(data->line);
			data->cmd = create_cmd(data->line);
			if (cmd_is_built_in(data->cmd->argv[0], data->built_ins) == true)
				handle_built_in(data);
			else
				printf("ERROR: not a minishell built-in\n"); 
		}
	}
	// clean_all(data)
	return (0);
}
