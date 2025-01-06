/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlamlaik <rlamlaik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 08:13:29 by rlamlaik          #+#    #+#             */
/*   Updated: 2025/01/06 13:55:10 by rlamlaik         ###   ########.fr       */
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



void write_list(l_list *list)
{
	int  i;

	i = 0;
	while(list)
	{
		printf("-->%d",*list->data);
		printf("index :-->%d\n",list->index);
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

	error = "Error\n";
	spliting_input(ac, av, &stack_a);
	o = check(stack_a); //check for list size (lst > 3 || 2)
	if (o == 0)
		return ((write(1,error,7)), 0);
	switch_int(&stack_a);

	//size to implemment the algo depand of the size 
	sort_index(stack_a);

	sort_big(&stack_a, &stack_b);
	//printf("\n\n\n\this is the mid value : |%d|", mid(&ddd, size-1));
	//write_list(stack_a);

	

	
	// //for SIZE 3-5: in hardcode can solve it "to be more oprimazed"
	// if (size <= 4)
	// 	return (write(1, "hard code\n", 11));
	// //for SIZE 6-100
	// if (size >=5 && size <= 50)
	// 	return (write(1, "hard code\n", 11));//insertion_sort(&stack_a,&stack_b);
	// //for SIZE 100- ++ in big stack
	// if (size > 100)
	// 	return (write(1, "need in algo\n", 11));
}
