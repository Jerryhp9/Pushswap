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
			// chunk->location = TOP_A;
		}
		else if (chunk->location == TOP_B)
		{
			push_a(stack);
			stack->a_counter++;
			stack->b_counter--;
			// chunk->location = TOP_A;
		}
		else if (chunk->location == BOTTOM_B)
		{
			if (stack->pstk_b->next_link != NULL)
				r_rotate_b(stack);
			push_a(stack);
			stack->a_counter++;
			stack->b_counter--;
			// chunk->location = TOP_A;
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
		// printf("head of stack a is %d\n", temp->data); //! commented out
		// printf("second node of stack a is %d\n", temp2->data);
		// ft_lstiter(stack->pstk_a, print_content); //! what are the head node and second node
		// printf("\n");
		if (temp->data > temp2->data && chunk->location == TOP_A)
			swap_a(stack);
	}
	else if (chunk->size == 1 && chunk->location != TOP_A)
		sender(stack, chunk);
}

// void	chunk_checker(t_container *stack)
// {
// 	printf("mid size: %d\n", stack->mid.size);
// 	if (stack->mid.location == BOTTOM_A)
// 		printf("Mid location is Bottom A\n");
// 	else if (stack->mid.location == TOP_B)
// 		printf("Mid location is Top B\n");
// 	printf("min size: %d\n", stack->min.size);
// 	if (stack->min.location == BOTTOM_A)
// 		printf("Min location is Bottom A\n");
// 	else if (stack->min.location == TOP_B)
// 		printf("Min location is Top B\n");
// }