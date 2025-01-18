/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlamlaik <rlamlaik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 08:13:29 by rlamlaik          #+#    #+#             */
/*   Updated: 2025/01/18 13:07:37 by rlamlaik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	clean_2(char **ptr)
{
	int	i;

	i = 0;
	if (!ptr)
		return ;
	while (ptr[i])
	{
		free(ptr[i]);
		ptr[i] = NULL;
		i++;
	}
	free(ptr);
	ptr = NULL;
}

void	freed(t_list *lst)
{
	t_list	*tmp;

	if (!lst)
		return ;
	while (lst)
	{
		tmp = lst->next;
		free(lst->data);
		free(lst);
		lst = tmp;
	}
}

int	sort_check(t_list **stack_a)
{
	t_list	*tmp;

	tmp = *stack_a;
	while (tmp->next)
	{
		if (*tmp->data > *tmp->next->data)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

void	sort(int size, t_list *stack_a, t_list *stack_b)
{
	if (size == 2)
		swap_a(&stack_a);
	else if (size == 3)
		sort_three(&stack_a);
	else if (size > 2 && size <= 10)
		sort_small_stack(&stack_a, &stack_b);
	else
		sort_big(&stack_a, &stack_b);
	freed(stack_a);
	freed(stack_b);
}
void write_list(t_list *list)
{
	int  i;
	i = 0;
	while(list)
	{
		printf("-->%d",*list->data);
		i++;
		list=list->next;
	}
	printf("\n");
}

int	main(int ac, char **av)
{
	t_list	*stack_a;
	t_list	*stack_b;
	char	*error;
	int		o;
	int		size;

	error = "Error\n";
	stack_a = NULL;
	stack_b = NULL;
	spliting_input(ac, av, &stack_a);
	if (ft_lstsize(stack_a) != (ac - 1))
		return (freed(stack_a), (write(1, error, 7)), 0);
	o = check(stack_a);
	if (o == 2)
		return (freed(stack_a), write(1, "Erorr\n", 7), 0);
	switch_int(&stack_a);
	o = check_double(&stack_a);
	if (o == 0)
		return ((write(1, error, 7)), 0);
	o = sort_check(&stack_a);
	if (o == 0)
		return (freed(stack_a), 0);
	sort_index(stack_a);
	size = ft_lstsize(stack_a);
	sort(size, stack_a, stack_b);
}

// #include "push_swap.h"
// void apply_operation(const char *operation,
// l_list **stack_a, l_list **stack_b) 
// {
// 	if (strcmp(operation, "pa") == 0)
// 		push_a(stack_a, stack_b);
// 	else if (strcmp(operation, "pb") == 0)
// 		push_b(stack_b, stack_a);
// 	else if (strcmp(operation, "sa") == 0)
// 		swap_a(stack_a);
// 	else if (strcmp(operation, "sb") == 0)
// 		swap_b(stack_b);
// 	else if (strcmp(operation, "ss") == 0)
// 		swap_ab(stack_a, stack_b);
// 	else if (strcmp(operation, "ra") == 0)
// 		rotate_a(stack_a);
// 	else if (strcmp(operation, "rb") == 0)
// 		rotate_b(stack_b);
// 	else if (strcmp(operation, "rr") == 0)
// 		rotate_ab(stack_a, stack_b);
// 	else if (strcmp(operation, "rra") == 0)
// 		reverse_rotate_a(stack_a);
// 	else if (strcmp(operation, "rrb") == 0)
// 		reverse_rotate_b(stack_b);
// 	else if (strcmp(operation, "rrr") == 0)
// 		reverse_rotate_ab(stack_a, stack_b);
// 	else 
// 		printf("Invalid operation: %s\n", operation);
// }