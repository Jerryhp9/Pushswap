/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_rotate_b.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhor <jhor@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 00:44:53 by jhor              #+#    #+#             */
/*   Updated: 2025/05/22 00:44:53 by jhor             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

void	r_rotate_b(t_container *stack)
{
	nodes *last_node;
	nodes *second_last;

	last_node = stack->pstk_b;
	second_last = NULL;
	while (last_node->next_link != NULL)
		last_node = last_node->next_link;
	second_last = last_node->prev_link;
	if (second_last->next_link != NULL)
		second_last->next_link = NULL;
	last_node->prev_link = NULL;
	last_node->next_link = stack->pstk_b;
	stack->pstk_b->prev_link = last_node;
	stack->pstk_b = last_node;
	if (stack->is_combine)
		printf("rrb\n");
}