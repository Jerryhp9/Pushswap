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
void innit_chunk_proper(t_container *stack)
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

int	sorted_check(t_container *stack, t_chunk *chunk)
{
	nodes	*ptr;
	int		i;
	int		*data;
	int		j;

	ptr = NULL;
	ptr = find_start_node(stack, chunk);
	i = 0;
	j = 0;
	data = NULL;
	data = chunk_presort(data, stack, chunk);
	if (!data)
		return (0);
	while (ptr && i < chunk->size)
	{
		if (ptr->data == data[i])
		{
			ptr = ptr->next_link;
			i++;
			j++;
		}
		else
		{
			free(data);
			return (0);
		}
	}
	free(data);
	return (j == chunk->size);
}

void	quick_sort(t_container *stack, t_chunk *chunk, t_split *split)
{
	nodes *start;
	t_chunk local_min;
	t_chunk local_mid;
	t_chunk local_max;
	
	start = NULL;
	if (chunk->size == 0)
		return;
	else if (sorted_check(stack, chunk) && chunk->location == TOP_A) //push to top a
	{
		if (chunk->location != TOP_A)
			sender(stack, chunk);
		return;
	}
	if (stack->a_counter == 2 && chunk->location == TOP_A)
	{
		sort2(stack);
		return;
	}
	if (stack->a_counter == 3 && chunk->location == TOP_A)
	{
		n_sort3(stack);
		return;
	}
	else if (stack->a_counter == 5 && chunk->location == TOP_A)
	{
		sort5(stack);
		return;
	}
	else if (chunk->size <= 3 && chunk->location != TOP_A) //TODO: find a way to check the size of stack A and just sort if it is == 3
	{
			send_top_sort(stack, chunk);
			return;
	}
	else if (chunk->size == 3 && chunk->location == TOP_A)
	{
		sort3(stack);
		return;
	}
	else if (chunk->size == 2 && chunk->location == TOP_A)
	{
		sort2(stack);
		return;
	}
	else if (chunk->size > 3)
	{
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
}


void	recursive_split(t_container *stack, t_chunk *chunk, t_split *split, nodes *start)
{
	int *data;
	int i;
	data = 0;
	i = 0;
	innit_chunk_recurse(chunk);
	data = chunk_presort(data, stack, chunk);
	split->pivotS = chunk->size / 3;
	split->pivotB = 2 * chunk->size / 3;
	int total = chunk->size;
	start = find_start_node(stack, chunk);
	while (i < total)
	{
		split->val = start->data;
		split->rank = 0;
		while (split->rank < chunk->size)
		{
			if (data[split->rank] == split->val)
				break;
			split->rank++;
		}
		if (chunk->location == TOP_A || chunk->location == TOP_B)
			start = start->next_link;
		else if (chunk->location == BOTTOM_A || chunk->location == BOTTOM_B)
			start = start->prev_link;
		if (chunk->location == TOP_A)
			TopA_sender(stack, chunk, split);
		else if (chunk->location == BOTTOM_A)
			BotA_sender(stack, chunk, split);
		else if (chunk->location == TOP_B)
			TopB_sender(stack, chunk, split);
		else if (chunk->location == BOTTOM_B)
			BotB_sender(stack, chunk, split);
		i++;
	}
	free(data);
}
