/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_r.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhor <jhor@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 18:24:06 by jhor              #+#    #+#             */
/*   Updated: 2025/05/25 18:24:06 by jhor             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

void	rotate_r(t_container *stack)
{
	stack->is_combine = 1;
	if (stack->pstk_a->next_link != NULL)
		rotate_a(stack);
	if (stack->pstk_b->next_link != NULL)
		rotate_b(stack);
	printf("rr\n");
	stack->is_combine = 0;
}