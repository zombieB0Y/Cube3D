/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zoentifi <zoentifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 16:04:27 by zoentifi          #+#    #+#             */
/*   Updated: 2025/06/29 16:12:44 by zoentifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	gc_register(void *ptr)
{
	t_GCNode	*node;

	if (!ptr)
		return ;
	node = malloc(sizeof(t_GCNode));
	if (!node)
		return ;
	node->ptr = ptr;
	node->next = cube()->g_head;
	cube()->g_head = node;
}

void	*gc_malloc(size_t size)
{
	void	*ptr;

	ptr = malloc((size_t)size);
	if (!ptr)
		return (NULL);
	gc_register(ptr);
	return (ptr);
}

void	gc_collect(void)
{
	t_GCNode	*current;
	t_GCNode	*next;

	current = cube()->g_head;
	while (current)
	{
		next = current->next;
		free(current->ptr);
		free(current);
		current = next;
	}
	cube()->g_head = NULL;
}