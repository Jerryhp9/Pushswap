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
	// printf("nodes pointer in sorted chunk function is %d\n", ptr->data); //!uncomment
	i = 0;
	j = 0;
	data = NULL;
	data = chunk_presort(data, stack, chunk); //presorted data
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
	else if (sorted_check(stack, chunk)) //push to top a
	{
		// printf("location in sorted check is %d\n", chunk->location);
		if (chunk->location != TOP_A)
			send_top_sort(stack, chunk);
		// printf("it checks whether it's sorted\n"); //! commented out
		return;
	}
	if (chunk->size == 2 && chunk->location == TOP_A)
	{
		printf("here\n");
		sort2(stack);
		return;
	}
	if (chunk->size == 3 && chunk->location == TOP_A)
	{
		// printf("it sort 3\n"); //! commented out
		n_sort3(stack);
		return;
	}
	else if (chunk->size == 5 && chunk->location == TOP_A)
	{
		// printf("a counter is %d\n", stack->a_counter);
		sort5(stack);
		return;
	}
	else if (chunk->size <= 3 && chunk->location != TOP_A) //TODO: find a way to check the size of stack A and just sort if it is == 3
	{
			// printf("mid chunk size is %d\n", stack->mid.size);
			// printf("min chunk size is %d\n", stack->min.size);
			// printf("max chunk size is %d\n", stack->max.size);
			send_top_sort(stack, chunk);
			return;
	}
	else if (chunk->size == 3 && chunk->location == TOP_A)
	{
		// printf("i am right here");
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
		// printf("origin_chunk size %d\n", chunk->size); //!commented out
		// printf("chunk location is %d\n", chunk->location);
		// printf("mid chunk size is {%d}\n", stack->mid.size);
		// printf("min chunk size is {%d}\n", stack->min.size);
		// printf("max chunk size is {%d}\n", stack->max.size);
		recursive_split(stack, chunk, split, start);
		stack->min.size = chunk->min_count;
		stack->mid.size = chunk->mid_count;
		stack->max.size = chunk->max_count;
		// printf("mid chunk size is %d\n", stack->mid.size); //!commented out
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
		{
			// printf("here\n");
			// printf("local_mid location is %d\n", local_mid.location); //!commented out
			quick_sort(stack, &local_mid, split);
		}
		if (local_min.size > 0)
		{
			// printf("local_min location is %d\n", local_min.location);
			quick_sort(stack, &local_min, split);
		}
		// printf("Number of nodes in stack A are %d\n", stack->a_counter);
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
	// printf("Data: "); //!debug 
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
