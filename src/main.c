/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaspari <sgaspari@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 15:55:10 by sgaspari          #+#    #+#             */
/*   Updated: 2025/09/01 11:36:07 by sgaspari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "banner.h"
#include "built_in.h"
#include "clean.h"
#include "data.h"
#include "exec.h"
#include "libft.h"
#include "pipes.h"
#include "signals.h"
#include <readline/history.h>
#include <readline/readline.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int	main(int argc, char *argv[], char *envp[])
{
	t_data	*data;
	char	*s;

	(void)argc;
	(void)argv;
	banner();
	handle_signals();
	data = create_data(envp);
	while (1)
	{
		g_flag = 0;
		s = readline("> ");
		if (s == NULL)
			exit(EXIT_SUCCESS); // free before
		if (s[0] == '\0')
			;
		else if (check_input(s) == 1)
		{
			add_history(s);
			init_data(data, s);
			create_pipes(data);
			exec_cmd(data->cmds, data);
			clean_data(data);
		}
	}
	return (0);
}
