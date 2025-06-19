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

void	quick_sort(t_container *stack, t_chunk *chunk, t_split *split)
{
	nodes *start;
	t_chunk local_min;
	t_chunk local_mid;
	t_chunk local_max;

	start = NULL;
	// printf("address of origin_max %d\n", chunk->size);
	if (chunk->size == 0)
		return;
	if (chunk->size == 3 && chunk->location == TOP_A)
		sort3(stack);
	else if (chunk->size == 2 && chunk->location == TOP_A)
		sort2(stack);
	else if (chunk->size > 3)
	{
		recursive_split(stack, chunk, split, start);
		stack->min.size = chunk->min_count;
		stack->mid.size = chunk->mid_count;
		stack->max.size = chunk->max_count;
		// printf("mid chunk size is %d\n", stack->mid.size);
		// printf("min chunk size is %d\n", stack->min.size);
		// printf("max chunk size is %d\n", stack->max.size);
		local_min = stack->min;
		local_mid = stack->mid;
		local_max = stack->max;
		// ft_lstiter(stack->pstk_a, print_content);
		// printf("\n");
		// ft_lstiter(stack->pstk_b, print_content);
		// printf("\n");
		if (local_max.size > 0)
			quick_sort(stack, &local_max, split);
		if (local_mid.size > 0)
			quick_sort(stack, &local_mid, split);
		if (local_min.size > 0)
			quick_sort(stack, &local_min, split);
	}
	else if (chunk->size <= 3 && chunk->location != TOP_A)
	{
		// printf("mid chunk size is %d\n", stack->mid.size);
		// printf("min chunk size is %d\n", stack->min.size);
		// printf("max chunk size is %d\n", stack->max.size);
		send_top_sort(stack, chunk);
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
	// printf("Data2: "); //!debug 
	// for (int k = 0; k < chunk->size; k++)
	// 	printf("%d ", data[k]);
	// printf("\n");
	// int maxt = find_max_int(data, chunk);
	// printf("Data: "); //!debug
	// for (int k = 0; k < chunk->size; k++)
	// 	printf("%d ", data[k]);
	// printf("\n");
	// int mint = find_min_int(data, chunk);
	// printf("max data of chunk is %d\n", maxt);
	// printf("min data of chunk is %d\n", mint);
	split->pivotS = chunk->size / 3;
	split->pivotB = 2 * chunk->size / 3;
	int total = chunk->size;
	// printf("[%d]\n", mint);
	// printf("[%d]\n", maxt);
	// printf("[%d]\n", split->pivotS); //!pivot print
	// printf("[%d]\n", split->pivotB);
	// printf("\n");
	// ft_lstiter(start, print_content);
	// printf("\n");
	start = find_start_node(stack, chunk);
	while (i < total)
	{
		// printf("\n");
		// ft_lstiter(start, print_content);
		// printf("\n");
		split->val = start->data;
		split->rank = 0;
		while (split->rank < chunk->size)
		{
			if (data[split->rank] == split->val)
				break;
			split->rank++;
		}
		// printf("data sending for validation is %d\n", data[split->rank]); //!what nodes is validating
		if (chunk->location == TOP_A || chunk->location == TOP_B)
			start = start->next_link;
		else if (chunk->location == BOTTOM_A || chunk->location == BOTTOM_B)
			start = start->prev_link;
		// printf("Start: %d\n", start->data);
		// printf("I: %d\n", i);
		// printf("Chunk_size: %d\n", chunk->size);
		// printf("Times\n");
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
	// if (chunk->min_count + chunk->mid_count + chunk->max_count == chunk->size)
	// 	chunk->size = 0; 
	// printf("min size is %d\n", chunk->min_count);
	// printf("mid size is %d\n", chunk->mid_count);
	// printf("max size is %d\n", chunk->max_count);
	// printf("chunk size is %d\n", chunk->size);
	free(data);
}
