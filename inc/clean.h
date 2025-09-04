/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaspari <sgaspari@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 15:09:43 by sgaspari          #+#    #+#             */
/*   Updated: 2025/09/04 17:23:54 by sgaspari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLEAN_H
# define CLEAN_H

typedef struct s_data t_data;
typedef struct s_cmd t_cmd;
typedef struct s_node t_node;

void	clean_data(t_data *p);
void	clean(t_data *p);
void	free_list(t_node *list);
void	free_cmd(t_cmd *c);
void	free_array(char **c);

#endif
