/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putstr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlamlaik <rlamlaik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 09:09:38 by rlamlaik          #+#    #+#             */
/*   Updated: 2025/01/07 15:44:18 by rlamlaik         ###   ########.fr       */
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
