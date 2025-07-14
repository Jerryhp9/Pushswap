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
void	topa_sender(t_container *stack, t_chunk *chunk, t_split *split)
{
	if (split->rank <= split->pivots)
	{
		push_b(stack);
		rotate_b(stack);
		chunk->min_count++;
		stack->min.location = BOTTOM_B;
		stack->b_counter++;
		stack->a_counter--;
	}
	else if (split->rank > split->pivots && split->rank <= split->pivotb)
	{
		push_b(stack);
		chunk->mid_count++;
		stack->mid.location = TOP_B;
		stack->b_counter++;
		stack->a_counter--;
	}
	else if (split->rank > split->pivotb)
	{
		rotate_a(stack);
		chunk->max_count++;
		stack->max.location = BOTTOM_A;
	}
}

void	bota_sender(t_container *stack, t_chunk *chunk, t_split *split)
{
	if (split->rank <= split->pivots)
	{
		r_rotate_a(stack);
		push_b(stack);
		rotate_b(stack);
		chunk->min_count++;
		stack->min.location = BOTTOM_B;
		stack->b_counter++;
		stack->a_counter--;
	}
	else if (split->rank > split->pivots && split->rank <= split->pivotb)
	{
		r_rotate_a(stack);
		push_b(stack);
		chunk->mid_count++;
		stack->mid.location = TOP_B;
		stack->b_counter++;
		stack->a_counter--;
	}
	else if (split->rank > split->pivotb)
	{
		r_rotate_a(stack);
		chunk->max_count++;
		stack->max.location = TOP_A;
	}
}

void	topb_sender(t_container *stack, t_chunk *chunk, t_split *split)
{
	if (split->rank <= split->pivots)
	{
		rotate_b(stack);
		chunk->min_count++;
		stack->min.location = BOTTOM_B;
	}
	else if (split->rank > split->pivots && split->rank <= split->pivotb)
	{
		push_a(stack);
		rotate_a(stack);
		chunk->mid_count++;
		stack->mid.location = BOTTOM_A;
		stack->a_counter++;
		stack->b_counter--;
	}
	else if (split->rank > split->pivotb)
	{
		push_a(stack);
		chunk->max_count++;
		stack->max.location = TOP_A;
		stack->a_counter++;
		stack->b_counter--;
	}
}

void	botb_sender(t_container *stack, t_chunk *chunk, t_split *split)
{
	if (split->rank <= split->pivots)
	{
		r_rotate_b(stack);
		chunk->min_count++;
		stack->min.location = TOP_B;
	}
	else if (split->rank > split->pivots && split->rank <= split->pivotb)
	{
		r_rotate_b(stack);
		push_a(stack);
		rotate_a(stack);
		chunk->mid_count++;
		stack->mid.location = BOTTOM_A;
		stack->a_counter++;
		stack->b_counter--;
	}
	else if (split->rank > split->pivotb)
	{
		r_rotate_b(stack);
		push_a(stack);
		chunk->max_count++;
		stack->max.location = TOP_A;
		stack->a_counter++;
		stack->b_counter--;
	}
}
