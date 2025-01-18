/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putstr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlamlaik <rlamlaik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 09:09:38 by rlamlaik          #+#    #+#             */
/*   Updated: 2025/01/18 20:15:35 by rlamlaik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	putchar(int c)
{
	write(1, &c, 1);
	return (1);
}

int	putstr(char *string)
{
	int	i;

	i = 0;
	if (!string)
		i += write(1, "(null)", 6);
	else
	{
		while (*string)
		{
			i += putchar(*string);
			string++;
		}
	}
	return (i);
}

int	is_valid(char *str)
{
	int	i;
	int	j;

	i = 0;
	if (!str || !str[i])
		return (0);
	while (str[i] == '-' || str[i] == '+')
		i++;
	j = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		j++;
		i++;
	}
	if (j < 1)
		return (0);
	return (1);
}
