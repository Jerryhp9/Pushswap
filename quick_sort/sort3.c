/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cheapest_move.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+        
	+:+     */
/*   By: jhor <jhor@student.42kl.edu.my>            +#+  +:+      
	+#+        */
/*                                                +#+#+#+#+#+  
	+#+           */
/*   Created: 2025/05/26 18:10:55 by jhor              #+#    #+#             */
/*   Updated: 2025/05/26 18:10:55 by jhor             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

void	extra_sort3(t_container *stack)
{
	swap_a(stack);
	rotate_a(stack);
	swap_a(stack);
	r_rotate_a(stack);
	swap_a(stack);
}

void	diff_sort3(t_container *stack)
{
	swap_a(stack);
	rotate_a(stack);
	swap_a(stack);
	r_rotate_a(stack);
}

void	n_sort3(t_container *stack)
{
	nodes	*middle;
	nodes	*last;

	middle = stack->pstk_a->next_link;
	last = middle->next_link;
	if (stack->pstk_a->data < middle->data && middle->data < last->data)
		return ;
	else if (stack->pstk_a->data > middle->data
		&& stack->pstk_a->data > last->data)
	{
		if (middle->data > last->data)
			(rotate_a(stack), swap_a(stack));
		else
			rotate_a(stack);
	}
	else if (stack->pstk_a->data > middle->data
		&& stack->pstk_a->data < last->data)
		swap_a(stack);
	else if (stack->pstk_a->data < middle->data
		&& stack->pstk_a->data > last->data)
		r_rotate_a(stack);
	else if (stack->pstk_a->data < middle->data
		&& stack->pstk_a->data < last->data)
		(swap_a(stack), rotate_a(stack));
}

void	sort3(t_container *stack)
{
	nodes	*middle;
	nodes	*last;

	middle = stack->pstk_a->next_link;
	last = middle->next_link;
	if (stack->pstk_a->data < middle->data && middle->data < last->data)
		return ;
	else if (stack->pstk_a->data < middle->data
		&& stack->pstk_a->data < last->data)
		(rotate_a(stack), swap_a(stack), r_rotate_a(stack));
	else if (stack->pstk_a->data < middle->data
		&& stack->pstk_a->data > last->data)
		(rotate_a(stack), swap_a(stack), r_rotate_a(stack), swap_a(stack));
	else if (stack->pstk_a->data > middle->data
		&& stack->pstk_a->data > last->data)
	{
		if (middle->data > last->data)
			extra_sort3(stack);
		else
			diff_sort3(stack);
	}
	else if (stack->pstk_a->data > middle->data
		&& stack->pstk_a->data < last->data)
		swap_a(stack);
}
