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

t_split	*innit_chunk(int argc, t_split *split)
{
	split->size = argc - 1;
	split->pivot1 = split->size / 3;
	split->pivot2 = 2 * split->size / 3;
	split->min_count = 0;
	split->mid_count = 0;
	split->max_count = 0;

	return (split);
}

void	apply_split_chunk(t_container *stack, t_split *split)
{
	if (split->rank > split->pivot1 && split->rank <= split->pivot2)
	{
		push_b(stack);
		stack->mid.size++;
		// printf("\n");
		// printf("|%d|\n", stack->mid.size);
		// printf("\n");
	}
	else if (split->rank <= split->pivot1)
	{
		push_b(stack);
		rotate_b(stack);
		stack->min.size++;
		// printf("\n");
		// printf("-%d-\n", stack->min.size);
		// printf("\n");
	}
	else if (split->rank > split->pivot2)
	{
		rotate_a(stack);
		stack->max.size++;
		// printf("\n");
		// printf("[%d]\n", stack->max.size);
		// printf("\n");
	}
}

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

void	compare_split(int *data, int argc, t_container *stack, t_split *split)
{
	split = innit_chunk(argc, split);
	split->i = 0;
	while (split->i < split->size)
	{
		split->val = stack->pstk_a->data;
		split->rank = 0;
		while (split->rank < split->size)
		{
			if (data[split->rank] == split->val)
				break;
			split->rank++;
		}
		apply_split_chunk(stack, split);
		split->i++;
	}
	if (stack->max.size != 0)
		stack->max.location = BOTTOM_A;
	else if (stack->mid.size != 0)
		stack->mid.location = TOP_B;
	else if (stack->min.size != 0)
		stack->min.location = BOTTOM_B;
}

void	quick_sort(t_container *stack, t_split *split)
{
	stack->origin = stack->max;
	split->pivotsmall = stack->origin.size / 3;
	split->pivotbig = stack->origin.size * 2 / 3;
	if (stack->origin.size <= 2 && stack->origin.location == TOP_A)
		sort3(stack);
	else if (stack->origin.size > 2 && stack->origin.location != TOP_A)
		apply_split_chunk(); //TODO: split into 3 and label them with chunk name, size and location(Mailman)
	if (stack->max.size <= 2 && stack->max.location == TOP_A)
		sort3(stack);
	if (stack->mid.size <= 2 && stack->mid.location == TOP_A)
		sort3(stack);
	if (stack->min.size <= 2 && stack->min.location == TOP_A)
		sort3(stack);
	quick_sort(stack->max.size, split);
	quick_sort(stack->mid.size, split);
	quick_sort(stack->min.size, split);
}

