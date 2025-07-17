/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_line.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zoentifi <zoentifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 14:27:37 by zoentifi          #+#    #+#             */
/*   Updated: 2025/07/17 14:11:07 by zoentifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_LINE_H
# define GET_LINE_H

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include "../cube.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

typedef struct s_buff
{
	char	*buffer;
	int		buffer_index;
	int		bytes_read;
}			t_buff;

char		*get_next_line(int fd);
char		*ft_strjoin(char *s1, char *s2);
int			init_buffer(t_buff *buff);
char		*read_from_buffer(t_buff *buff, char *line);
void		*ft_memcpy(void *dst, const void *src, size_t n);

#endif
