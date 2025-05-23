/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_rotate_a.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhor <jhor@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 16:13:14 by jhor              #+#    #+#             */
/*   Updated: 2025/05/19 16:13:14 by jhor             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

nodes	*r_rotate_a(nodes *head)
{
	nodes	*temp;
	nodes	*temp2;

	temp = head;
	while (temp->next_link != NULL)
		temp = temp->next_link;
	temp2 = temp->prev_link;
	head->prev_link = temp;
	temp->next_link = head;
	temp->prev_link = NULL;
	temp2->next_link = NULL;
	head = temp;
	return (head);
}
