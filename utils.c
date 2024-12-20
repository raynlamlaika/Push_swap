/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlamlaik <rlamlaik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 21:02:06 by rlamlaik          #+#    #+#             */
/*   Updated: 2024/12/20 16:56:23 by rlamlaik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

static int	ft_overflow(int sing)
{
	if (sing == 1)
		return (-1);
	return (0);
}

int	ft_atoi(const char *str)
{
	int		i;
	int		sing;
	long	rs;

	i = 0;
	rs = 0;
	sing = 1;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sing *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (rs > ((9223372036854775807 - str[i] - 48)) / 10)
			return (ft_overflow(sing));
		rs = rs * 10 + str[i] - '0';
		i++;
	}
	return ((int )rs * sing);
}
// need to check for the input 
int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	return (0);
}

int checkfordouble(l_list **linked)
{

	return 1;
}
int is_valid(char *str , t_list	**linked)
{
	if (!str || !*str)
		return 0;
	if (*str == '-' || *str == '+') 
		str++;
	while (*str) 
	{
		if (!ft_isdigit(*str) || checkfordouble(linked))
			return 0;
		str++;
	}
	return 1;
}

//for implimentation of the linked list

l_list	*ft_lstnew(void *content)
{
	l_list	*p;

	p = (l_list *)malloc(sizeof(l_list));
	if (!p)
		return (0);
	p->data = content;
	p->next = NULL;
	return (p);
}

void	ft_lstadd_back(l_list **lst, l_list *new)
{
	l_list	*p;

	if (!lst || !new)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	p = *lst;
	while (p->next)
		p = p->next;
	p->next = new;
}