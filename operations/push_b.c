/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhor <jhor@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 17:17:45 by jhor              #+#    #+#             */
/*   Updated: 2025/05/19 17:17:45 by jhor             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

void	push_b(t_container *stack)
{
	t_nodes	*nodep;

	if (stack->pstk_a == NULL)
		return ;
	nodep = stack->pstk_a;
	stack->pstk_a = stack->pstk_a->next_link;
	nodep->next_link = stack->pstk_b;
	stack->pstk_b = nodep;
	stack->pstk_b->prev_link = nodep;
	if (stack->pstk_a != NULL)
		stack->pstk_a->prev_link = NULL;
	nodep->prev_link = NULL;
	if (stack->is_combine == 0)
		printf("pb\n");
}
