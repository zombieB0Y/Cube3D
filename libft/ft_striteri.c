/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zoentifi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 17:58:15 by zoentifi          #+#    #+#             */
/*   Updated: 2024/11/02 17:59:07 by zoentifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	size_t	i;

	i = 0;
	if (!s || !f)
		return ;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}

/*void	ft_tolower(unsigned int a, char *b)
{
	if (a)
		if (*b >= 'A' && *b <= 'Z')
			*b += 32;
}

int	main(void)
{
	char	arr[] = "HEllo WolRd!";

	ft_striteri(arr, ft_tolower);
	printf("%s\n", arr);
	//free(arr);
	return (0);
}*/
