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

t_chunk	*innit_chunk_recurse(t_chunk *chunk)
{
	chunk->min_count = 0;
	chunk->mid_count = 0;
	chunk->max_count = 0;

	return (chunk);
}

void	innit_chunk_proper(t_container *stack)
{
	stack->min.location = 0;
	stack->mid.location = 0;
	stack->max.location = 0;
	stack->min.size = 0;
	stack->mid.size = 0;
	stack->max.size = 0;
	stack->a_counter = stack->origin_chunk.size;
	stack->b_counter = 0;
}

t_split	*innit_sorted(t_split *split)
{
	split->size = 0;
	split->rank = 0;
	split->val = 0;
	split->pivotS = 0;
	split->pivotB = 0;

	return (split);
}

void	innit_sorted_check(t_sorted_c *sorted)
{
	sorted->i = 0;
	sorted->j = 0;
	sorted->data = NULL;
}

int	sorted_check(t_container *stack, t_chunk *chunk)
{
	t_sorted_c	sorted;
	nodes		*ptr;

	innit_sorted_check(&sorted); //TODO: SHORTEN ONE MORE LINE THEN TEST
	ptr = find_start_node(stack, chunk);
	sorted.data = chunk_presort(sorted.data, stack, chunk);
	if (!sorted.data)
		return (0);
	while (ptr && sorted.i < chunk->size)
	{
		if (ptr->data == sorted.data[sorted.i])
		{
			ptr = ptr->next_link;
			sorted.i++;
			sorted.j++;
		}
		else
		{
			free(sorted.data);
			return (0);
		}
	}
	free(sorted.data);
	return (sorted.j == chunk->size);
}

void	quick_sort_helper(t_container *stack, t_chunk *chunk, t_split *split)
{
	nodes *start;
	t_chunk local_min;
	t_chunk local_mid;
	t_chunk local_max;

	start = NULL;
	recursive_split(stack, chunk, split, start);
	stack->min.size = chunk->min_count;
	stack->mid.size = chunk->mid_count;
	stack->max.size = chunk->max_count;
	local_min = stack->min;
	local_mid = stack->mid;
	local_max = stack->max;
	if (local_max.size > 0)
		quick_sort(stack, &local_max, split);
	if (local_mid.size > 0)
		quick_sort(stack, &local_mid, split);
	if (local_min.size > 0)
		quick_sort(stack, &local_min, split);
}

void	quick_sort(t_container *stack, t_chunk *chunk, t_split *split)
{
	if (chunk->size == 0)
		return;
	else if (sorted_check(stack, chunk) && chunk->location == TOP_A)
	{
		if (chunk->location != TOP_A) //push to top a
			sender(stack, chunk);
		return;
	}
	if (stack->a_counter == 2 && chunk->location == TOP_A)
		return sort2(stack);
	if (stack->a_counter == 3 && chunk->location == TOP_A)
		return n_sort3(stack);
	else if (stack->a_counter == 5 && chunk->location == TOP_A)
		return sort5(stack);
	else if (chunk->size <= 3 && chunk->location != TOP_A) //TODO: find a way to check the size of stack A and just sort if it is == 3
		return send_top_sort(stack, chunk);
	else if (chunk->size == 3 && chunk->location == TOP_A)
		return sort3(stack);
	else if (chunk->size == 2 && chunk->location == TOP_A)
		return sort2(stack);
	quick_sort_helper(stack, chunk, split);
}

void	send_by_location(t_container *stack, t_chunk *chunk, t_split *split)
{
	if (chunk->location == TOP_A)
		TopA_sender(stack, chunk, split);
	else if (chunk->location == BOTTOM_A)
		BotA_sender(stack, chunk, split);
	else if (chunk->location == TOP_B)
		TopB_sender(stack, chunk, split);
	else if (chunk->location == BOTTOM_B)
		BotB_sender(stack, chunk, split);
}

void	recursive_split(t_container *stack, t_chunk *chunk, t_split *split, nodes *start)
{
	int *data;
	int i;

	data = 0;
	i = -1;
	innit_chunk_recurse(chunk);
	data = chunk_presort(data, stack, chunk);
	split->pivotS = chunk->size / 3;
	split->pivotB = 2 * chunk->size / 3;
	int total = chunk->size;
	start = find_start_node(stack, chunk);
	while (++i < total)
	{
		split->val = start->data;
		split->rank = -1;
		while (++split->rank < chunk->size)
			if (data[split->rank] == split->val)
				break;
		if (chunk->location == TOP_A || chunk->location == TOP_B)
			start = start->next_link;
		else if (chunk->location == BOTTOM_A || chunk->location == BOTTOM_B)
			start = start->prev_link;
		send_by_location(stack, chunk, split);
	}
	free(data);
}

