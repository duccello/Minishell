/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duccello <duccello@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 17:20:59 by duccello          #+#    #+#             */
/*   Updated: 2025/09/04 10:41:11 by sgaspari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "built_in.h"
#include "clean.h"
#include "cmd.h"
#include "data.h"
#include "ft_fprintf.h"
#include "list.h"
#include "segments.h"
#include "utils.h"
#include <stdbool.h>
#include <stdio.h>
#include <unistd.h>

static void	count_cmds(t_data *data);
static void	set_minishell_env(t_node **envp);

t_data	*create_data(char **envp)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	if (data == NULL)
		return (NULL);
	data->envp = create_list(envp);
	data->built_ins = create_built_ins();
	data->ret_val = 0;
	set_minishell_env(&data->envp);
	return (data);
}

bool	check_input(char *s)
{
	int	i;
	int	c;

	i = 0;
	c = 0;
	while (s[i])
	{
		if (ft_isspace(s[i]) == true)
			c++;
		i++;
	}
	if (i == c)
		return (false);
	return (true);
}

int	init_data(t_data *data, char *input)
{
	int		i;
	bool	input_correct;

	input_correct = split_segments(data, input);
	i = 0;
	if (input_correct == false)
	{
		ft_fprintf(STDERR_FILENO, "wrong input\n");
		return (1);
	}
	data->cmds = malloc(data->amount * sizeof(t_cmd *));
	if (data->cmds == NULL)
		return (1);
	i = 0;
	while (i < data->amount)
	{
		data->cmds[i] = parse_cmds(data->segments[i], data);
		i++;
	}
	count_cmds(data);
	g_flag = 0;
	return (0);
}

static void	count_cmds(t_data *data)
{
	int	i;

	i = 0;
	data->total_cmds = 0;
	data->built_cmd = 0;
	data->bins = 0;
	while (i < data->amount)
	{
		if (data->cmds[i]->argv[0] != NULL)
			data->total_cmds++;
		if (cmd_is_built_in(data->cmds[i]->argv[0], data->built_ins) == true)
			data->built_cmd++;
		i++;
	}
	data->bins = data->total_cmds - data->built_cmd;
}

static void	set_minishell_env(t_node **envp)
{
	t_node *minis;

	delete_node(envp, "SHELL", ft_strlen("SHELL"));
	minis = create_node("SHELL=minishell");
	append_node(envp, minis);
}
