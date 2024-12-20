/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlamlaik <rlamlaik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 08:13:29 by rlamlaik          #+#    #+#             */
/*   Updated: 2024/12/20 22:05:01 by rlamlaik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int check(l_list *linked)
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

int main(int ac, char** av)
{
	l_list *linked= NULL;
	char	*error;

	error = "Error\n";
	spliting_input(ac, av, &linked);
	int o = check(linked); //check for list size (lst > 3 || 2)
	if (o == 0)
		return((write(1,error,7)),0);
	l_list *current = linked;

	while(current)
	{
		printf("this is are the input splitiong |%s|\n",(char *)current->data);
		current = current->next;
	}
}

// sa (swap a): swap the first tow elemment in Stack_a.
// sb (swap b): swap the first tow elemment in Stack_b
//ss : sa and sb at the same time
//pa (push a): Take the first element at the top of b and put it at the top of a.
//pb (push b): Take the first element at the top of a and put it at the top of b.
//ra (rotate a): Shift up all elements of stack a by 1.
//rb (rotate b): Shift up all elements of stack b by 1.
//rr : ra and rb at the same time.
//rra (reverse rotate a): Shift down all elements of stack a by 1
//rrb (reverse rotate b): Shift down all elements of stack b by 1.
//rrr : rra and rrb at the same time.


// SORTING ALGOOOOO
// int main(int ac, char **av)
// {
// 	char	**arguments;
// 	char	*error;
// 	l_list	*the_list;
// 	l_list	*linkedlist;

// 	error = "Error\n";
// //Parssing
// 	int i = 1 ;
// 	int j = 0 ;
// 	int integer;
// 	char **fuck;
// 	if (ac >= 1)
// 	{
// 		if (ac == 2)
// 		{
// 			fuck = ft_split(av[1], ' ');
// 			if (!fuck)
// 				return(0);
// 			while (fuck[j] && !fuck[j])
// 				if (is_valid(fuck[j]))
// 				{
// 					integer = ft_atoi(fuck[j++]);
// 					printf("this is the int we pass :%d\n",integer);
// 				}
// 				else
// 					return (0);
// 		}
// 		while (av[i] )
// 			if (is_valid(av[i]))
// 			{
// 				integer  = ft_atoi(av[i++]);
// 				printf("this is the int we pass :%d\n",integer);
// 			}
// 			else
// 				return (0);
// 	}
// }
   // arguments = ft_split(av[1], ' ');
	// int i = 0;
	// while (*arguments)
	// 	printf("%s",arguments[i++]);

    // if (!arguments)
    //     return (write(1, error, 7), 0);
	// if(!(check_args(ac, arguments)))
// check for valid argemment passed
	//	return (write(1, error, 7), 0);
//	write(1, "passe the checking successefully\n" ,34);
// switch and appand the stack from av to stack
//	write(1,"now letss pass to the liked list\n",34);
	// int *i;
	// i = creating_list(ac, arguments, linkedlist);
	//sort_args();
	//sorting the stack a and b right here