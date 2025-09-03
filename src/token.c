/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaspari <sgaspari@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 12:19:19 by sgaspari          #+#    #+#             */
/*   Updated: 2025/09/03 13:20:36 by sgaspari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <readline/history.h>
#include <readline/readline.h>
#include <stdlib.h>
#include <stdio.h>
#include "cmd.h"
#include "token.h"
#include "libft.h"
#include "expand.h"

t_tok	*tokenize(char *s, t_data *data, int *n_tokens)
{
	t_tok	*tokens;
	char	*tracker;
	int		i;

	tracker = malloc(ft_strlen(s) + 1);
	i = 0;
	while (i < (int) ft_strlen(s))
		tracker[i++] = '-';
	tracker[i] = '\0';
	*n_tokens = count_tokens(s, &tracker);
	tokens = malloc(sizeof(t_tok) * (*n_tokens));
	if (tokens == NULL)
		return (NULL);
	i = 0;
	while (i < *n_tokens)
	{
		tokens[i] = populate_token(&s, &tracker);
		tokens[i].data = data;
		tokens[i].quote = false;
		tokens[i].dquote = false;
		trim_spaces(&tokens[i]);
		trim_quotes(&tokens[i]);
		expand(&tokens[i]);
		i++;
	}
	return (tokens);
}

void	trim_quotes(t_tok *token)
{
	char	*s;
	int		len;
	int		i;

	len = (int) ft_strlen(token->s);
	if ((token->s[0] == '"' && token->s[len - 1] == '"')
			|| (token->s[0] == '\'' && token->s[len - 1] == '\''))
	{
		if (token->s[0] == '\'' && token->s[len - 1] == '\'')
			token->quote = true;
		if (token->s[0] == '"' && token->s[len - 1] == '"')
			token->dquote = true;
		len -= 2;
		s = malloc(len + 1);
		if (s == NULL)
			return ;
		i = 0;
		while (i < len)
		{
			s[i] = token->s[i + 1];
			i++;
		}
		s[i] = '\0';
		token->s = ft_strdup(s);
		free(s);
	}
}

void	trim_spaces(t_tok *token)
{
	char	*s;
	int		i;
	int		j;
	int		len;

	len = ft_strlen(token->s);
	i = 0;
	while (token->s[i] == ' ' && i < len)
		i++;
	j = 0;
	while (token->s[len - 1] == ' ' && j < len)
	{
		j++;
		len--;
	}
	len = ft_strlen(token->s) - i - j;
	s = malloc(len + 1);
	if (s == NULL)
	{
		perror("malloc");
		return ;
	}
	i = 0;
	while (token->s[i] == ' ')
		i++;
	j = 0;
	while (j < len)
	{
		s[j] = token->s[i + j];
		j++;
	}
	s[j] = '\0';
	token->s = ft_strdup(s);
	free(s);
}

int		count_tokens(char *s, char **tracker)
{
	int		counter;
	bool	in_quote;
	bool	in_dquote;
	bool	in_word;
	int		i;

	in_quote = false;
	in_dquote = false;
	in_word = false;
	counter = 0;
	i = 0;
	while (s[i] != '\0' && (*tracker)[i] != '\0')
	{
		if (s[i] != ' ' && !in_word && !in_quote && !in_dquote)
		{
			counter++;
			in_word = true;
		}
		else if (s[i] == ' ' && in_word && !in_quote && !in_dquote)
		{
			(*tracker)[i] = '+';	
			in_word = false;
		}
		toggle_quotes(s[i], &in_quote, &in_dquote);
		i++;
	}
	return (counter);
}

void	toggle_quotes(char c, bool *in_quote, bool *in_dquote)
{
	if (c == '\'')
	{
		if (*in_quote == false)
			*in_quote = true;
		else
			*in_quote = false;
	}
	else if (c == '"')
	{
		if (*in_dquote == false)
			*in_dquote = true;
		else
			*in_dquote = false;
	}
}

t_tok	populate_token(char **s, char **tracker)
{
	t_tok	token;
	int		count;
	int		i;
	char	*temp;

	temp = *s;
	count = 0;
	while (**tracker != '+' && **s != '\0')
	{
		count++;
		(*s)++;
		(*tracker)++;
	}
	token.s = malloc(count + 1);
	token.quote = false;
	i = 0;
	while (i < count)
	{
		token.s[i] = temp[i];
		i++;
	}
	token.s[i] = '\0';
	(*s)++;
	(*tracker)++;
	return (token);
}
