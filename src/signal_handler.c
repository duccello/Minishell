/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaspari <sgaspari@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 15:12:53 by sgaspari          #+#    #+#             */
/*   Updated: 2025/08/25 15:43:40 by sgaspari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdio.h>
#include <stdlib.h>

volatile sig_atomic_t	g_flag;

void	sig_handler(int sig)
{
	(void)sig;
	if (g_flag == 1)
		exit (0);
}
