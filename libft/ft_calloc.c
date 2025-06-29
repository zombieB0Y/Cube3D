/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zoentifi <zoentifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 19:16:55 by zoentifi          #+#    #+#             */
/*   Updated: 2025/06/29 15:56:49 by zoentifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*arr;
	size_t	res;

	if (count != 0 && (__SIZE_MAX__ / count) < size)
		return (NULL);
	res = count * size;
	arr = malloc(res);
	if (!arr)
		return (NULL);
	ft_memset(arr, 0, res);
	return (arr);
}
