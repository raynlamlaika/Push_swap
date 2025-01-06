/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linkedlist.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlamlaik <rlamlaik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 13:41:19 by rlamlaik          #+#    #+#             */
/*   Updated: 2025/01/06 16:17:13 by rlamlaik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_lstsize(l_list *lst)
{
	int	i;

	i = 0;
	if (!lst)
		return (0);
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

l_list	*lst_second(l_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next->next)
		lst = lst->next;
	return (lst);
}

l_list	*ft_lstlast(l_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

int	max_node_positon(l_list *stack)
{
	l_list	*tmp;
	l_list	*max;

	tmp = stack;
	max = tmp;
	while (tmp)
	{
		if (*tmp->data > *max->data)
			max = tmp;
		tmp = tmp->next;
	}
	return (max->position_in_stack);
}
