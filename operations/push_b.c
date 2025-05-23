/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhor <jhor@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 17:17:45 by jhor              #+#    #+#             */
/*   Updated: 2025/05/19 17:17:45 by jhor             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

void	push_b(nodes **head_a, nodes **head_b)
{
	nodes	*nodep;

	if (*head_a == NULL)
		return;
	nodep = *head_a;
	*head_a = (*head_a)->next_link;
	nodep->next_link = NULL;
	(*head_a)->prev_link = NULL;
	if (*head_b == NULL)
	{
		*head_b =  nodep;
		(*head_b)->prev_link = NULL;
		(*head_b)->next_link = NULL;
	}
	else if (*head_b != NULL)
	{
		nodep->next_link = *head_b;
		nodep->prev_link = NULL;
		(*head_b)->prev_link = nodep;
		*head_b = (*head_b)->prev_link;
		nodep = NULL;
	}
}