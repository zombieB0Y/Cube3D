/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zoentifi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 18:02:06 by zoentifi          #+#    #+#             */
/*   Updated: 2024/11/02 18:06:11 by zoentifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*arr;
	int		i;

	i = 0;
	if (!s || !f)
		return (NULL);
	arr = (char *)malloc(sizeof(char) * ft_strlen(s) + 1);
	if (!arr)
		return (NULL);
	while (s[i])
	{
		arr[i] = f(i, s[i]);
		i++;
	}
	arr[i] = '\0';
	return (arr);
}

/*tets
char	ft_tolower(unsigned int a, char b)
{
	if (a)
		if (b >= 'A' && b <= 'Z')
			return (b + 32);
	return (b);
}

int	main(void)
{
	char	*arr;

	arr = ft_strmapi("HEllo WolRd!", ft_tolower);
	printf("%s\n", arr);
	free(arr);
	return (0);
}*/
