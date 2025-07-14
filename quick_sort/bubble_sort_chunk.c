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

long	*index_data(long *data, int argc, char **argv)
{
	int	count;
	

	count = 0;
	data = parse_long(argc, argv, &count);
	if (!data)
		exit(1);
	data = index_nodes(data, count);
	return (data);
}

long	*index_nodes(long *data, int count)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	while (i < count)
	{
		j = 0;
		while (j < count - 1 - i)
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




