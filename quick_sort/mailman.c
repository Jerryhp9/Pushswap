/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mailman.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhor <jhor@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 18:37:02 by jhor              #+#    #+#             */
/*   Updated: 2025/06/12 18:37:02 by jhor             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

//!these functions are for splitting 3 ways depending on the location
void	TopA_sender(t_container *stack, t_chunk *chunk, t_split *split)
{
	if (chunk->location == TOP_A)
	{
		if (split->rank <= split->pivotS)
		{
			push_b(stack);
			rotate_b(stack);
			chunk->min_count++;
			stack->min.location = BOTTOM_B;
			stack->b_counter++;
			stack->a_counter--;
			// printf("current min stack is %d\n", stack->min.location);
		}
		else if (split->rank > split->pivotS && split->rank <= split->pivotB)
		{
			push_b(stack);
			chunk->mid_count++;
			stack->mid.location = TOP_B;
			stack->b_counter++;
			stack->a_counter--;
			// printf("current mid stack is %d\n", stack->mid.location);
		}
		else if (split->rank > split->pivotB)
		{
			rotate_a(stack);
			chunk->max_count++;
			stack->max.location = BOTTOM_A;
			// printf("current max stack is %d\n", stack->max.location);
		}
	}
}

void	BotA_sender(t_container *stack, t_chunk *chunk, t_split *split)
{
	if (chunk->location == BOTTOM_A)
	{
		if (split->rank <= split->pivotS)
		{
			r_rotate_a(stack);
			push_b(stack);
			rotate_b(stack);
			chunk->min_count++;
			stack->min.location = BOTTOM_B;
			stack->b_counter++;
			stack->a_counter--;
			// printf("current min stack is %d\n", stack->min.location);
		}
		else if (split->rank > split->pivotS && split->rank <= split->pivotB)
		{
			r_rotate_a(stack);
			push_b(stack);
			chunk->mid_count++;
			stack->mid.location = TOP_B;
			stack->b_counter++;
			stack->a_counter--;
			// printf("current mid stack is %d\n", stack->mid.location);
		}
		else if (split->rank > split->pivotB)
		{
			r_rotate_a(stack);
			chunk->max_count++;
			stack->max.location = TOP_A;
			// printf("current max stack is %d\n", stack->max.location);
		}
	}
}

void	TopB_sender(t_container *stack, t_chunk *chunk, t_split *split)
{
	if (chunk->location == TOP_B)
	{
		if (split->rank <= split->pivotS)
		{
			rotate_b(stack);
			chunk->min_count++;
			stack->min.location = BOTTOM_B;
			// printf("current min stack is %d\n", stack->min.location);
		}
		else if (split->rank > split->pivotS && split->rank <= split->pivotB)
		{
			push_a(stack);
			rotate_a(stack);
			chunk->mid_count++;
			stack->mid.location = BOTTOM_A;
			stack->a_counter++;
			stack->b_counter--;
			// printf("current mid stack is %d\n", stack->mid.location);
		}
		else if (split->rank > split->pivotB)
		{
			push_a(stack);
			chunk->max_count++;
			stack->max.location = TOP_A;
			stack->a_counter++;
			stack->b_counter--;
			// printf("current max stack is %d\n", stack->max.location);
		}
	}
}

void	BotB_sender(t_container *stack, t_chunk *chunk, t_split *split)
{
	if (chunk->location == BOTTOM_B)
	{
		if (split->rank <= split->pivotS)
		{
			r_rotate_b(stack);
			chunk->min_count++;
			stack->min.location = TOP_B;
			// printf("current min stack is %d\n", stack->min.location);
		}
		else if (split->rank > split->pivotS && split->rank <= split->pivotB)
		{
			r_rotate_b(stack);
			push_a(stack);
			rotate_a(stack);
			chunk->mid_count++;
			stack->mid.location = BOTTOM_A;
			stack->a_counter++;
			stack->b_counter--;
			// printf("current mid stack is %d\n", stack->mid.location);
		}
		else if (split->rank > split->pivotB)
		{
			r_rotate_b(stack);
			push_a(stack);
			chunk->max_count++;
			stack->max.location = TOP_A;
			stack->a_counter++;
			stack->b_counter--;
			// printf("current max stack is %d\n", stack->max.location);
		} 
	}
}

