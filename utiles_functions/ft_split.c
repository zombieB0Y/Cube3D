/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zoentifi <zoentifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 17:54:23 by zoentifi          #+#    #+#             */
/*   Updated: 2025/07/22 11:58:10 by zoentifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

static size_t	count_words(char const *s, char c)
{
	size_t	count;
	int		in_word;

	count = 0;
	in_word = 0;
	while (*s)
	{
		if (*s != c && !in_word)
		{
			in_word = 1;
			count++;
		}
		else if (*s == c)
			in_word = 0;
		s++;
	}
	return (count);
}

static char	*make_word(char const *s, char c)
{
	char	*word;
	size_t	i;
	size_t	len;

	len = 0;
	while (s[len] && s[len] != c)
		len++;
	word = (char *)gc_malloc(sizeof(char) * (len + 1));
	if (!word)
		return (NULL);
	i = 0;
	while (i < len)
	{
		word[i] = s[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

static char	**split_words(char const *s, char c, char **result,
		size_t word_count)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (j < word_count)
	{
		while (s[i] == c)
			i++;
		result[j] = make_word(s + i, c);
		if (!result[j])
			return (NULL);
		while (s[i] && s[i] != c)
			i++;
		j++;
	}
	result[word_count] = NULL;
	return (result);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	size_t	word_count;

	if (!s)
		return (NULL);
	word_count = count_words(s, c);
	result = (char **)gc_malloc(sizeof(char *) * (word_count + 1));
	if (!result)
		return (NULL);
	return (split_words(s, c, result, word_count));
}
