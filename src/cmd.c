/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duccello <duccello@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 13:01:48 by duccello          #+#    #+#             */
/*   Updated: 2025/09/04 17:46:05 by sgaspari         ###   ########.fr       */
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
	c->n_redirectors = count_redirectors(c->tokens); //to implement
	c->argv = malloc((c->n_tokens - c->redirectors) * sizeof(char *));
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
		if (c->tokens[i].quote == true || c->tokens[i].dquote == true)
			c->argv[j++] = ft_strdup(c->tokens[i].s);
		else if (ft_strncmp(c->tokens[i].s, "<", 2) == 0)
			c->infile = ft_strdup(c->tokens[++i].s);
		else if (ft_strncmp(c->tokens[i].s, ">", 2) == 0)
			c->outfile = ft_strdup(c->tokens[++i].s);
		else if (ft_strncmp(c->tokens[i].s, "<<", 3) == 0)
			handle_heredoc(c->tokens[++i].s, c);
		else if (ft_strncmp(c->tokens[i].s, ">>", 3) == 0)
			handle_append(c->tokens[++i].s, c);
		else
			c->argv[j++] = ft_strdup(c->tokens[i].s);
		i++;
	}
	c->argv[j] = NULL;
}

void	handle_heredoc(char *s, t_cmd *c)
{
	c->limiter = ft_strdup(s);
	c->heredoc = true;
}

void	handle_append(char *s, t_cmd *c)
{
	c->outfile = ft_strdup(s);
	c->append = true;
}
