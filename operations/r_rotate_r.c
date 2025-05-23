/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_rotate_r.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhor <jhor@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 18:47:08 by jhor              #+#    #+#             */
/*   Updated: 2025/05/23 18:47:08 by jhor             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

void r_rotate_r(nodes **head_a, nodes **head_b)
{
	if (*head_a != NULL)
		*head_a = r_rotate_a(*head_a);
	if (*head_b != NULL)
		*head_b = r_rotate_b(*head_b);
}