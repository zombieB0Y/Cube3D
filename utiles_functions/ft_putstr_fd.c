/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zoentifi <zoentifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 23:03:53 by zoentifi          #+#    #+#             */
/*   Updated: 2025/07/17 17:21:27 by zoentifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

void	ft_putstr_fd(char *s, int fd)
{
	if (!s || fd < 0)
		return ;
	else
	{
		while (*s)
		{
			if (write(fd, s, 1) < 0)
			{
				ft_putstr_fd("Error writing\n", 2);
				return ;
			}
			s++;
		}
	}
}
