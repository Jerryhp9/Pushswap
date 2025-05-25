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
	nodes	*temp;
	nodes	*temp2;

	temp = stack->pstk_a;
	while (temp->next_link != NULL)
		temp = temp->next_link;
	temp2 = temp->prev_link;
	stack->pstk_a->prev_link = temp;
	temp->next_link = stack->pstk_a;
	temp->prev_link = NULL;
	temp2->next_link = NULL;
	stack->pstk_a = temp;
	if (stack->is_combine == 0)
		printf("rra\n");
}
