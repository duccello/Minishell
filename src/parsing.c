/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duccello <duccello@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 13:01:48 by duccello          #+#    #+#             */
/*   Updated: 2025/08/25 11:02:46 by sgaspari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"
#include <stdbool.h>
#include "data.h"
#include "cmd.h"
#include "utils.h"

char	*path_start(char **envp)
{
	int	i;

	i = 0;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
			return ((envp[i] + 5));
		i++;
	}
	return (NULL);
}

char	**parse_path(char **envp)
{
	char	**paths;
	char	*start;

	start = path_start(envp);
	if (!start)
		return (NULL);
	paths = ft_split(start, ':');
	return (paths);
}

void	norminette_parse(char **chunks, t_cmd *c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (chunks[i])
	{
		if (ft_strncmp(chunks[i], "<", 2) == 0)
			c->infile = ft_strdup(chunks[++i]);
		else if (ft_strncmp(chunks[i], ">", 2) == 0)
			c->outfile = ft_strdup(chunks[++i]);
		else if (ft_strncmp(chunks[i], "<<", 3) == 0)
		{
			c->limiter = ft_strdup(chunks[++i]);
			c->heredoc = true;
		}
		else if (ft_strncmp(chunks[i], ">>", 3) == 0)
		{
			c->outfile = ft_strdup(chunks[++i]);
			c->append = true;
		}
		else
			c->argv[j++] = ft_strdup(chunks[i++]);
	}
	c->argv[j] = NULL;
}

void	initiate_cmds(t_cmd *c, char **envp, char *segment)
{
	c->infile = NULL;
	c->outfile = NULL;
	c->heredoc = 0;
	c->limiter = NULL;
	c->append = 0;
	c->argv = malloc((char_counter(segment, ' ') + 1) * sizeof(char *));
	c->paths = parse_path(envp);
	c->envp = envp;
}

t_cmd	*parse_cmds(char *segment, char **envp)
{
	t_cmd	*c;
	char	**chunks;

	chunks = ft_split(segment, ' ');
	c = malloc(sizeof(t_cmd));
	initiate_cmds(c, envp, segment);
	norminette_parse(chunks, c);
	set_fds(c);
	free_array(chunks);
	return (c);
}

char	*joint_path(char *cmd, char **paths, t_cmd *c)
{
	char	*tmp;
	char	*full;
	int		i;

	i = 0;
	if (cmd == NULL)
	{
		free_cmd(c);
		return (NULL);
	}
	if (ft_strchr(cmd, '/'))
		return (ft_strdup(cmd));
	while (paths[i])
	{
		tmp = ft_strjoin(paths[i++], "/");
		full = ft_strjoin(tmp, cmd);
		free(tmp);
		if (access(full, X_OK) == 0)
			return (full);
		free(full);
	}
	free_cmd(c);
	unlink(c->outfile);
	perror("access");
	return (NULL);
}
