#include "push_swap.h"

int main(int ac, char** av)
{
	t_list	*stack_a= NULL;
	t_list	*stack_b = NULL;
	char	*error;
	int		o;
    char operation[10];

	error = "Error\n";
	spliting_input(ac, av, &stack_a);
	o = check(stack_a); //check for list size (lst > 3 || 2)
	if (o == 0)
		return ((write(1,error,7)), 0);
	switch_int(&stack_a);
	printf("Enter operations (e.g., pa, pb, sa, ...), one per line:\n");
    while (scanf("%s", operation) != EOF) 
	{
        apply_operation(operation, &stack_a, &stack_b);
        printf("Stack A: ");
        write_list(stack_a);
        printf("Stack B: ");
        write_list(stack_b);
    }
}
