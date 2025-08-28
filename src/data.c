/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duccello <duccello@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 17:20:59 by duccello          #+#    #+#             */
/*   Updated: 2025/08/26 15:14:44 by sgaspari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "built_in.h"
#include "clean.h"
#include "cmd.h"
#include "data.h"
#include "parse.h"
#include "utils.h"
#include <stdbool.h>

void	count_cmds(t_data *data)
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

t_data	*create_data(char *input, char **envp)
{
	t_data	*data;
	int		i;

	i = 0;
	data = malloc(sizeof(t_data));
	if (data == NULL)
		return (NULL);
	data->segments = ft_split(input, '|');
	data->amount = char_counter(input, '|') + 1;
	data->cmds = malloc(data->amount * sizeof(t_cmd *));
	data->envp = create_list(envp);
	if (data->cmds == NULL)
	{
		free_everything(data);
		return (NULL);
	}
	data->built_ins = create_built_ins();
	while (i < data->amount)
	{
		data->cmds[i] = parse_cmds(data->segments[i], envp);
		i++;
	}
	count_cmds(data);
	return (data);
}
