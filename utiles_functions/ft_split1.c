/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zoentifi <zoentifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 19:34:07 by zoentifi          #+#    #+#             */
/*   Updated: 2025/09/20 20:37:04 by zoentifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

static size_t	count_words1(char const *s, char c)
{
	size_t	count;
	int		in_word;
	int		i;

	count = 0;
	in_word = 0;
	i = 0;
	while (*s)
	{
		if (*s != c && !in_word)
		{
			in_word = 1;
			count++;
		}
		else if (*s == c)
			in_word = 0 * i++;
		if (!ft_isdigit(*s) && *s != c)
			return (0 * printf("Invalid character found: %d\n", *s));
		s++;
	}
	if (i != 2)
		return (0);
	return (count);
}

static char	*make_word1(char const *s, char c)
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

static char	**split_words1(char const *s, char c, char **result,
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
		result[j] = make_word1(s + i, c);
		if (!result[j])
			return (NULL);
		while (s[i] && s[i] != c)
			i++;
		j++;
	}
	result[word_count] = NULL;
	return (result);
}

char	**ft_split1(char *s, char c)
{
	char	**result;
	size_t	word_count;
	int		i;

	if (!s)
		return (NULL);
	i = ft_strlen(s);
	s[i - 1] = '\0';
	word_count = count_words1(s, c);
	if (!word_count)
		return (NULL);
	result = (char **)gc_malloc(sizeof(char *) * (word_count + 1));
	if (!result)
		return (NULL);
	return (split_words1(s, c, result, word_count));
}
