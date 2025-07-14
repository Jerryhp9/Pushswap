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

#include "../pushswap.h"

t_nodes	*create_nodes(t_nodes *head, int data)
{
	t_nodes	*temp;

	temp = malloc(sizeof(t_nodes));
	if (!temp)
		return (NULL);
	temp->prev_link = NULL;
	temp->data = data;
	temp->next_link = NULL;
	head = temp;
	return (head);
}

void	last_node(t_nodes *head, int data)
{
	t_nodes	*temp;
	t_nodes	*tp;

	temp = malloc(sizeof(t_nodes));
	if (!temp)
		return ;
	temp->prev_link = NULL;
	temp->data = data;
	temp->next_link = NULL;
	tp = head;
	while (tp->next_link != NULL)
		tp = tp->next_link;
	temp->prev_link = tp;
	tp->next_link = temp;
}

void	fail_data(long *data, int count)
{
	if (exceed_int(data, count))
	{
		free(data);
		exit(1);
	}
}

t_nodes	*command_nodes(long *data, int argc, char **argv)
{
	t_nodes	*head;
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

int	main(int argc, char **argv)
{
	long		*data;
	t_nodes		*stk_a;
	t_nodes		*stk_b;
	t_container	stack;
	t_split		split;

	if (argc == 1)
		return (0);
	if (argv[1][0] == '\0')
	{
		ft_putstr_fd("Error\n", 2);
		return (1);
	}
	data = 0;
	stk_b = NULL;
	stk_a = command_nodes(data, argc, argv);
	stack = init(stk_a, stk_b);
	data = index_data(data, argc, argv);
	stack.origin_chunk = origin_size(&stack);
	innit_chunk_proper(&stack);
	quick_sort(&stack, &stack.origin_chunk, &split);
	free_nodes(stack.pstk_a);
	free(data);
	return (0);
}
