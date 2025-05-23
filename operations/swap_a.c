/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhor <jhor@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 19:28:22 by jhor              #+#    #+#             */
/*   Updated: 2025/05/16 19:28:22 by jhor             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

nodes *swap_a(nodes *head_a)
{
	nodes *temp;
	nodes *temp2;

	temp2 = NULL;
	temp = head_a;
	if (!head_a || head_a->next_link == NULL)
		return (head_a);
	if (head_a->next_link != NULL)
		head_a = head_a->next_link;
	if (head_a->next_link != NULL)
		temp2 = head_a->next_link;
	head_a->next_link = temp;
	head_a->prev_link = NULL;
	temp->prev_link = head_a;
	temp->next_link = temp2;
	return (head_a);
}
