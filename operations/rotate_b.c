/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_b.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhor <jhor@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 00:28:46 by jhor              #+#    #+#             */
/*   Updated: 2025/05/22 00:28:46 by jhor             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

nodes *rotate_b(nodes *head_b)
{
	nodes *temp;
	nodes *temp2;

	temp2 = NULL;
	temp = head_b;
	while (temp->next_link != NULL)
		temp = temp->next_link;
	if (head_b->next_link != NULL)
		head_b = head_b->next_link;
	temp2 = head_b->prev_link;
	temp2->prev_link = temp;
	temp2->next_link = NULL;
	temp->next_link = temp2;
	head_b->prev_link = NULL;
	return (head_b);
}