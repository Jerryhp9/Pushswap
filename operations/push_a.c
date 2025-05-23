/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhor <jhor@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 01:04:12 by jhor              #+#    #+#             */
/*   Updated: 2025/05/22 01:04:12 by jhor             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

void	push_a(nodes **head_a, nodes **head_b)
{
	nodes* nodep;

	if (*head_b == NULL)
		return;
	nodep = *head_b;
	if ((*head_b)->next_link != NULL)
	{
		*head_b = (*head_b)->next_link;
		(*head_b)->prev_link = NULL;
	}
	nodep->next_link = NULL;
	nodep->prev_link = NULL;
	if (*head_a == NULL)
	{
		*head_a = nodep;
		(*head_a)->next_link = NULL;
		(*head_a)->prev_link = NULL;
	}
	else if (*head_a != NULL)
	{
		nodep->next_link = *head_a;
		nodep->prev_link = NULL;
		(*head_a)->prev_link = nodep;
		*head_a = nodep;
	}
}
