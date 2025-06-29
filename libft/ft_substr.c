/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zoentifi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 03:28:39 by zoentifi          #+#    #+#             */
/*   Updated: 2024/11/04 03:29:02 by zoentifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*arr;
	unsigned int	i;

	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	if (len > ft_strlen(s) - start)
		len = (ft_strlen(s) - start);
	i = 0;
	arr = (char *)malloc(sizeof(char) * (len + 1));
	if (!arr)
		return (NULL);
	if (len)
	{
		while (s[start] && len)
		{
			arr[i++] = s[start++];
			len--;
		}
	}
	arr[i] = '\0';
	return (arr);
}

/*int	main(void)
{
	char	*dest;
	char	src[] = "hello world!";

	dest = ft_substr(src, 6, 6);
	if (!dest)
	{
		printf("NULL\n");
		return (0);
	}
	printf("%s\n", dest);
	free(dest);
	return (0);
}*/