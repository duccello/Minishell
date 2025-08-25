/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaspari <sgaspari@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 15:55:10 by sgaspari          #+#    #+#             */
/*   Updated: 2025/08/25 11:35:26 by sgaspari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "banner.h"
#include "binary_exec.h"
#include "built_in.h"
#include "libft.h"
#include "pipex.h"
#include "structs.h"
#include <readline/history.h>
#include <readline/readline.h>
#include <stdlib.h>

int	main(int argc, char *argv[], char *envp[])
{
	t_data	*data;
	char	*s;

	(void)argc;
	(void)argv;
	banner();
	while (1)
	{
		s = readline("> ");
		if (s == NULL)
			break ;
		if (s[0] == '\0')
			;
		else
		{
			add_history(s);
			data = create_data(s, envp);
		}
	}
	// clean_all(data)
	return (0);
}
