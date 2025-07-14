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

int	sorted_check(t_container *stack, t_chunk *chunk)
{
	t_sorted_c	sorted;
	t_nodes		*ptr;

	innit_sorted_check(&sorted);
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
	t_nodes	*start;
	t_chunk	local_min;
	t_chunk	local_mid;
	t_chunk	local_max;

	start = NULL;
	recu_spt(stack, chunk, split, start);
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
		return ;
	else if (sorted_check(stack, chunk) && chunk->location == TOP_A)
	{
		if (chunk->location != TOP_A)
			sender(stack, chunk);
		return ;
	}
	if (stack->a_counter == 2 && chunk->location == TOP_A)
		return (sort2(stack));
	if (stack->a_counter == 3 && chunk->location == TOP_A)
		return (n_sort3(stack));
	else if (stack->a_counter == 5 && chunk->location == TOP_A)
		return (sort5(stack));
	else if (chunk->size <= 3 && chunk->location != TOP_A)
		return (send_top_sort(stack, chunk));
	else if (chunk->size == 3 && chunk->location == TOP_A)
		return (sort3(stack));
	else if (chunk->size == 2 && chunk->location == TOP_A)
		return (sort2(stack));
	quick_sort_helper(stack, chunk, split);
}

void	send_by_location(t_container *stack, t_chunk *chunk, t_split *split)
{
	if (chunk->location == TOP_A)
		topa_sender(stack, chunk, split);
	else if (chunk->location == BOTTOM_A)
		bota_sender(stack, chunk, split);
	else if (chunk->location == TOP_B)
		topb_sender(stack, chunk, split);
	else if (chunk->location == BOTTOM_B)
		botb_sender(stack, chunk, split);
}

void	recu_spt(t_container *stk, t_chunk *chk, t_split *spt, t_nodes *st)
{
	int	*data;
	int	i;

	data = 0;
	i = -1;
	innit_chunk_recurse(chk);
	data = chunk_presort(data, stk, chk);
	spt->pivots = chk->size / 3;
	spt->pivotb = 2 * chk->size / 3;
	st = find_start_node(stk, chk);
	while (++i < chk->size)
	{
		spt->val = st->data;
		spt->rank = -1;
		while (++spt->rank < chk->size)
			if (data[spt->rank] == spt->val)
				break ;
		if (chk->location == TOP_A || chk->location == TOP_B)
			st = st->next_link;
		else if (chk->location == BOTTOM_A || chk->location == BOTTOM_B)
			st = st->prev_link;
		send_by_location(stk, chk, spt);
	}
	free(data);
}
