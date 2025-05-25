/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhor <jhor@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 19:28:22 by jhor              #+#    #+#             */
/*   Updated: 2025/05/16 19:28:22 by jhor             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

void swap_a(t_container *stack)
{
	nodes *temp;
	nodes *temp2;

	temp2 = NULL;
	temp = stack->pstk_a;
	if (!stack->pstk_a || stack->pstk_a->next_link == NULL)
		return;
	stack->pstk_a = stack->pstk_a->next_link;
	temp2 = stack->pstk_a->next_link;
	stack->pstk_a->next_link = temp;
	stack->pstk_a->prev_link = NULL;
	temp->prev_link = stack->pstk_a;
	temp->next_link = temp2;
	if (stack->is_combine == 0)
		printf("sa\n");
}
