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

typedef struct s_container {
	nodes *pstk_a;
	nodes *pstk_b;
	int is_combine;
} t_container;

int			ft_atoi(const char *str);
nodes		*command_nodes(int *data, int argc, char **argv);
void		last_node(nodes **head, int data);
void		swap_a(t_container *stack);
void		swap_b(t_container *stack);
void		swap_s(t_container *stack);
void		rotate_a(t_container *stack);
void		rotate_b(t_container *stack);
void		rotate_r(t_container *stack);
void		r_rotate_a(t_container *stack);
void		r_rotate_b(t_container *stack);
void		r_rotate_r(t_container *stack);
void		push_a(t_container *stack);
void		push_b(t_container *stack);
void		print_content(void *content);
void		sort3(t_container *stack);
void		free_data(int *data);
void		free_nodes(nodes *head);
t_container	init (nodes *stk_a, nodes *stk_b);

#endif