/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duccello <duccello@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 13:01:48 by duccello          #+#    #+#             */
/*   Updated: 2025/09/03 12:58:05 by sgaspari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "clean.h"
#include "data.h"
#include "token.h"
#include "cmd.h"
#include "list.h"
#include "libft.h"
#include "utils.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

t_cmd	*parse_cmds(char *segment, t_data *data)
{
	t_cmd	*c;

	c = malloc(sizeof(t_cmd));
	initiate_cmds(c, data, segment);
	parse(c);
	set_fds(c);
	return (c);
}

void	initiate_cmds(t_cmd *c, t_data *data, char *segment)
{
	c->data = data;
	c->tokens = tokenize(segment, data, &(c->n_tokens));
	c->argv = malloc(c->n_tokens * sizeof(char *));
	if (c->argv == NULL)
		return ;
	c->envp = create_array(data->envp);
	c->infile = NULL;
	c->outfile = NULL;
	c->heredoc = false;
	c->limiter = NULL;
	c->append = false;
	c->paths = parse_path(c->data->envp);
}

void	parse(t_cmd *c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < c->n_tokens)
	{
		if (ft_strncmp(c->tokens[i].s, "<", 2) == 0
				&& c->tokens[i].quote == false
				&& c->tokens[i].dquote == false)
			c->infile = ft_strdup(c->tokens[++i].s);
		else if (ft_strncmp(c->tokens[i].s, ">", 2) == 0
				&& c->tokens[i].quote == false
				&& c->tokens[i].dquote == false)
			c->outfile = ft_strdup(c->tokens[++i].s);
		else if (ft_strncmp(c->tokens[i].s, "<<", 3) == 0
				&& c->tokens[i].quote == false
				&& c->tokens[i].dquote == false)
		{
			c->limiter = ft_strdup(c->tokens[++i].s);
			c->heredoc = true;
		}
		else if (ft_strncmp(c->tokens[i].s, ">>", 3) == 0
				&& c->tokens[i].quote == false
				&& c->tokens[i].dquote == false)
		{
			c->outfile = ft_strdup(c->tokens[++i].s);
			c->append = true;
		}
		else
			c->argv[j++] = ft_strdup(c->tokens[i].s);
		i++;
	}
	c->argv[j] = NULL;
}

char	**parse_path(t_node *envp)
{
	char	**paths;
	char	*start;

	start = path_start(envp);
	if (!start)
		return (NULL);
	paths = ft_split(start, ':');
	return (paths);
}

char	*path_start(t_node *envp)
{
	t_node	*curr;

	curr = envp;
	while (curr != NULL)
	{
		if (ft_strncmp(curr->s, "PATH=", 5) == 0)
			return (curr->s + 5);
		curr = curr->next;
	}
	return (NULL);
}
