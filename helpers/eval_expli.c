#include "push_swap.h"

void apply_operation(const char *operation, l_list **stack_a, l_list **stack_b) 
{
	if (strcmp(operation, "pa") == 0)
		push_a(stack_a, stack_b);
	else if (strcmp(operation, "pb") == 0)
		push_b(stack_b, stack_a);
	else if (strcmp(operation, "sa") == 0)
		swap_a(stack_a);
	else if (strcmp(operation, "sb") == 0)
		swap_b(stack_b);
	else if (strcmp(operation, "ss") == 0)
		swap_ab(stack_a, stack_b);
	else if (strcmp(operation, "ra") == 0)
		rotate_a(stack_a);
	else if (strcmp(operation, "rb") == 0)
		rotate_b(stack_b);
	else if (strcmp(operation, "rr") == 0)
		rotate_ab(stack_a, stack_b);
	else if (strcmp(operation, "rra") == 0)
		reverse_rotate_a(stack_a);
	else if (strcmp(operation, "rrb") == 0)
		reverse_rotate_b(stack_b);
	else if (strcmp(operation, "rrr") == 0)
		reverse_rotate_ab(stack_a, stack_b);
	else 
		printf("Invalid operation: %s\n", operation);
	
}

