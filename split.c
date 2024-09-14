/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victor <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 20:05:31 by victor            #+#    #+#             */
/*   Updated: 2024/09/11 13:20:32 by victor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	count_words(char *s, char c)
{
	int		count;
	t_bool	inside_word;

	count = 0;
	inside_word = false;
	while (*s)
	{
		inside_word = false;
		while (*s == c)
			++s;
		while (*s != c && *s)
		{
			if (!inside_word)
			{
				++count;
				inside_word = true;
			}
			++s;
		}
	}
	return (count);
}

static char	*get_next_word(char *s, char c, int *cursor)
{
	char		*next_word;
	int			len;
	int			i;

	len = 0;
	i = 0;
	while (s[*cursor] == c)
		++(*cursor);
	while (s[*cursor + len] != c && s[*cursor + len])
		++len;
	next_word = malloc((size_t)len * sizeof(char) + 1);
	if (!next_word)
		return (NULL);
	while (s[*cursor] != c && s[*cursor])
		next_word[i++] = s[(*cursor)++];
	next_word[i] = '\0';
	return (next_word);
}

void	free_splited_str(char **splited_str)
{
	int	i;

	i = 0;
	if (!splited_str)
		return ;
	while (splited_str[i] != NULL)
	{
		free(splited_str[i]);
		i++;
	}
	free(splited_str);
}

char	**split(char *s, char c)
{
	int		i;
	int		words;
	int		cursor;
	char	**res;

	i = 0;
	cursor = 0;
	words = count_words(s, c);
	res = malloc((words + 1) * sizeof(char *));
	if (!res)
		return (NULL);
	while (i < words)
	{
		res[i] = get_next_word(s, c, &cursor);
		if (!res[i])
		{
			free_splited_str(res);
			return (NULL);
		}
		i++;
	}
	res[i] = NULL;
	return (res);
}
