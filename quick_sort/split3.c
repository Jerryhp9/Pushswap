/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhor <jhor@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 13:48:58 by jhor              #+#    #+#             */
/*   Updated: 2025/06/10 13:48:58 by jhor             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

t_chunk origin_size(t_container *stack)
{
	nodes *ptr;

	ptr = NULL;
	ptr = stack->pstk_a;
	stack->origin_chunk.size = 0;
	stack->origin_chunk.location = TOP_A;
	while (ptr != NULL)
	{
		stack->origin_chunk.size++;
		ptr = ptr->next_link;
	}
	return (stack->origin_chunk);
}


// t_container *apply_split_chunk(t_container *stack, t_split *split)
// {
// 	if (split->rank > split->pivot1 && split->rank <= split->pivot2)
// 	{
// 		push_b(stack);
// 		stack->origin_mid.size++;
// 		stack->origin_mid.location = TOP_B;
// 		stack->b_counter++;
// 		stack->a_counter--;
// 		// printf("\n");
// 		// printf("|%d|\n", stack->mid.size);
// 		// printf("\n");
// 	}
// 	else if (split->rank <= split->pivot1)
// 	{
// 		push_b(stack);
// 		rotate_b(stack);
// 		stack->origin_min.size++;
// 		stack->origin_min.location = BOTTOM_B;
// 		stack->b_counter++;
// 		stack->a_counter--;
// 		// printf("\n");
// 		// printf("-%d-\n", stack->min.size);
// 		// printf("\n");
// 	}
// 	else if (split->rank > split->pivot2)
// 	{
// 		rotate_a(stack);
// 		stack->origin_max.size++;
// 		stack->origin_max.location = BOTTOM_A;
// 		// printf("\n");
// 		// printf("[%d]\n", stack->max.size);
// 		// printf("\n");
// 	}
// 	return (stack);
// }

// void	locate_chunk(t_container *stack)
// {
// 	if (stack->max.size != 0)
// 	{
// 		stack->max.location = BOTTOM_A;
// 		printf("\n");
// 		printf("Min location: %s\n", get_location_name(stack->min.location));
// 		printf("\n");
// 	}
// 	else if (stack->mid.size != 0)
// 	{
// 		stack->mid.location = TOP_B;
// 		printf("\n");
// 		printf("Mid location: %s\n", get_location_name(stack->mid.location));
// 		printf("\n");
// 	}
// 	else if (stack->min.size != 0)
// 	{
// 		stack->min.location = BOTTOM_B;
// 		printf("\n");
// 		printf("Max location: %s\n", get_location_name(stack->max.location));
// 		printf("\n");
// 	}
// }

// void	compare_split(int *data, int argc, t_container *stack, t_split *split)
// {
// 	split = innit_chunk(argc, stack, split);
// 	stack = innit_stack(stack, split);
// 	// printf("chunk location is %d\n", stack->origin_max.location);
// 	split->i = 0;
// 	while (split->i < split->size)
// 	{
// 		split->val = stack->pstk_a->data;
// 		split->rank = 0;
// 		while (split->rank < split->size)
// 		{
// 			if (data[split->rank] == split->val)
// 				break;
// 			split->rank++;
// 		}
// 		stack = apply_split_chunk(stack, split);
// 		split->i++;
// 	}
// 	// if (stack->max.size != 0)
// 	// 	stack->max.location = BOTTOM_A;
// 	// else if (stack->mid.size != 0)
// 	// 	stack->mid.location = TOP_B;
// 	// else if (stack->min.size != 0)
// 	// 	stack->min.location = BOTTOM_B;
// }


