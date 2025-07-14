/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort_innit.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhor <jhor@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 21:47:30 by jhor              #+#    #+#             */
/*   Updated: 2025/07/14 22:18:07 by jhor             ###   ########.fr       */
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

void	innit_sorted_check(t_sorted_c *sorted)
{
	sorted->i = 0;
	sorted->j = 0;
	sorted->data = NULL;
}

int	move_top(int position, t_nodes *ptr, t_container *stack)
{
	t_nodes	*temp;

	temp = stack->pstk_a;
	while (temp)
	{
		if (temp == ptr)
			return (position);
		else if (temp != ptr)
			position++;
		temp = temp->next_link;
	}
	return (0);
}
