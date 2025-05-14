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

int		ft_atoi(const char *str);
nodes	*command_nodes(int *data, int argc, char **argv);
void	print_content(void *content);
void	free_data(int *data);





#endif