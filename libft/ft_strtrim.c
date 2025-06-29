/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zoentifi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 00:05:04 by zoentifi          #+#    #+#             */
/*   Updated: 2024/11/04 00:20:16 by zoentifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_trimloop(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
		if (c == set[i++])
			return (1);
	return (0);
}

static char	*ft_trimarr(char const *s1, int i, int j)
{
	char	*arr;
	int		z;

	z = 0;
	arr = NULL;
	if (i > j)
	{
		arr = (char *)malloc(sizeof(char) * 1);
		if (!arr)
			return (NULL);
		*arr = '\0';
	}
	else
	{
		arr = (char *)malloc(sizeof(char) * (j - i + 2));
		if (!arr)
			return (NULL);
		while (i <= j)
			arr[z++] = s1[i++];
		arr[z] = '\0';
	}
	return (arr);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int	flag;
	int	i;
	int	j;

	if (!s1 || !set)
		return (NULL);
	flag = 1;
	i = 0;
	j = 0;
	while (s1[i] && flag)
	{
		flag = ft_trimloop(s1[i], set);
		if (flag)
			i++;
	}
	flag = 1;
	j = ft_strlen(s1);
	j--;
	while (j > 0 && flag)
	{
		flag = ft_trimloop(s1[j], set);
		if (flag)
			j--;
	}
	return (ft_trimarr(s1, i, j));
}
