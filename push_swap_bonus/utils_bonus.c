/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlamlaik <rlamlaik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 21:02:06 by rlamlaik          #+#    #+#             */
/*   Updated: 2025/01/20 10:05:04 by rlamlaik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

static void	cheek(int rs, int i, const char *str, t_list *stck)
{
	long long	overflow;

	overflow = ((long long)((long)rs * 10) + (str[i] - '0'));
	if ((overflow > 2147483647) || (overflow < -2147483648))
	{
		write(1, "Error\n", 7);
		freed(stck);
		exit(EXIT_FAILURE);
	}
}

int	ft_atoi(const char *str, t_list *stck)
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
		cheek((rs * (long long)sing), i, str, stck);
		rs = rs * 10 + str[i] - '0';
		i++;
	}
	return ((int )rs * sing);
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
