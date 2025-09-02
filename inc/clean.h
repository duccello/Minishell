/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaspari <sgaspari@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 15:09:43 by sgaspari          #+#    #+#             */
/*   Updated: 2025/08/26 15:14:57 by sgaspari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLEAN_H
# define CLEAN_H

# include "data.h"

void	clean_data(t_data *p);
void	free_data(t_data *p);
void	free_cmd(t_cmd *c);
void	free_array(char **c);

#endif
