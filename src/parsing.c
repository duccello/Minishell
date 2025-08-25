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

#include "pipex.h"

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

void	norminette_parse(char **chunks, t_pipe *c)
{
	int	i;

	i = 0;
	while (chunks[i])
	{
		if (ft_strncmp(chunks[i], "<", 2) == 0)
			c->infile = ft_strdup(chunks[++i]);
		else if (ft_strncmp(chunks[i], ">", 2) == 0)
			c->outfile = ft_strdup(chunks[++i]);
		else if (ft_strncmp(chunks[i], "<<", 3) == 0)
		{
			c->limiter = ft_strdup(chunks[++i]);
			c->heredoc = TRUE;
		}
		else if (ft_strncmp(chunks[i], ">>", 3) == 0)
		{
			c->outfile = ft_strdup(chunks[++i]);
			c->append = TRUE;
		}
		else
			c->cmd[c->ind++] = ft_strtrim(chunks[i], "\"\'");
		i++;
	}
	c->cmd[c->ind] = NULL;
}

t_pipe	*parse_pipes(char *segment, char **envp)
{
	t_pipe	*c;
	char	**chunks;

	chunks = ft_split(segment, ' ');
	c = malloc(sizeof(t_pipe));
	initiate_cmds(c, envp, segment);
	norminette_parse(chunks, c);
	free_array(chunks);
	return (c);
}

char	*joint_path(char *cmd, char **paths, t_pipe *c)
{
	char	*tmp;
	char	*full;
	int		i;

	i = 0;
	if (cmd == NULL)
	{
		free_com(c);
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
	free_com(c);
	unlink(c->outfile);
	perror("access");
	return (NULL);
}
