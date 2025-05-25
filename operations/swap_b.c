/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhor <jhor@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 18:55:25 by jhor              #+#    #+#             */
/*   Updated: 2025/05/21 18:55:25 by jhor             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

void swap_b(t_container *stack)
{
	nodes *temp;
	nodes *temp2;

	temp2 = NULL;
	temp = stack->pstk_b;
	if (!stack->pstk_b || stack->pstk_b->next_link == NULL)
		return;
	stack->pstk_b = stack->pstk_b->next_link;
	temp2 = stack->pstk_b->next_link;
	stack->pstk_b->next_link = temp;
	stack->pstk_b->prev_link = NULL;
	temp->prev_link = stack->pstk_b;
	temp->next_link = temp2;
	if (stack->is_combine == 0)
		printf("sb\n");
}

// nodes *swap_b(nodes *head_b)
// {
// 	nodes *temp;
// 	nodes *temp2;

// 	temp2 = NULL;
// 	temp = head_b;
// 	ft_lstiter(head_b, print_content);
// 	printf("\n");
// 	if (!head_b || head_b->next_link == NULL)
// 		return (head_b);
// 	if (head_b->next_link != NULL)
// 		head_b = head_b->next_link;
// 	ft_lstiter(head_b, print_content);
// 	printf("\n");
// 	if (head_b->next_link != NULL)
// 		temp2 = head_b->next_link;
// 	ft_lstiter(temp2, print_content);
// 	printf("\n");
// 	temp->next_link = temp2;
// 	temp->prev_link = head_b;
// 	head_b->next_link = temp;
// 	head_b->prev_link = NULL;
// 	return (head_b);
// }
