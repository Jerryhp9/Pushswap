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
	nodes	*last;
	nodes	*move;

	move = NULL;
	last = stack->pstk_a;
	if (!stack->pstk_a || stack->pstk_a->next_link == NULL)
		return;
	while (last->next_link != NULL)
		last = last->next_link;
	// ft_lstiter(last, print_content);
	// printf("Break\n");
	move = stack->pstk_a;
	// ft_lstiter(move, print_content);
	// printf("Break1\n");
	if (stack->pstk_a->next_link != NULL)
		stack->pstk_a = stack->pstk_a->next_link;
	// ft_lstiter(stack->pstk_a, print_content);
	// printf("Break2\n");
	move->prev_link = last;
	move->next_link = NULL;
	last->next_link = move;
	stack->pstk_a->prev_link = NULL;
	// ft_lstiter(move, print_content);
	// printf("Break3\n");
	if (stack->is_combine == 0)
		printf("ra\n");
	return;
}
