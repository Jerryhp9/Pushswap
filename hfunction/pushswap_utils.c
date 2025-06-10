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
	nodes	*data;
	
	data = ((nodes *)content);
	printf("%d\n", data->data);
}

void	free_data(int *data)
{
	int i;

	i = 0;
	while (data[i])
	{
		free(data + i);
		i++;
	}
	printf("\n");
}

void	free_nodes(nodes *head)
{
	nodes* temp;
	while (head->next_link != NULL)
	{
		temp = head;
		head = head->next_link;
		free(temp);
	}
	free(head);
}

t_container	init (nodes *stk_a, nodes *stk_b)
{
	t_container container;

	container.pstk_a = stk_a;
	container.pstk_b = stk_b;
	container.is_combine = 0;
	container.min.size = 0;
	container.mid.size = 0;
	container.max.size = 0;
	return (container);
}

// nodes *free_firstnode(nodes *head)
// {
// 		nodes *temp;
	
// 	temp = head;
// 	head = head->next_link;
// 	free(temp);
// 	temp = NULL;
// 	head->prev_link = NULL;
// 	return (head);
// }

// void free_nodes(nodes *head)
// {
// 	nodes *temp;
// 	nodes *temp2;
// 	temp = head;
// 	while (temp->next_link != NULL)
// 		temp = temp->next_link;	
// 	temp2 = temp->prev_link;
// 	free(temp);
// 	temp = NULL;
// 	temp2->next_link = NULL;
// 	if (temp == NULL)
// 		temp = temp2->prev_link;
// 	while (temp->prev_link != NULL || temp2->prev_link != NULL)
// 	{
// 		free(temp2);
// 		temp2 = NULL;
// 		temp->next_link = NULL;
// 		temp2 = temp->prev_link;
// 		free(temp);
// 		temp = NULL;
// 		temp2->next_link = NULL;
// 		temp = temp2->prev_link;
// 	}
// }
