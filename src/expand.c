/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaspari <sgaspari@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 13:30:23 by sgaspari          #+#    #+#             */
/*   Updated: 2025/08/29 15:38:14 by sgaspari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdbool.h>
#include "data.h"
#include "libft.h"
#include "list.h"
#include "token.h"
#include "expand.h"

void	expand(t_tok *token)
{
	int	i;

	if (token->quote == true)
		return ;
	i = 0;
	while (token->s[i] != '\0')
	{
		if (token->s[i] == '$' && token->s[i + 1] != '\0'
				&& ft_isspace(token->s[i + 1]) == false)
			token->s = expand_var(token);
		i++;
	}
}

char	*expand_var(t_tok *token)
{
	char	*s;
	t_node	*curr;
	int		key_len;

	key_len = (int)ft_strlen(token->s);
	curr = token->data->envp;
	while (curr != NULL)
	{
		if (ft_strncmp(curr->s, &(token->s[1]), key_len - 1) == 0)
			s = ft_strdup(&(curr->s[key_len]));
		curr = curr->next;
	}
	return (s);
}

