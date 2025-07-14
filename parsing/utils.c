/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhor <jhor@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 21:12:31 by jhor              #+#    #+#             */
/*   Updated: 2025/07/14 21:23:12 by jhor             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

char	*ft_strjoin_free(char *s1, char *s2)
{
	char	*new;

	new = NULL;
	new = ft_strjoin(s1, s2);
	free(s1);
	return (new);
}

char	*join_args(int argc, char **argv)
{
	char	*join;
	int		i;

	join = ft_strdup("");
	i = 1;
	while (i < argc)
	{
		join = ft_strjoin_free(join, argv[i]);
		join = ft_strjoin_free(join, " ");
		i++;
	}
	return (join);
}

int	token_count(char **tokens)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (tokens[i] != NULL)
	{
		i++;
		count++;
	}
	return (count);
}
