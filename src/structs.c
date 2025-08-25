/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaspari <sgaspari@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 14:53:52 by sgaspari          #+#    #+#             */
/*   Updated: 2025/08/25 12:05:27 by sgaspari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "structs.h"
#include "libft.h"
#include "macros.h"

/* It creates and dynamically allocates an array containing
 * the built-in commands strings. */
char	**create_built_ins(void)
{
	char	**arr;

	arr = malloc(sizeof(char *) * NUM_BUILT_INS + 1);
	if (arr == NULL)
		return (NULL);
	arr[ECHO] = ft_strdup("echo");
	arr[CD] = ft_strdup("cd");
	arr[PWD] = ft_strdup("pwd");
	arr[EXPORT] = ft_strdup("export");
	arr[UNSET] = ft_strdup("unset");
	arr[ENV] = ft_strdup("env");
	arr[EXIT] = ft_strdup("exit");
	arr[NUM_BUILT_INS] = NULL;
	return (arr);
}

