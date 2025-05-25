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
	nodes *temp;
	nodes *temp2;

	temp2 = NULL;
	temp = stack->pstk_b;
	while (temp->next_link != NULL)
		temp = temp->next_link;
	if (stack->pstk_b->next_link != NULL)
		stack->pstk_b = stack->pstk_b->next_link;
	temp2 = stack->pstk_b->prev_link;
	temp2->prev_link = temp;
	temp2->next_link = NULL;
	temp->next_link = temp2;
	stack->pstk_b->prev_link = NULL;
	if(stack->is_combine == 0)
		printf("rb\n");
}