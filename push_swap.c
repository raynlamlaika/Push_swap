/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlamlaik <rlamlaik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 08:13:29 by rlamlaik          #+#    #+#             */
/*   Updated: 2024/12/28 16:17:49 by rlamlaik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
//parccing the input (node by node)
void spliting_input(int ac, char **av, l_list **linked)
{
	int i;
	int j;
	char **gone;
	int l;
	l_list *lst;

	i = 1;
	while (ac > i && ac > 2)
	{
		gone = ft_split(av[i++], ' ');
		l = 0;
		while (gone[l])
		{
			lst = ft_lstnew(gone[l++]);
			if (!lst)
			{
				j = 0;
				while (gone[j])
					free(gone[j++]);
				free(gone);
				return ;
			}
			ft_lstadd_back(linked, lst);
		}
	}
}

//Parccing: check for not digit argemment
int	check(l_list *linked)
{
	l_list *tmp;

	tmp = linked;
	while(tmp)
	{
		if (!is_valid((char *)tmp->data))
			return (0);
		tmp = tmp->next;
	}
	return 1;
}

// switch char to integer to preparing to check for doubles
void	switch_int(l_list **stack_a)
{
	int i;
	l_list *curr;

	curr = *stack_a;
	while (curr)
	{	
		i = ft_atoi((char *)curr->data);
		free(curr->data);
		curr->data = malloc(sizeof(int));
		if (!(curr->data))
		{	
			printf("eeeee");
			return ;
		}
		*(int *)(curr->data) = i;
    	curr = curr->next;
	}

}

//check nodes if this in doubles deffenoition in nodes
int check_double(l_list **stack_a )
{
	return 0;
}


void write_list(l_list *list)
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


int main(int ac, char** av)
{
	l_list	*stack_a= NULL;
	l_list	*stack_b = NULL;
	char	*error;
	int		o;
	int		size;
    char operation[10];

	error = "Error\n";
	spliting_input(ac, av, &stack_a);
	o = check(stack_a); //check for list size (lst > 3 || 2)
	if (o == 0)
		return ((write(1,error,7)), 0);
	switch_int(&stack_a);
	l_list *xx = stack_a;

	//size to implemment the algo depand of the size 
	write_list(stack_a);

	size = ft_lstsize(xx);
	l_list *fr = find_min(xx);
	int i = nbt_rotations_needed(xx, fr);
	printf("the number of the rotate operaitions needed: |%d| to make the min node(%d)\n", i, *fr->data);
	rotate_to_top(&stack_a, i);
	write_list(stack_a);

	//for SIZE 3-5: in hardcode can solve it "to be more oprimazed"
	if (size <= 5)
		return (write(1, "hard code\n", 11));

	//for SIZE 6-100
	if (size >=6 && size <= 100)
		return (write(1, "need in algo\n", 11));

	//for SIZE 100- ++ in big stack
	if (size > 100)
		return (write(1, "need in algo\n", 11));

	//write_list(stack_a);
}





//play with the operations

// int main(int ac, char** av)
// {
// 	l_list	*stack_a= NULL;
// 	l_list	*stack_b = NULL;
// 	char	*error;
// 	int		o;
//     char operation[10];

// 	error = "Error\n";
// 	spliting_input(ac, av, &stack_a);
// 	o = check(stack_a); //check for list size (lst > 3 || 2)
// 	if (o == 0)
// 		return ((write(1,error,7)), 0);
// 	switch_int(&stack_a);
// 	printf("Enter operations (e.g., pa, pb, sa, ...), one per line:\n");
//     while (scanf("%s", operation) != EOF) 
// 	{
//         apply_operation(operation, &stack_a, &stack_b);
//         printf("Stack A: ");
//         write_list(stack_a);
//         printf("Stack B: ");
//         write_list(stack_b);
//     }

// }






