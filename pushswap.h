/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhor <jhor@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 16:13:35 by jhor              #+#    #+#             */
/*   Updated: 2025/05/12 16:13:35 by jhor             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
#define PUSHSWAP_H

#include <stdio.h>
#include <stdlib.h>
#include "Libft/libft.h"

int		ft_atoi(const char *str);
nodes	*command_nodes(int *data, int argc, char **argv);
nodes	*swap_a(nodes *head_a);
nodes	*swap_b(nodes *head_b);
void	swap_s(nodes **head_a, nodes **head_b);
nodes	*rotate_a(nodes *head);
nodes	*rotate_b(nodes *head_b);
nodes	*r_rotate_a(nodes *head);
nodes	*r_rotate_b(nodes *head_b);
void	r_rotate_r(nodes **head_a, nodes **head_b);
void	push_a(nodes **head_a, nodes **head_b);
void	push_b(nodes **head_a, nodes **head_b);
void	print_content(void *content);
void	free_data(int *data);
void	free_nodes(nodes *head);




#endif