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

nodes *swap_b(nodes *head_b)
{
	nodes *temp;
	nodes *temp2;

	temp2 = NULL;
	temp = head_b;
	if (!head_b || head_b->next_link == NULL)
		return (head_b);
	if (head_b->next_link != NULL)
		head_b = head_b->next_link;
	if (head_b->next_link != NULL)
		temp2 = head_b->next_link;
	head_b->next_link = temp;
	head_b->prev_link = NULL;
	temp->prev_link = head_b;
	temp->next_link = temp2;
	return (head_b);
}
