/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cheapest_move.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhor <jhor@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 18:10:55 by jhor              #+#    #+#             */
/*   Updated: 2025/05/26 18:10:55 by jhor             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

void	sort3(t_container *stack)
{
	nodes	*middle;
	nodes	*last;

	middle = stack->pstk_a->next_link;
	last = middle->next_link;
	ft_lstiter(middle, print_content);
	printf("\n");
	ft_lstiter(last, print_content);
	if (stack->pstk_a->data > middle->data && stack->pstk_a->data > last->data)
	{
		rotate_a(stack);
		if (stack->pstk_a->data > middle->data)
			swap_a(stack);
	}
	else if (stack->pstk_a->data > middle->data && stack->pstk_a->data < last->data)
		swap_a(stack);
	else if (stack->pstk_a->data < middle->data && stack->pstk_a->data > last->data)
		r_rotate_a(stack);
	else if (stack->pstk_a->data < middle->data && stack->pstk_a->data < last->data)
	{	
		swap_a(stack);
		rotate_a(stack);
	}
	printf("\n");
	ft_lstiter(stack->pstk_a, print_content);
}