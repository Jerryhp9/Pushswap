/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhor <jhor@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 17:07:04 by jhor              #+#    #+#             */
/*   Updated: 2025/05/12 17:07:04 by jhor             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

nodes *create_nodes(nodes *head, int data)
{
	nodes *temp;
	temp = malloc(sizeof(nodes));
	if (!temp)
		return (NULL);
	temp->prev_link = NULL;
	temp->data = data;
	temp->next_link = NULL;
	head = temp;
	return (head);
}
nodes *last_node(nodes *head, int data)
{
	nodes *temp;
	nodes *tp;
	temp = malloc(sizeof(nodes));
	if (!temp)
		return (NULL);
	temp->prev_link = NULL;
	temp->data = data;
	temp->next_link = NULL;
	tp = head;
	while(tp->next_link != NULL)
		tp = tp->next_link;
	temp->prev_link = tp;
	tp->next_link = temp;
	// tp = head->next_link;
	// temp->prev_link = tp;
	// tp = head;
	// temp = NULL;
	return (head);
}
int *convert_int(int argc, char **argv)
{
	int	i;
	int	j;
	int *data;

	i = 1;
	j = 0;
	data = malloc(sizeof(int) * (argc - 1));
	if (!data)
		return NULL;
	while (i < argc)
	{
		data[j] = ft_atoi(argv[i]);
		i++;
		j++;
	}
	return (data);
}

nodes	*command_nodes(int *data, int argc, char **argv)
{
	nodes	*head;
	nodes	*body;
	int		i;

	head = NULL;
	i = 0;
	if (argv == NULL || argv[1] == NULL)
		return (0);
	data = convert_int(argc, argv);
	if (!data)
		return (0);
	(void)argc;
	if (argv[1])
		head = create_nodes(head, data[i]);
	body = head;
	while (argv[i + 2])
	{
		body = last_node(body, data[i + 1]);
		i++;
	}
	free(data);
	body = NULL;
	return (head);
}


int main(int argc, char **argv)
{
	int		*data;;
	nodes	*temp;
	nodes	*new_temp;
	nodes	*temp2;
	data = 0;
	temp2 = NULL;
	temp = command_nodes(data, argc, argv);
	// ft_lstiter(temp, print_content);
	new_temp = swap_a(temp);
	// ft_lstiter(new_temp, print_content);
	new_temp = rotate_a(new_temp);
	// ft_lstiter(new_temp, print_content);
	new_temp = r_rotate_a(new_temp);
	// ft_lstiter(new_temp, print_content);
	// printf("\n");
	// ft_lstiter(temp2, print_content);
	push_b(&new_temp, &temp2);
	// ft_lstiter(temp2, print_content);
	// printf("\n");
	// ft_lstiter(new_temp, print_content);
	push_b(&new_temp, &temp2);
	// printf("\n");
	// ft_lstiter(temp2, print_content);
	// printf("\n");
	// ft_lstiter(new_temp, print_content);
	// printf("\n");
	temp2 = swap_b(temp2);
	// ft_lstiter(temp2, print_content);
	push_b(&new_temp, &temp2);
	// ft_lstiter(temp2, print_content);
	// printf("\n");
	// ft_lstiter(new_temp, print_content);
	// printf("\n");
	temp2 = rotate_b(temp2);
	// ft_lstiter(temp2, print_content);
	// printf("\n");
	temp2 = r_rotate_b(temp2);
	// ft_lstiter(temp2, print_content);
	// printf("\n");
	// ft_lstiter(new_temp, print_content);
	// printf("\n");
	// push_a(&new_temp, &temp2);
	// ft_lstiter(temp2, print_content);
	// printf("\n");
	// ft_lstiter(new_temp, print_content);
	// temp2 = swap_b(temp2);
	// push_a(&new_temp, &temp2);
	// printf("\n");
	// ft_lstiter(new_temp, print_content);
	// printf("\n");
	// push_a(&new_temp, &temp2);
	// ft_lstiter(new_temp, print_content);
	// printf("\n");
	swap_s (&new_temp, &temp2);
	// ft_lstiter(new_temp, print_content);
	// printf("\n");
	ft_lstiter(temp2, print_content);
	printf("\n");
	r_rotate_r(&new_temp, &temp2);
	ft_lstiter(temp2, print_content);
	printf("\n");
	// ft_lstiter(new_temp, print_content);
	free_nodes(temp2);
	free_nodes(new_temp);
	return (0);
}