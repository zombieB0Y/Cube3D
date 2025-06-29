/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zoentifi <zoentifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 15:03:14 by zoentifi          #+#    #+#             */
/*   Updated: 2025/06/29 16:12:16 by zoentifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE_H
# define CUBE_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <string.h>
# include <math.h>
# include "libft/libft.h"
# include "mlx.h"

// Node to track allocated pointers
typedef struct t_GCNode
{
	void				*ptr;
	struct t_GCNode		*next;
}						t_GCNode;

typedef struct s_Cube
{
	t_GCNode			*g_head; // Head of the garbage collector linked list
}				t_Cube;


// our global cube instance
t_Cube  *cube(void);

// Memory management functions
void	gc_register(void *ptr);
void	*gc_malloc(size_t size);
void	gc_collect(void);

# endif