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
	// nodes	*body;
	int		i;

	head = NULL;
	i = 1;
	if (argc < 2)
		return (0);
	data = convert_int(argc, argv);
	if (!data)
		return (0);
	// (void)argc;
	// if (argv[1])
	head = create_nodes(head, data[0]);
	// body = head;
	while (i < argc - 1)
	{
		last_node(&head, data[i]);
		i++;
	}
	free(data);
	// body = NULL;
	return (head);
}


int main(int argc, char **argv)
{
	int			*data;
	nodes		*stk_a;
	nodes		*stk_b;
	// int			size;
	// int i = 0;
	// nodes		*pmin;
	t_container	stack;
	t_split		split;
	// nodes		*start;
	// t_chunk		chunk;

	data = 0;
	stk_b = NULL;
	// printf("address of origin_max %p\n", &stack.origin_max);
	// pmin = NULL;
	stk_a = command_nodes(data, argc, argv);
	stack = init(stk_a, stk_b); //understand the flow of the struct stack
	data = convert_int(argc, argv);
	data = index_nodes(data, argc, argv);
	// while (i < argc - 1)
	// {
	// 	printf("%d\n", data[i]);
	// 	i++;
	// }
	compare_split(data, argc, &stack, &split);
	// ft_lstiter(stack.pstk_a, print_content);
	// printf("\n");
	// ft_lstiter(stack.pstk_b, print_content);
	// printf("\n");
	// if (stack.max.location == TOP_A)
	// 	printf("Hello");
	// start = find_start_node(&stack, &stack.max);
	quick_sort(&stack, &stack.origin_max, &split);
	quick_sort(&stack, &stack.origin_mid, &split);
	quick_sort(&stack, &stack.origin_min, &split);
	// ft_lstiter(stack.pstk_a, print_content);
	// printf("\n");
	// ft_lstiter(stack.pstk_b, print_content);
	// printf("\n");
	free_nodes(stack.pstk_a);
	// free_nodes(stack.pstk_b);
	free(data);
	return (0);
}