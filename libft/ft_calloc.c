/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zoentifi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 19:16:55 by zoentifi          #+#    #+#             */
/*   Updated: 2024/10/28 19:57:31 by zoentifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*arr;
	size_t	res;

	if (count != 0 && (SIZE_MAX / count) < size)
		return (NULL);
	res = count * size;
	arr = malloc(res);
	if (!arr)
		return (NULL);
	ft_memset(arr, 0, res);
	return (arr);
}

// int main()
// {
// 	char *arr;

// 	arr = ft_calloc(SIZE_MAX, SIZE_MAX);
// 	printf("%s\n", arr);
// 	if (arr)
// 		free(arr);
// }