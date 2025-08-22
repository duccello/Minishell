/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaspari <sgaspari@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 15:55:10 by sgaspari          #+#    #+#             */
/*   Updated: 2025/08/22 10:01:43 by sgaspari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <sys/wait.h>
#include "structs.h"
#include "libft.h"
#include "cd.h"

int	main(int argc, char *argv[], char *envp[])
{
	t_data	*data;

	(void)argc;
	(void)argv;
	data = create_data();
	while (1)
	{
		data->line = readline(NULL);
		if (ft_strncmp(data->line, "exit", ft_strlen(data->line)) == 0)
			break ;
		data->cmd = create_cmd(data->line);
		if (ft_strncmp(data->cmd->argv[0], "cd",
					ft_strlen(data->cmd->argv[0])) == 0)
			cd(data);
		else
		{
			data->pid = fork();
			if (data->pid == -1)
			{
				perror("fork");
				return (1);
			}
			if (data->pid == 0)
				execve(data->cmd->path, data->cmd->argv, envp);
			else
				wait(NULL);
		}
	}
	return (0);
}
