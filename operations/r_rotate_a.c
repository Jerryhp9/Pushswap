/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_rotate_a.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhor <jhor@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 16:13:14 by jhor              #+#    #+#             */
/*   Updated: 2025/05/19 16:13:14 by jhor             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

void	r_rotate_a(t_container *stack)
{
	t_nodes	*last;
	t_nodes	*before_last;
	t_nodes	*first;

	if (!stack->pstk_a || stack->pstk_a->next_link == NULL)
		return ;
	last = stack->pstk_a;
	while (last->next_link != NULL)
		last = last->next_link;
	before_last = last->prev_link;
	before_last->next_link = NULL;
	last->prev_link = NULL;
	first = stack->pstk_a;
	last->next_link = first;
	first->prev_link = last;
	stack->pstk_a = last;
	if (stack->is_combine == 0)
		printf("rra\n");
}
