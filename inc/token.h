/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaspari <sgaspari@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 11:08:49 by sgaspari          #+#    #+#             */
/*   Updated: 2025/08/29 14:58:49 by sgaspari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKEN_H
# define TOKEN_H

# include <stdbool.h>

typedef struct s_data t_data;

typedef struct s_tok
{
	t_data	*data;
	char	*s;
	bool	quote;
}	t_tok;

t_tok	*tokenize(char *s, t_data *data, int *n_tokens);
int		count_tokens(char *s, char **tracker);
void	toggle_quotes(char c, bool *in_quote, bool *in_dquote);
t_tok	populate_token(char **s, char **tracker);
void	trim_spaces(t_tok *token);
void	trim_quotes(t_tok *token);

#endif
