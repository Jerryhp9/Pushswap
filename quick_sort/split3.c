/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhor <jhor@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 13:48:58 by jhor              #+#    #+#             */
/*   Updated: 2025/06/10 13:48:58 by jhor             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

t_chunk	origin_size(t_container *stack)
{
	t_nodes	*ptr;

	ptr = NULL;
	ptr = stack->pstk_a;
	stack->origin_chunk.size = 0;
	stack->origin_chunk.location = TOP_A;
	while (ptr != NULL)
	{
		stack->origin_chunk.size++;
		ptr = ptr->next_link;
	}
	return (stack->origin_chunk);
}
