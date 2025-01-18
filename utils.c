/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlamlaik <rlamlaik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 21:02:06 by rlamlaik          #+#    #+#             */
/*   Updated: 2025/01/18 17:31:44 by rlamlaik         ###   ########.fr       */
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

static void	cheek(int rs, int sing, int i, const char *str)
{
	long	overflow;

	overflow = ((long long)(rs * 10) + (str[i] - '0')) * (long long)sing;
	if ((overflow > 2147483647) || (overflow < -2147483648))
	{
		write(1, "Error\n", 7);
		exit(EXIT_FAILURE);
	}
}

int	ft_atoi(const char *str)
{
	int		i;
	int		sing;
	int		rs;

	i = 0;
	rs = 0;
	sing = 1;
	while (str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sing *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		cheek(rs, sing, i, str);
		rs = rs * 10 + str[i] - '0';
		i++;
	}
	return ((int )rs * sing);
}

int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	return (0);
}
