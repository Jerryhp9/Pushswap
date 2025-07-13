/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort5.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhor <jhor@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 16:45:10 by jhor              #+#    #+#             */
/*   Updated: 2025/06/02 16:45:10 by jhor             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

int	move_top(int position, nodes *ptr, t_container *stack)
{
	nodes	*temp;

	temp = stack->pstk_a;
	while (temp)
	{
		if (temp == ptr)
			return (position);
		else if (temp != ptr)
			position++;
		temp = temp->next_link;
	}
	return 0;
}


void	position_a(int position, t_container *stack)
{
	if (position == 0)
		push_b(stack);
	if (position == 1)
	{
		swap_a(stack);
		push_b(stack);
	}
	if (position == 2)
	{
		rotate_a(stack);
		rotate_a(stack);
		push_b(stack);
	}
	if (position == 3)
	{
		r_rotate_a(stack);
		r_rotate_a(stack);
		push_b(stack);
	}
	if (position == 4)
	{
		r_rotate_a(stack);
		push_b(stack);
	}
}

void	position_b(int position, t_container *stack)
{
	if (position == 0)
		push_b(stack);
	if (position == 1)
	{
		swap_a(stack);
		push_b(stack);
	}
	if (position == 2)
	{
		rotate_a(stack);
		rotate_a(stack);
		push_b(stack);
	}
	if (position == 3)
	{
		r_rotate_a(stack);
		push_b(stack);
	}
}


nodes	*find_min(nodes	*pmin, t_container *stack)
{
	nodes	*travel;
	int		num;

	pmin = stack->pstk_a;
	travel = stack->pstk_a->next_link;
	num = pmin->data;
	while (travel)
	{
		if (travel->data < num)
		{
			num = travel->data;
			pmin = travel;
		}
		travel = travel->next_link;
	}
	return (pmin);
}

nodes	*find_max(nodes *pmax, t_container *stack)
{
	nodes	*travel;
	int		num;
	
	pmax = stack->pstk_a;
	travel = stack->pstk_a->next_link;
	num = stack->pstk_a->data;
	while (travel)
	{
		if (travel->data > num)
		{
			num = travel->data;
			pmax = travel;
		}
		travel = travel->next_link;
	}
	return (pmax);
}

void	sort5(t_container *stack)
{
	nodes	*min;
	nodes	*max;
	int		position;
	nodes	*temp;

	min = NULL;
	max = NULL;
	position = 0;
	min = find_min(min, stack);
	position = move_top(position, min, stack);
	position_a(position, stack);
	position = 0;
	max = find_max(max, stack);
	position = move_top(position, max, stack);
	position_b(position, stack);
	temp = stack->pstk_b->next_link;
	n_sort3(stack);
	if (stack->pstk_b->data > temp->data)
		swap_b(stack);
	push_a(stack);
	push_a(stack);
	rotate_a(stack);
}
