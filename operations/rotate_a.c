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

 nodes	*rotate_a(nodes *head)
{
	nodes	*temp;
	nodes	*temp2;

	temp2 = NULL;
	temp = head;
	while (temp->next_link != NULL)
		temp = temp->next_link;
	temp2 = head;
	if (temp2->next_link != NULL)
		temp2 = temp2->next_link;
	head->prev_link = temp;
	head->next_link = NULL;
	temp->next_link = head;
	temp2->prev_link = NULL;
	head = temp2;
	return (head);
}