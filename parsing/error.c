/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhor <jhor@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 16:34:58 by jhor              #+#    #+#             */
/*   Updated: 2025/07/07 16:34:58 by jhor             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

int	invalid_argument(char *token)
{
	int	i;

	i = 0;
	if (token[i] == '-' && (token[i + 1] >= '0' && token[i + 1] <= '9'))
		i++;
	while (token[i])
	{
		if (token[i] < '0' || token[i] > '9')
		{
			ft_putstr_fd("Error\n", 2);
			return (1);
		}
		i++;
	}
	return (0);
}

int	exceed_int(long *data, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		if (data[i] > INT_MAX || data[i] < INT_MIN)
		{
			ft_putstr_fd("Error\n", 2);
			return (1);
		}
		i++;
	}
	return (0);
}

int	duplicate(long *data, int count)
{
	int		i;
	int		j;
	int		first;

	i = 0;
	first = 1;
	while (i < count)
	{
		if (first == 1)
			j = 1;
		else
			j = i + 1;
		while (j < count)
		{
			if (data[j] == data[i])
			{
				ft_putstr_fd("Error\n", 2);
				return (1);
			}
			first = 0;
			j++;
		}
		i++;
	}
	return (0);
}
