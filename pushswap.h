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
	int min_count;
	int mid_count;
	int max_count;
} t_chunk;

typedef struct s_container {
	nodes *pstk_a;
	nodes *pstk_b;
	int is_combine;
	int a_counter;
	int b_counter;
	t_chunk	min;
	t_chunk	mid;
	t_chunk	max;
	t_chunk origin_chunk;
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
	int	pivotS;
	int pivotB;
} t_split;

typedef struct s_parse {
	long	*data;
	char	*joined;
	char	**tokens;
	int		count;
	int		i;
} t_parse;

int			ft_atoi(const char *str);
nodes		*command_nodes(long *data, int argc, char **argv);
void		last_node(nodes *head, int data);
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
void		sort2(t_container *stack);
void		n_sort3(t_container *stack);
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
long		*index_data(long *data, int argc, char **argv);
long		*index_nodes(long *data, int count);
t_split		*innit_chunk(int argc, t_split *split);
t_container	*innit_stack(t_container *stack, t_split *split);
void		compare_split(int *data, int argc, t_container *stack, t_split *split);
t_container	*apply_split_chunk(t_container *stack, t_split *split);
void		TopA_sender(t_container *stack, t_chunk *chunk, t_split *split);
void		BotA_sender(t_container *stack, t_chunk *chunk, t_split *split);
void		TopB_sender(t_container *stack, t_chunk *chunk, t_split *split);
void		BotB_sender(t_container *stack, t_chunk *chunk, t_split *split);
void		sender(t_container *stack, t_chunk *chunk);
void		send_top_sort(t_container *stack, t_chunk *chunk);
void		quick_sort(t_container *stack, t_chunk *chunk, t_split *split);
void		recursive_split(t_container *stack, t_chunk *chunk, t_split *split, nodes *start);
int			*compare_max_chunk(t_container *stack, t_chunk *chunk);
int			*chunk_presort(int *data, t_container *stack, t_chunk *chunk);
nodes 		*find_start_node(t_container *stack, t_chunk *chunk);
int			find_max_int(int *data, t_chunk *chunk);
int			find_min_int(int *data, t_chunk *chunk);
t_chunk		*innit_chunk_recurse(t_chunk *chunk);
void		innit_chunk_proper(t_container *stack);
int			invalid_argument(char *token);
int			exceed_int(long *data, int count);
int			duplicate(long *data, int count);
long 		*parse_long(int argc, char **argv, int *counter);
void		free_fail(long *data, char *joined, char **tokens);
t_chunk 	origin_size(t_container *stack);
// voidchunk_checker(t_container *stack);
// void		locate_chunk(t_container *stack);
// const char	*get_location_name(enum e_loc loc);

#endif