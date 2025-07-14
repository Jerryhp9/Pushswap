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

void	swap_a(t_container *stack)
{
	t_nodes	*first;
	t_nodes	*second;
	t_nodes	*third;

	second = NULL;
	third = NULL;
	if (!stack->pstk_a || stack->pstk_a->next_link == NULL)
		return ;
	first = stack->pstk_a->next_link;
	second = stack->pstk_a;
	if (first->next_link != NULL)
		third = first->next_link;
	first->next_link = second;
	second->prev_link = first;
	if (third != NULL)
	{
		second->next_link = third;
		third->prev_link = second;
	}
	else
		second->next_link = NULL;
	first->prev_link = NULL;
	stack->pstk_a = first;
	if (stack->is_combine == 0)
		printf("sa\n");
}
