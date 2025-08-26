/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaspari <sgaspari@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 15:06:26 by sgaspari          #+#    #+#             */
/*   Updated: 2025/08/26 15:06:36 by sgaspari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "data.h"

void	free_array(char **c);
void	free_data(t_data *p);
int		char_counter(char *input, char c);
void	free_cmd(t_cmd *c);
void	free_everything(t_data *p);

#endif
