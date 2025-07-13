/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_top3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhor <jhor@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 15:39:54 by jhor              #+#    #+#             */
/*   Updated: 2025/06/13 15:39:54 by jhor             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

void	sender(t_container *stack, t_chunk *chunk)
{
	while (chunk->size != 0)
	{
		if (chunk->location == BOTTOM_A)
		{
			r_rotate_a(stack);
		}
		else if (chunk->location == TOP_B)
		{
			push_a(stack);
			stack->a_counter++;
			stack->b_counter--;
		}
		else if (chunk->location == BOTTOM_B)
		{
			if (stack->pstk_b->next_link != NULL)
				r_rotate_b(stack);
			push_a(stack);
			stack->a_counter++;
			stack->b_counter--;
		}
		chunk->size--;
	}
}

void	send_top_sort(t_container *stack, t_chunk *chunk)
{
	nodes *temp;
	nodes *temp2;

	temp = NULL;
	temp2 = NULL;
	if (chunk->size == 3 && chunk->location != TOP_A)
	{
		sender(stack, chunk);
		sort3(stack); //TODO: SHORTEN THE LINES WITH A FUNCTION TO HANDLE LOCATION SWAPPING AND SORT3
	}
	else if (chunk->size == 2)
	{
		sender(stack, chunk);
		chunk->location = TOP_A;
		temp = find_start_node(stack, chunk);
		temp2 = temp->next_link;
		if (temp->data > temp2->data && chunk->location == TOP_A)
			swap_a(stack);
	}
	else if (chunk->size == 1 && chunk->location != TOP_A)
		sender(stack, chunk);
}
