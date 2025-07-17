/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_line.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zoentifi <zoentifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 15:48:28 by zoentifi          #+#    #+#             */
/*   Updated: 2025/07/17 14:10:50 by zoentifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_line.h"

char	*fill_line(t_buff *buff, char *line, int fd)
{
	while (1)
	{
		if (buff->buffer_index >= buff->bytes_read)
		{
			buff->bytes_read = read(fd, buff->buffer, BUFFER_SIZE);
			buff->buffer_index = 0;
			if (buff->bytes_read <= 0)
			{
				if (buff->bytes_read == 0)
				{
					buff->buffer = NULL;
					return (line);
				}
				return (NULL);
			}
		}
		line = read_from_buffer(buff, line);
		if (!line || (line[ft_strlen(line) - 1] == '\n'))
			return (line);
	}
}

char	*get_next_line(int fd)
{
	static t_buff	buff;
	char			*line;

	line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0 || !init_buffer(&buff))
		return (NULL);
	line = fill_line(&buff, line, fd);
	if (!line)
    	return (NULL);
	return (line);
}
