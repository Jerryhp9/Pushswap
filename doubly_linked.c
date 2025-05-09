/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doubly_linked.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhor <jhor@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 21:13:59 by jhor              #+#    #+#             */
/*   Updated: 2025/05/07 21:13:59 by jhor             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

typedef struct typenodes {
	struct typenodes *prev_link;
	int data;
	struct typenodes *next_link;
} nodes;

nodes *create_nodes(nodes *head, int data)
{
	nodes *temp;
	temp = malloc(sizeof(nodes));
	temp->prev_link = NULL;
	temp->data = data;
	temp->next_link = NULL;
	head = temp;
	return (head);
}
nodes *beginning_node(nodes *head, int data)
{
	nodes *temp = malloc(sizeof(nodes));
	temp->prev_link = NULL;
	temp->data = data;
	temp->next_link = NULL;
	temp->next_link = head;
	head->prev_link = temp;
	head = temp;
	return (head);
}

nodes *last_node(nodes *head, int data)
{
	nodes *temp;
	nodes *tp;
	temp = malloc(sizeof(nodes));
	temp->prev_link = NULL;
	temp->data = data;
	temp->next_link = NULL;
	tp = head;
	while (tp->next_link != NULL)
		tp = tp->next_link;
	temp->prev_link = tp;
	tp->next_link = temp;
	// tp = head->next_link;
	// temp->prev_link = tp;
	// tp = head;
	return (head);
}

nodes *intermediate_node(nodes *head, int data, int position)
{
	nodes *newp;
	nodes *temp;
	nodes *temp2;

	newp = create_nodes(newp, data);
	temp = head;
	temp2 = NULL;
	while (position != 1)
	{
		temp = temp->next_link;
		position--;
	}
	if (temp->next_link == NULL)
	{
		newp->prev_link = temp;
		temp->next_link = newp;
	}
	else
	{
		temp2 = temp->next_link;
		newp->prev_link = temp;
		newp->next_link = temp2;
		temp->next_link = newp;
		temp2->prev_link = newp;
	}
	return (head);
}

int main()
{
	nodes *head;
	nodes *ptr;

	head = create_nodes(head, 5000);
	head = beginning_node(head, 4000);
	head = last_node(head, 6000);
	head = intermediate_node(head, 5500, 2);
	ptr = head;
	while(ptr)
	{
		printf("%d \n", ptr->data);
		ptr = ptr->next_link;
	}
	return 0;
}