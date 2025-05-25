/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_a.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhor <jhor@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 14:48:29 by jhor              #+#    #+#             */
/*   Updated: 2025/05/19 14:48:29 by jhor             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

 #include "../pushswap.h"

 void	rotate_a(t_container *stack)
{
	nodes	*temp;
	nodes	*temp2;

	temp2 = NULL;
	temp = stack->pstk_a;
	while (temp->next_link != NULL)
		temp = temp->next_link;
	temp2 = stack->pstk_a;
	if (temp2->next_link != NULL)
		temp2 = temp2->next_link;
	stack->pstk_a->prev_link = temp;
	stack->pstk_a->next_link = NULL;
	temp->next_link = stack->pstk_a;
	temp2->prev_link = NULL;
	stack->pstk_a = temp2;
	if (stack->is_combine == 0)
		printf("ra\n");
}