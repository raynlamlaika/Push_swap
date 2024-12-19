/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlamlaik <rlamlaik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 08:13:24 by rlamlaik          #+#    #+#             */
/*   Updated: 2024/12/19 04:51:40 by rlamlaik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef PUSH_SWAP_H
#  define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <libc.h>

typedef struct t_list
{
	int*			data;
	struct t_list*	next;
}					l_list;

int		ft_atoi(const char *str);
int		is_valid(int c);
void	ft_lstadd_back(l_list **lst, l_list *new);
char	**ft_split(char const *s, char c);


#endif