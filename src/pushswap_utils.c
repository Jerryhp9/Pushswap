/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhor <jhor@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 16:12:29 by jhor              #+#    #+#             */
/*   Updated: 2025/05/12 16:12:29 by jhor             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

void print_content(void *content)
{
	nodes	*data;
	
	data = ((nodes *)content);
	printf("%d\n", data->data);
}

void free_data(int *data)
{
	int i;

	i = 0;
	while (data[i])
	{
		free(data);
		i++;
	}
}
