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
void	TopA_sender(t_container *stack, t_split *split)
{
	if (stack->origin.location == TOP_A)
	{
		if (split->rank <= split->pivot1)
		{
			push_b(stack);
			rotate_b(stack);
			stack->min.size++;
			stack->min.location = BOTTOM_B;
		}
		else if (split->rank > split->pivot1 && split->rank <= split->pivot2)
		{
			push_b(stack);
			stack->mid.size++;
			stack->mid.location = TOP_B;
		}
		else if (split->rank > split->pivot2)
		{
			rotate_b(stack);
			stack->max.size++;
			stack->max.location = BOTTOM_B;
		}
	}
}
void	BotA_sender(t_container *stack, t_split *split)
{
	if (stack->origin.location == BOTTOM_A)
	{
		if (split->rank <= split->pivot1)
		{
			r_rotate_a(stack);
			push_b(stack);
			rotate_b(stack);
			stack->min.size++;
			stack->min.location = BOTTOM_B;
		}
		else if (split->rank > split->pivot1 && split->rank <= split->pivot2)
		{
			r_rotate_a(stack);
			push_b(stack);
			stack->mid.size++;
			stack->mid.location = TOP_B;
		}
		else if (split->rank > split->pivot2)
		{
			r_rotate_a(stack);
			stack->max.size++;
			stack->max.location = TOP_A;
		}
	}
}
void	TopB_sender(t_container *stack, t_split *split)
{
	if (stack->origin.location == TOP_B)
	{
		if (split->rank <= split->pivot1)
		{
			rotate_b(stack);
			stack->min.size++;
			stack->min.location = BOTTOM_B;
		}
		else if (split->rank > split->pivot1 && split->rank <= split->pivot2)
		{
			push_a(stack);
			rotate_a(stack);
			stack->mid.size++;
			stack->mid.location = BOTTOM_A;
		}
		else if (split->rank > split->pivot2)
		{
			push_a(stack);
			stack->max.size++;
			stack->max.location = TOP_A;
		}
	}
}

void	BotB_sender(t_container *stack, t_split *split)
{
	if (stack->origin.location == BOTTOM_B)
	{
		if (split->rank <= split->pivot1)
		{
			r_rotate_b(stack);
			stack->min.size++;
			stack->min.location = TOP_B;
		}
		else if (split->rank > split->pivot1 && split->rank <= split->pivot2)
		{
			r_rotate_b(stack);
			push_a(stack);
			rotate_a(stack);
			stack->mid.size++;
			stack->mid.location = BOTTOM_A;
		}
		else if (split->rank > split->pivot2)
		{
			r_rotate_b(stack);
			push_a(stack);
			stack->max.size++;
			stack->max.location = TOP_A;
		} 
	}
}
