/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaspari <sgaspari@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 10:24:45 by sgaspari          #+#    #+#             */
/*   Updated: 2025/09/04 10:38:00 by sgaspari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stdlib.h>
#include "quotes.h"

void	toggle_quotes(char c, bool *in_quote, bool *in_dquote)
{
	if (c == '\'')
	{
		if (*in_quote == false && *in_dquote == false)
			*in_quote = true;
		else if (*in_quote == true && *in_dquote == false)
			*in_quote = false;
	}
	else if (c == '"')
	{
		if (*in_dquote == false && *in_quote == false)
			*in_dquote = true;
		else if (*in_dquote == true && *in_quote == false)
			*in_dquote = false;
	}
}

bool	are_quotes_open(char *s)
{
	bool	quote;
	bool	dquote;
	int		i;

	quote = false;
	dquote = false;
	i = 0;
	while (s[i] != '\0')
	{
		toggle_quotes(s[i], &quote, &dquote);
		i++;
	}
	if (quote == true || dquote == true)
		return (true);
	return (false);
}
