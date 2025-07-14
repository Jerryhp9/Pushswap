/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_s.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhor <jhor@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 16:36:22 by jhor              #+#    #+#             */
/*   Updated: 2025/05/22 16:36:22 by jhor             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

void	swap_s(t_container *stack)
{
	stack->is_combine = 1;
	if (stack->pstk_a->next_link != NULL)
		swap_a(stack);
	if (stack->pstk_b->next_link != NULL)
		swap_b(stack);
	printf("ss\n");
	stack->is_combine = 0;
}
