/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_b.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhor <jhor@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 00:28:46 by jhor              #+#    #+#             */
/*   Updated: 2025/05/22 00:28:46 by jhor             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

void	rotate_b(t_container *stack)
{
	t_nodes	*last;
	t_nodes	*move;

	move = NULL;
	last = stack->pstk_b;
	if (!stack->pstk_b || stack->pstk_b->next_link == NULL)
		return ;
	while (last->next_link != NULL)
		last = last->next_link;
	move = stack->pstk_b;
	stack->pstk_b = stack->pstk_b->next_link;
	move->prev_link = last;
	move->next_link = NULL;
	last->next_link = move;
	stack->pstk_b->prev_link = NULL;
	if (stack->is_combine == 0)
		printf("rb\n");
}
