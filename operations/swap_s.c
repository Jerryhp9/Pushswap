/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_s.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhor <jhor@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 16:36:22 by jhor              #+#    #+#             */
/*   Updated: 2025/05/22 16:36:22 by jhor             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

void	swap_s(nodes **head_a, nodes **head_b)
{
	if ((*head_a)->next_link != NULL)
		*head_a = swap_a(*head_a);
	if ((*head_b)->next_link != NULL)
		*head_b = swap_b(*head_b);
}