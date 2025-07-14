/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhor <jhor@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 18:55:58 by jhor              #+#    #+#             */
/*   Updated: 2025/07/09 18:55:58 by jhor             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

void	free_tokens(char **tokens)
{
	int	i;

	i = 0;
	while (tokens[i])
	{
		free(tokens[i]);
		i++;
	}
	free(tokens);
}

void	free_fail(long *data, char *joined, char **tokens)
{
	free(joined);
	free_tokens(tokens);
	free(data);
}

void	innit(long **data, char **joined, char ***tokens, int *count)
{
	data = 0;
	joined = NULL;
	tokens = NULL;
	count = 0;
}

void	free_parse_long(char *joined, char **tokens)
{
	free(joined);
	free_tokens(tokens);
}

long	*parse_long(int argc, char **argv, int *counter)
{
	long	*data;
	char	*joined;
	char	**tokens;
	int		count;
	int		i;

	innit(&data, &joined, &tokens, &count);
	i = 0;
	joined = join_args(argc, argv);
	tokens = ft_split(joined, ' ');
	count = token_count(tokens);
	data = malloc(sizeof(long) * count);
	while (i < count)
	{
		if (invalid_argument(tokens[i]))
		{
			free_fail(data, joined, tokens);
			exit(1);
		}
		data[i] = ft_atol(tokens[i]);
		i++;
	}
	*counter = count;
	free_parse_long(joined, tokens);
	return (data);
}
