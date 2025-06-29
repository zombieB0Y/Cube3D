/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zoentifi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 18:00:27 by zoentifi          #+#    #+#             */
/*   Updated: 2024/11/02 18:01:49 by zoentifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*arr;
	int		i;
	int		j;

	if (!s1 || !s2)
		return (NULL);
	i = ft_strlen(s1);
	j = ft_strlen(s2);
	arr = (char *)malloc((sizeof(char) * (i + j)) + 1);
	if (!arr)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
	{
		arr[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		arr[i++] = s2[j];
		j++;
	}
	arr[i] = '\0';
	return (arr);
}

/*int main()
{
	char d[] = "hello ";
	char s[] = "world!";
	char *dest;

	dest = ft_strjoin(d, s);
	printf("%s\n", dest);
	free(dest);
	return (0);
}*/
