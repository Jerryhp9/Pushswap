/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_data_presort.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhor <jhor@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 15:09:16 by jhor              #+#    #+#             */
/*   Updated: 2025/06/16 15:09:16 by jhor             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

int	find_max_int(int *data, t_chunk *chunk)
{
	int i;
	int num;

	i = 1;
	num = data[0];
	while (i < chunk->size)
	{
		if ( data[i] > num)
			num = data[i];
		i++;
	}
	return (num);
}

int	find_min_int(int *data, t_chunk *chunk)
{
	int i;
	int num;

	i = 1;
	num = data[0];
	while (i < chunk->size)
	{
		if ( data[i] < num)
		{
			num = data[i];
		}
		i++;
	}
	return (num);
}

nodes *find_start_node(t_container *stack, t_chunk *chunk)
{
	nodes *cur;

	cur = NULL;
	if (chunk->location == TOP_A)
		cur = stack->pstk_a;
	else if (chunk->location == BOTTOM_A)
	{
		cur = stack->pstk_a;
		while (cur->next_link != NULL)
			cur = cur->next_link;
	}
	else if (chunk->location == TOP_B)
		cur = stack->pstk_b;
	else if (chunk->location == BOTTOM_B)
	{
		cur = stack->pstk_b;
		while (cur->next_link != NULL)
			cur = cur->next_link;
	}
	return (cur);
}

int	*compare_max_chunk(t_container *stack, t_chunk *chunk)
{
	nodes *temp;
	int *max;
	int i;

	i = 0;
	max = ft_calloc(chunk->size, sizeof(int)); //TODO: define the chunk size related to subchunks
	temp = NULL;
	temp = find_start_node(stack, chunk);
	
	while (temp != NULL && i < chunk->size)
	{
		max[i] = temp->data;
		if (chunk->location == TOP_A || chunk->location == TOP_B)
			temp = temp->next_link;
		else if (chunk->location == BOTTOM_A || chunk->location == BOTTOM_B)
			temp = temp->prev_link;
		i++;
	}
	return (max);
}

int	*chunk_presort(int *data, t_container *stack, t_chunk *chunk)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	data = compare_max_chunk(stack, chunk);
	while (i < chunk->size)
	{
		j = 0;
		while (j < chunk->size - 1 - i)
		{
			if (data[j] > data[j + 1])
			{
				temp = data[j];
				data[j] = data[j + 1];
				data[j + 1] = temp;
			}
			j++;
		}
		i++;
	}
	return (data);
}