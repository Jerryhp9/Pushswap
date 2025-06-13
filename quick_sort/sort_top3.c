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

void	sender(t_container *stack)
{
	while (stack->max.size != 0)
	{
		if (stack->max.location == BOTTOM_A)
			r_rotate_a(stack);
		if (stack->max.location == TOP_B)
			push_a(stack);
		stack->max.size--;
	}
	while (stack->mid.size != 0)
	{
		if (stack->mid.location == BOTTOM_A)
			r_rotate_a(stack);
		if (stack->mid.location == TOP_B)
			push_a(stack);
		stack->mid.size--;
	}
	while (stack->min.size != 0)
	{
		if (stack->min.location == BOTTOM_B)
		{
			r_rotate_b(stack);
			push_a(stack);
		}
		if (stack->min.location == TOP_B)
			push_a(stack);
		stack->min.size--;
	}
}

void	send_top_sort3(t_container *stack)
{
	if (stack->max.size <= 2 && stack->max.location == TOP_A)
	{
		sender(stack);
		sort3(stack); //TODO: SHORTEN THE LINES WITH A FUNCTION TO HANDLE LOCATION SWAPPING AND SORT3
	}
	if (stack->mid.size <= 2 && stack->mid.location == TOP_A)
	{
		sender(stack);
		sort3(stack);
	}
	if (stack->min.size <= 2 && stack->min.location == TOP_A)
	{
		sender(stack);
		sort3(stack);
	}
}