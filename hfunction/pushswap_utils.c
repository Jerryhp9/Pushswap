/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhor <jhor@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 16:12:29 by jhor              #+#    #+#             */
/*   Updated: 2025/05/12 16:12:29 by jhor             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

void	print_content(void *content)
{
	t_nodes	*data;

	data = ((t_nodes *)content);
	printf("%d\n", data->data);
}

void	free_data(int *data)
{
	int	i;

	i = 0;
	while (data[i])
	{
		free(data + i);
		i++;
	}
}

void	free_nodes(t_nodes *head)
{
	t_nodes	*temp;

	while (head->next_link != NULL)
	{
		temp = head;
		head = head->next_link;
		free(temp);
	}
	free(head);
}

t_container	init(t_nodes *stk_a, t_nodes *stk_b)
{
	t_container	container;

	container.pstk_a = stk_a;
	container.pstk_b = stk_b;
	container.is_combine = 0;
	container.min.size = 0;
	container.mid.size = 0;
	container.max.size = 0;
	return (container);
}
