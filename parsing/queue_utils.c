/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zm <zm@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 00:00:00 by zm                #+#    #+#             */
/*   Updated: 2025/09/20 05:25:50 by zm               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

int init_queue(t_queue *q, int capacity)
{
	q->data = gc_malloc(capacity * sizeof(t_point));
	if (!q->data)
		return (0);
	q->front = 0;
	q->back = -1;
	q->capacity = capacity;
	return (1);
}

void add_in_queue(t_queue *q, t_point point)
{
	if (q->back == q->capacity - 1)
		return ;
	q->data[++q->back] = point;
}

t_point out_of_queue(t_queue *q)
{
	return (q->data[q->front++]);
}

int is_empty(t_queue *q)
{
	return (q->front > q->back);
}
