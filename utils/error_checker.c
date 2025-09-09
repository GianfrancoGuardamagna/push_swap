/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_checker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguardam <gguardam@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 14:41:50 by gguardam          #+#    #+#             */
/*   Updated: 2025/09/09 14:41:51 by gguardam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	*tokens_to_ints(char **tokens)
{
	int	*values;
	int	i;
	int	size;

	i = 0;
	while (tokens[i])
		i++;
	size = i;
	i = 0;
	values = malloc(sizeof(int) * (size + 1));
	if (!values)
		return (0);
	while (tokens[i])
	{
		if ((ft_atol(tokens[i]) > 2147483647) \
|| (ft_atol(tokens[i]) < -2147483648))
		{
			free(values);
			return (0);
		}
		values[i] = ft_atoi(tokens[i]);
		i++;
	}
	values[i] = '\0';
	return (values);
}

void	free_split(char **tokens)
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

static int	has_duplicates(char **tokens, int *values)
{
	int	i;
	int	j;
	int	size;

	if (!tokens || !values)
		return (1);
	i = 0;
	while (tokens[i])
		i++;
	size = i;
	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (values[j] == values[i])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

static int	only_digits(char **tokens)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (tokens[i])
	{
		while (tokens[i][j])
		{
			if (!ft_isdigit(tokens[i][j]) &&\
!(ft_issign(tokens[i][j]) && j == 0))
				return (0);
			j++;
		}
		j = 0;
		i++;
	}
	return (1);
}

int	error_checker(char **argv)
{
	char	**tokens;
	int		*values;
	int		error_flag;

	error_flag = 0;
	tokens = ft_split(argv[1], ' ');
	if (!tokens)
		return (1);
	if (!only_digits(tokens))
	{
		error_flag = 1;
		free_split(tokens);
	}
	values = tokens_to_ints(tokens);
	if (!values)
	{
		error_flag = 1;
		free(values);
	}
	if (has_duplicates(tokens, values))
		error_flag = 1;
	free(values);
	free_split(tokens);
	return (error_flag);
}
