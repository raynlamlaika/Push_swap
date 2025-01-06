/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlamlaik <rlamlaik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 08:13:24 by rlamlaik          #+#    #+#             */
/*   Updated: 2025/01/06 10:43:34 by rlamlaik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef PUSH_SWAP_H
#  define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>


typedef struct t_list
{
	int				index;
	int*			data;
	int				medi;
	struct t_list*	next;
}					l_list;

int		ft_atoi(const char *str);
int		is_valid(char *c);
void	ft_lstadd_back(l_list **lst, l_list *new);
char	**ft_split(char const *s, char c);
size_t	ft_strlen(const char *str);
l_list	*ft_lstnew(void *content);
int		ft_lstsize(l_list *lst);
int		swap_ab(l_list **stack_b, l_list **stack_a);
int		swap_a(l_list **stack_a);
int		swap_b(l_list **stack_b);
void	push_a(l_list **stack_a, l_list **stack_b);
l_list	*lst_second(l_list *lst);
int		rotate_a(l_list **stack_a);
int		rotate_b(l_list **stack_b);
int		rotate_ab(l_list **stack_a, l_list **stack_b);
int		reverse_rotate_a(l_list **stack_a);
l_list	*ft_lstlast(l_list *lst);
int		reverse_rotate_b(l_list **stack_b);
void	reverse_rotate_ab(l_list **stack_a, l_list **stack_b);
void	push_b(l_list **stack_b, l_list **stack_a);
void	spliting_input(int ac, char **av, l_list **linked);
int		check(l_list *linked);
void	switch_int(l_list **stack_a);
int		putstr(char *string);

void radix_sort(l_list **stack_a, l_list **stack_b);
// for the medium stacks (number of node)
void write_list(l_list *list);
void insertion_sort(l_list **stack_a, l_list **stack_b);
//for the eval
void apply_operation(const char *operation, l_list **stack_a, l_list **stack_b);
int *switch_to_array(l_list **stack_a, int size);



int sort_index(l_list *lst);
void	sort_big(l_list **stack_a, l_list **stack_b);
int mid(l_list **stack_b, int size);

#endif
