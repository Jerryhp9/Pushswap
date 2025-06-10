/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recursive_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhor <jhor@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 15:50:06 by jhor              #+#    #+#             */
/*   Updated: 2025/06/03 15:50:06 by jhor             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

int	*index_nodes(int *data, int argc, char **argv)
{
	int	i;
	int	j;
	int	temp;
	(void)argv;

	i = 0;
	while (i < argc - 1)
	{
		j = 0;
		while (j < argc - 2 - i)
		{
			if (data[j] > data[j + 1])
			{
				temp = data[j];
				data[j] = data[j + 1];
				data[j + 1] = temp;
			}
			j++;
		}
		i++;
	}
	return (data);
}




