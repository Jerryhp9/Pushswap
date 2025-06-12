/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhor <jhor@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 16:13:35 by jhor              #+#    #+#             */
/*   Updated: 2025/05/12 16:13:35 by jhor             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
#define PUSHSWAP_H

#include <stdio.h>
#include <stdlib.h>
#include "Libft/libft.h"

enum	e_loc {
	TOP_A,
	BOTTOM_A,
	TOP_B,
	BOTTOM_B,
};

typedef struct s_chunk {
	enum e_loc location;
	int size;
} t_chunk;

typedef struct s_container {
	nodes *pstk_a;
	nodes *pstk_b;
	int is_combine;
	t_chunk	min;
	t_chunk	mid;
	t_chunk	max;
	t_chunk origin;
} t_container;


// typedef struct s_cato {
// 	t_chunk	min;
// 	t_chunk	mid;
// 	t_chunk	max;
// } t_cato;

typedef struct s_split {
	int	size;
	int	pivot1;
	int	pivot2;
	int	i;
	int	rank;
	int	val;
	int	pivotsmall;
	int pivotbig;
} t_split;

int			ft_atoi(const char *str);
nodes		*command_nodes(int *data, int argc, char **argv);
void		last_node(nodes **head, int data);
void		swap_a(t_container *stack);
void		swap_b(t_container *stack);
void		swap_s(t_container *stack);
void		rotate_a(t_container *stack);
void		rotate_b(t_container *stack);
void		rotate_r(t_container *stack);
void		r_rotate_a(t_container *stack);
void		r_rotate_b(t_container *stack);
void		r_rotate_r(t_container *stack);
void		push_a(t_container *stack);
void		push_b(t_container *stack);
void		print_content(void *content);
void		sort3(t_container *stack);
void		sort5(t_container *stack);
nodes		*find_min(nodes *pmin, t_container *stack);
nodes		*find_max(nodes	*pmax, t_container *stack);
int			move_top(int position, nodes *ptr, t_container *stack);
void		position_a(int position, t_container *stack);
void		position_b(int position, t_container *stack);
void		free_data(int *data);
void		free_nodes(nodes *head);
t_container	init (nodes *stk_a, nodes *stk_b);
int			*index_nodes(int *data, int argc, char **argv);
t_split		*innit_chunk(int argc, t_split *split);
void		compare_split(int *data, int argc, t_container *stack, t_split *split);
void		apply_split_chunk(t_container *stack, t_split *split);
// void		locate_chunk(t_container *stack);
// const char	*get_location_name(enum e_loc loc);

#endif