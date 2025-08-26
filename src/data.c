/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_data.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duccello <duccello@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 17:20:59 by duccello          #+#    #+#             */
/*   Updated: 2025/08/26 11:53:47 by duccello         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "data.h"
#include "cmd.h"

t_data	*create_data(char *input, char **envp)
{
	t_data	*p;
	int		i;

	i = 0;
	p = malloc(sizeof(t_data));
	if (p == NULL)
		return (NULL);
	p->segments = ft_split(input, '|');
	p->amount = char_counter(input, '|') + 1;
	p->cmds = malloc(p->amount * sizeof(t_cmd *));
	p->envp = create_list(envp);
	if (p->cmds == NULL)
	{
		free_everything(p);
		return (NULL);
	}
	p->built_ins = create_built_ins();
	while (i < p->amount)
	{
		p->cmds[i] = parse_cmds(p->segments[i], envp);
		i++;
	}
	p->bins = count_bins(cmds, amount);
	return (p);
}
