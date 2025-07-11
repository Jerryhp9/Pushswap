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

void	last_node(nodes *head, int data)
{
	nodes *temp;
	nodes *tp;
	temp = malloc(sizeof(nodes));
	if (!temp)
		return;
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
	// return (*head);
}

// int *convert_int(int argc, char **argv)
// {
// 	int	i;
// 	int	j;
// 	int *data;

// 	i = 1;
// 	j = 0;
// 	data = malloc(sizeof(int) * (argc - 1));
// 	if (!data)
// 		return NULL;
// 	while (i < argc)
// 	{
// 		data[j] = ft_atoi(argv[i]);
// 		i++;
// 		j++;
// 	}
// 	return (data);
// }

void	fail_data(long *data, int count)
{
	if (exceed_int(data, count))
	{
		free(data);
		exit(1);
	}
}

nodes	*command_nodes(long *data, int argc, char **argv)
{
	nodes	*head;
	int		i;
	int		count;

	head = NULL;
	i = 1;
	if (argc < 2)
		return (0);
	data = parse_long(argc, argv, &count);
	fail_data(data, count);
	if (!data)
		return (0);
	if (duplicate(data, count))
	{
		free(data);
		exit(1);
	}
	head = create_nodes(head, data[0]);
	while (i < count)
	{
		last_node(head, data[i]);
		i++;
	}
	free(data);
	return (head);
}

// int main(int argc, char **argv)
// {
// 	nodes *head;

// 	head = NULL;
// 	long *data = {0};
// 	head = command_nodes(data, argc, argv);
// 	ft_lstiter(head, print_content);
// 	free_nodes(head);
// }

int main(int argc, char **argv)
{
	long		*data;
	nodes		*stk_a;
	nodes		*stk_b;
	// int			size;
	// int i = 0;
	// nodes		*pmin;
	t_container	stack;
	// t_split		split;
	// nodes		*start;
	// t_chunk		chunk;
	
	if (argc == 1)
		return (0);
	data = 0;
	stk_b = NULL;
	// pmin = NULL;
	stk_a = command_nodes(data, argc, argv);
	stack = init(stk_a, stk_b); //TODO: understand the flow of the struct stack
	data = index_data(data, argc, argv);
	printf("%ld\n", data[0]);
	printf("%ld\n", data[1]);
	printf("%ld\n", data[2]);
	printf("%ld\n", data[3]);
	printf("%ld\n", data[4]);
	printf("%ld\n", data[5]);
	printf("%ld\n", data[6]);
	printf("%ld\n", data[7]);
	innit_chunk_proper(&stack);
	// while (i < argc - 1)
	// {
	// 	printf("%d\n", data[i]);
	// 	i++;
	// }
	// compare_split(data, argc, &stack, &split);
	// ft_lstiter(stack.pstk_a, print_content);
	// printf("\n");
	// ft_lstiter(stack.pstk_b, print_content);
	// printf("\n");
	// if (stack.max.location == TOP_A)
	// 	printf("Hello");
	// start = find_start_node(&stack, &stack.max);
	// if (stack.a_counter == 3)
	// 	n_sort3(&stack); //!uncomment later
	// if (stack.a_counter == 5)
	// 	sort5(&stack); //!uncomment later
	// printf("chunk location is +%d+\n", stack.origin_max.location);
	stack.origin_chunk = origin_size(&stack);
	printf("the size is %d\n", stack.origin_chunk.size);
	printf("the location is %d\n", stack.origin_chunk.location);
	// quick_sort(&stack, &stack.origin_chunk, &split); //!uncomment later
	// ft_lstiter(stack.pstk_a, print_content);
	// printf("\n");
	// ft_lstiter(stack.pstk_b, print_content);
	// printf("\n");
	free_nodes(stack.pstk_a);
	// free_nodes(stack.pstk_b);
	free(data);
	return (0);
}