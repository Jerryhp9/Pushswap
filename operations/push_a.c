/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhor <jhor@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 01:04:12 by jhor              #+#    #+#             */
/*   Updated: 2025/05/22 01:04:12 by jhor             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

void	push_a(t_container *stack)
{
	t_nodes	*nodep;

	if (stack->pstk_b == NULL)
		return ;
	nodep = stack->pstk_b;
	stack->pstk_b = stack->pstk_b->next_link;
	nodep->next_link = stack->pstk_a;
	stack->pstk_a = nodep;
	stack->pstk_a->prev_link = nodep;
	if (stack->pstk_b != NULL)
		(stack->pstk_b)->prev_link = NULL;
	nodep->prev_link = NULL;
	if (stack->is_combine == 0)
		printf("pa\n");
}
