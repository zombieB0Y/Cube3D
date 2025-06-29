/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zoentifi <zoentifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 17:58:33 by zoentifi          #+#    #+#             */
/*   Updated: 2025/06/29 17:58:54 by zoentifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

void *ft_realloc(void *ptr, size_t old_size, size_t new_size)
{
    void *new_ptr;
    
    if (!ptr)
        return gc_malloc(new_size);
    if (new_size == 0) {
        free(ptr);
        return NULL;
    }
    new_ptr = gc_malloc(new_size);
    if (!new_ptr)
        return NULL;
    size_t copy_size = old_size < new_size ? old_size : new_size;
    new_ptr = ft_memcpy(new_ptr, ptr, copy_size);
    return new_ptr;
}