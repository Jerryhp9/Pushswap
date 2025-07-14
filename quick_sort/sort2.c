/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_top_sort2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhor <jhor@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 16:53:15 by jhor              #+#    #+#             */
/*   Updated: 2025/06/17 16:53:15 by jhor             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

void	sort2(t_container *stack)
{
	t_nodes	*temp;

	temp = NULL;
	temp = stack->pstk_a->next_link;
	if (stack->pstk_a->data > temp->data)
		swap_a(stack);
}
