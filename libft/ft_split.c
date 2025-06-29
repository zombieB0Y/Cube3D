/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zoentifi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 17:54:23 by zoentifi          #+#    #+#             */
/*   Updated: 2024/11/04 03:13:34 by zoentifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
	word = (char *)malloc(sizeof(char) * (len + 1));
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

static void	free_result(char **result, size_t count)
{
	size_t	i;

	i = 0;
	while (i < count)
		free(result[i++]);
	free(result);
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
		{
			free_result(result, j);
			return (NULL);
		}
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
	result = (char **)malloc(sizeof(char *) * (word_count + 1));
	if (!result)
		return (NULL);
	return (split_words(s, c, result, word_count));
}
/*int main()
{
	char	**arr;
	char	*src;
	int		i;

	src = "hello wolrd!";
	i = 0;
	arr = ft_split(src, ' ');
	if (!arr)
	{
		printf("malloc fail\n");
		return (0);
	}
	while (arr[i])
	{
		printf("%s\n", arr[i]);
		i++;
	}
	ft_free(arr, i);
	return (0);
}
malloc fail
static char	*word(const char *s, char c, int *i)
{
    char    *arr;
    int     j;
    static int  call_count = 0;

    j = 0;
    while (s[(*i)] && s[(*i)] != c)
    {
        (*i)++;
        j++;
    }
    (*i) -= j;
    // Force malloc to fail on the second word
    call_count++;
    if (call_count == 2)
        return (NULL);  // Simulate malloc failure
    arr = (char *)malloc(sizeof(char) * (j + 1));
    if (!arr)
        return (NULL);
    j = 0;
    while (s[(*i)] && s[(*i)] != c)
    {
        arr[j] = s[(*i)];
        j++;
        (*i)++;
    }
    arr[j] = '\0';
    return (arr);
}*/
