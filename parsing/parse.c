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

char *ft_strjoin_free(char *s1, char *s2)
{
	char *new;

	new = NULL;
	new = ft_strjoin(s1, s2);
	free(s1);
	return (new);
}

char *join_args(int argc, char **argv)
{
	char	*join;
	int		i;

	join = ft_strdup("");
	// printf("string :%s\n", join);
	i = 1;
	while (i < argc)
	{
		join = ft_strjoin_free(join, argv[i]);
		// printf("string :%s\n", join);
		join = ft_strjoin_free(join, " ");
		i++;
	}
	return (join);
}

int	token_count(char **tokens)
{
	int	i;
	int count;

	i = 0;
	count = 0;
	while (tokens[i] != NULL)
	{
		i++;
		count++;
	}
	return (count);
}

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

// t_parse	innit_parse(t_parse parse)
// {
// 	parse.data = 0;
// 	parse.joined = NULL;
// 	parse.tokens = NULL;
// 	parse.count = 0;
// 	parse.i = 0;

// 	return (parse);
// }

long *parse_long(int argc, char **argv, int *counter)
{
	long	*data;
	char	*joined;
	char	**tokens;
	int		count;
	int		i;
	
	data = 0;
	joined = NULL;
	tokens = NULL;
	count = 0;
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
	free(joined);
	free_tokens(tokens);
	return (data);
}




// int main(int argc, char **argv)
// {
// 	int *data;
// 	data = parse_int(argc, argv);
// 	printf("in int main %d\n", data[0]);
// 	free(data);
// }