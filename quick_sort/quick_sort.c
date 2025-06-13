/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhor <jhor@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 14:17:52 by jhor              #+#    #+#             */
/*   Updated: 2025/06/13 14:17:52 by jhor             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

void	quick_sort(t_container *stack, t_chunk *chunk, t_split *split)
{
	printf("Here");
	if (chunk->size == 0)
		return;
	split->pivotS = chunk->size / 3;
	split->pivotB = chunk->size * 2 / 3;
	if (chunk->size <= 2 && chunk->location == TOP_A)
		sort3(stack);
	else if (chunk->size > 2 && chunk->location != TOP_A)
		recursive_split(stack, chunk, split);
	else if (chunk->size <= 2 && chunk->location != TOP_A)
		send_top_sort3(stack);
	if (stack->max.size > 0)
		quick_sort(stack, &stack->max, split);
	if (stack->max.size > 0)
		quick_sort(stack, &stack->mid, split);
	if (stack->max.size > 0)
		quick_sort(stack, &stack->min, split);
}

void	recursive_split(t_container *stack, t_chunk *chunk, t_split *split)
{
	stack->max.size = 0;
	stack->mid.size = 0;
	stack->min.size = 0;
	while (chunk->size != 0)
	{
		if (chunk->location == TOP_A)
			TopA_sender(stack, chunk, split);
		if (chunk->location == BOTTOM_A)
			BotA_sender(stack, chunk, split);
		if (chunk->location == TOP_B)
			TopB_sender(stack, chunk, split);
		if (chunk->location == BOTTOM_B)
			BotB_sender(stack, chunk, split);
		chunk->size--;
	}
}