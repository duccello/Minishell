/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaspari <sgaspari@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 15:12:53 by sgaspari          #+#    #+#             */
/*   Updated: 2025/08/25 18:56:54 by sgaspari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <readline/readline.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "signal_handler.h"

volatile sig_atomic_t	g_flag;

void	handle_signals(void)
{
	struct sigaction	sa;

	sa.sa_handler = sig_handler;
	sigaction(SIGINT, &sa, NULL);
	sigaction(SIGQUIT, &sa, NULL);
}

void	sig_handler(int sig)
{
	if (sig == 2)
	{
		if (g_flag == 1)
			exit (0);
 		else
		{
			write(1, "\n> ", 3);
		}
	}
	if (sig == 3)
	{
		readline("> ");
		;
	}
}

