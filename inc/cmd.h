/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duccello <duccello@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 16:07:48 by duccello          #+#    #+#             */
/*   Updated: 2025/09/04 13:45:59 by sgaspari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CMD_H
# define CMD_H

typedef struct s_data	t_data;
typedef struct s_tok	t_tok;
typedef struct s_node	t_node;

typedef struct s_cmd
{
	t_data	*data;
	t_tok	*tokens;
	char	**paths;
	char	**argv;
	char	**envp;
	char	*infile;
	char	*outfile;
	char	*limiter;
	int		in_fd;
	int		out_fd;
	int		heredoc;
	int		append;
	int		current_in;
	int		current_out;
	int		n_tokens;
}			t_cmd;

t_cmd		*parse_cmds(char *segment, t_data *data);
void		initiate_cmds(t_cmd *c, t_data *data, char *segment);
void		parse(t_cmd *c);
void		handle_heredoc(char *s, t_cmd *c);
void		handle_append(char *s, t_cmd *c);
char		**parse_path(t_node *envp);
char		*path_start(t_node *envp);
void		set_fds(t_cmd *c);

#endif
