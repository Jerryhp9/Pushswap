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

nodes *swap_a(nodes *head)
{
	nodes *temp;
	nodes *temp2;

	temp = head;
	if (head->next_link != NULL)
		head = head->next_link;
	if (head->next_link != NULL)
		temp2 = head->next_link;
	head->next_link = temp;
	head->prev_link = NULL;
	temp->prev_link = head;
	temp->next_link = temp2;
	return (head);
}
