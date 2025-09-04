/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   segments.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaspari <sgaspari@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 10:22:05 by sgaspari          #+#    #+#             */
/*   Updated: 2025/09/04 10:38:29 by sgaspari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data.h"
#include "segments.h"
#include "quotes.h"
#include "token.h"
#include <stdbool.h>
#include <stdlib.h>

int		count_segments(char *s);
char	*cut_segments(char *s, int *p);

bool	split_segments(t_data *data, char *s)
{
	int		count;
	char	*temp;
	int		p;

	data->amount = count_segments(s) + 1;
	data->segments = (char **)malloc((data->amount + 1) * sizeof(char *));
	if (!data->segments)
		return (false);
	p = 0;
	count = 0;
	while (count < data->amount)
	{
		temp = cut_segments(s, &p);
		data->segments[count] = temp;
		if (are_quotes_open(data->segments[count]) == true)
			return (false);
		count++;
	}
	data->segments[count] = NULL;
	return (true);
}

char	*cut_segments(char *s, int *p)
{
	char	*temp;
	bool	quote;
	bool	dquote;
	int		start;
	int		len;

	len = 0;
	start = *p;
	quote = false;
	dquote = false;
	while (s[*p])
	{
		toggle_quotes(s[*p], &quote, &dquote);
		if (s[*p] == '|' && quote == false && dquote == false)
		{
			(*p)++;
			break ;
		}
		len++;
		(*p)++;
	}
	temp = (char *)malloc((len + 1) * sizeof(char));
	ft_strlcpy(temp, &s[start], len + 1);
	return (temp);
}

int	count_segments(char *s)
{
	int		i;
	bool	quote;
	bool	dquote;
	int		counter;

	quote = false;
	dquote = false;
	counter = 0;
	i = 0;
	while (s[i])
	{
		toggle_quotes(s[i], &quote, &dquote);
		if (s[i] == '|' && quote == false && dquote == false)
			counter++;
		i++;
	}
	return (counter);
}
