/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zoentifi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 23:03:53 by zoentifi          #+#    #+#             */
/*   Updated: 2024/11/06 07:43:06 by zoentifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <fcntl.h>
#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	if (!s || fd < 0)
		return ;
	else
	{
		while (*s)
		{
			write(fd, s, 1);
			s++;
		}
	}
}
/*int main()
{
	int fd = open("putstr.txt", O_WRONLY | O_CREAT);
	ft_putstr_fd(NULL, fd);
	close(fd);
	return (0);
}*/
