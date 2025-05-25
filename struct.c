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
void	last_node(nodes **head, int data)
{
	nodes *temp;
	nodes *tp;
	temp = malloc(sizeof(nodes));
	if (!temp)
		return;
	temp->prev_link = NULL;
	temp->data = data;
	temp->next_link = NULL;
	tp = *head;
	while(tp->next_link != NULL)
		tp = tp->next_link;
	temp->prev_link = tp;
	tp->next_link = temp;
	// tp = head->next_link;
	// temp->prev_link = tp;
	// tp = head;
	// temp = NULL;
	// return (*head);
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
	// nodes	*body
	int		i;

	head = NULL;
	i = 0;
	if (argc < 2)
		return (0);
	data = convert_int(argc, argv);
	if (!data)
		return (0);
	// (void)argc;
	// if (argv[1])
	head = create_nodes(head, data[i]);
	// body = head;
	while (argv[i + 2])
	{
		last_node(&head, data[i + 1]);
		i++;
	}
	free(data);
	// body = NULL;
	return (head);
}


int main(int argc, char **argv)
{
	int		*data;;
	nodes	*stk_a;
	nodes	*stk_b;
	t_container	stack;

	data = 0;
	stk_b = NULL;
	stk_a = command_nodes(data, argc, argv);
	stack = init(stk_a, stk_b); //understand the flow of the struct stack
	push_b(&stack);
	swap_s(&stack);
	push_b(&stack);
	swap_s(&stack);
	push_b(&stack);
	r_rotate_r(&stack);
	rotate_r(&stack);
	push_a(&stack);
	swap_s(&stack);
	push_a(&stack);
	swap_a(&stack);
	push_a(&stack);
	swap_a(&stack);
	ft_lstiter(stack.pstk_a, print_content);
	printf("\n");
	ft_lstiter(stack.pstk_b, print_content);
	printf("\n");
	free_nodes(stack.pstk_a);
	// free_nodes(stack.pstk_b);
	return (0);
}