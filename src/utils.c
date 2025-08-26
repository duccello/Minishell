/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duccello <duccello@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 17:08:42 by duccello          #+#    #+#             */
/*   Updated: 2025/08/26 12:36:48 by sgaspari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	char_counter(char *input, char c)
{
	int	i;
	int	amount;

	i = 0;
	amount = 0;
	while (input[i])
	{
		if (input[i] == c)
			amount++;
		i++;
	}
	return (amount);
}


