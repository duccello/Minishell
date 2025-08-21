/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaspari <sgaspari@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 17:49:22 by sgaspari          #+#    #+#             */
/*   Updated: 2025/08/21 18:24:21 by sgaspari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include "structs.h"

void	cd(t_data *data)
{
	char	*cwd;

	if (data->cmd->argv[1][0] == '/')
		chdir(data->cmd->argv[1]);
	else
	{
		cwd = getcwd(NULL, 0);
		printf("%s\n", cwd);
	}
}
