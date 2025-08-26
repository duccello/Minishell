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

#include "data.h"
#include "cmd.h"
#include "parse.h"
#include <stdbool.h>
#include "built_in.h"
#include "clean.h"
#include "utils.h"

int	count_bins(t_data *data)
{
	int	i;
	int	c;

	i = 0;
	c = 0;
	while (i < data->amount)
	{
		if (cmd_is_built_in(data->cmds[i]->argv[0], data->built_ins) == true)
			c++;
		i++;
	}
	return (data->amount - c);
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
	data->bins = count_bins(data);
	return (data);
}
