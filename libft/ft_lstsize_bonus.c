/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zoentifi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 00:04:50 by zoentifi          #+#    #+#             */
/*   Updated: 2024/11/06 00:04:55 by zoentifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	count;

	count = 0;
	while (lst)
	{
		lst = lst->next;
		count++;
	}
	return (count);
}

// int main()
// {
//     t_list  *node1;
//     t_list  *node2;
//     t_list  *node3;

//     node1 = ft_lstnew("zo");
//     node2 = ft_lstnew("uba");
//     node3 = ft_lstnew("ir");
//     ft_lstadd_front(&node3, node2);
//     ft_lstadd_front(&node2, node1);
//     t_list  *head = node1;
//     // while (node1)
//     // {
//     //     printf("%s",node1->content);
//     //     node1 = node1->next;
//     // }
//     int i = ft_lstsize(head);
//     printf("%d\n", i);
//     t_list  *tmp;

//     while (head)
//     {
//         tmp = head->next;
//         free(head);
//         head = tmp;
//     }

// }