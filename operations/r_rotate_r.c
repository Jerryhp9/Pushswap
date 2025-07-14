/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_rotate_r.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhor <jhor@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 18:47:08 by jhor              #+#    #+#             */
/*   Updated: 2025/05/23 18:47:08 by jhor             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

void	r_rotate_r(t_container *stack)
{
	stack->is_combine = 1;
	if (stack->pstk_a != NULL)
		r_rotate_a(stack);
	if (stack->pstk_b != NULL)
		r_rotate_b(stack);
	printf("rr\n");
	stack->is_combine = 0;
}
