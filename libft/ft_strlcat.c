/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zoentifi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 16:20:31 by zoentifi          #+#    #+#             */
/*   Updated: 2024/10/31 19:48:30 by zoentifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dst_length;
	size_t	src_length;

	if (dstsize == 0)
		return (ft_strlen(src));
	dst_length = ft_strlen(dst);
	src_length = ft_strlen(src);
	if (dst_length >= dstsize)
		return (src_length + dstsize);
	dst += dst_length;
	while (*src && (dstsize - dst_length - 1) > 0)
	{
		*dst = *src;
		dst++;
		src++;
		dstsize--;
	}
	*dst = '\0';
	return (dst_length + src_length);
}
