/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_rotate_b.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhor <jhor@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 00:44:53 by jhor              #+#    #+#             */
/*   Updated: 2025/05/22 00:44:53 by jhor             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

nodes *r_rotate_b(nodes *head_b)
{
	nodes *temp;
	nodes *temp2;

	temp = head_b;
	temp2 = NULL;
	// ft_lstiter(temp2, print_content);
	// printf("\n");
	while (temp->next_link != NULL)
		temp = temp->next_link;
	ft_lstiter(temp, print_content);
	printf("\n");
	temp2 = temp->prev_link;
	ft_lstiter(temp2, print_content);
	printf("\n");
	printf("\n");
	if (temp2->next_link != NULL)
		temp2->next_link = NULL;
	ft_lstiter(temp2, print_content);
	printf("\n");
	printf("\n");
	temp->prev_link = NULL;
	temp->next_link = head_b;
	head_b->prev_link = temp;
	head_b = temp;
	// while (temp->next_link != NULL)
	// 	temp = temp->next_link;
	// ft_lstiter(temp, print_content);
	// printf("\n");
	return (head_b);
}