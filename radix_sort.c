/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlamlaik <rlamlaik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 10:12:03 by rlamlaik          #+#    #+#             */
/*   Updated: 2024/12/31 22:04:24 by rlamlaik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

// swap the pointers
void    swap(int *take_a, int *take_b)
{
	int tmp;
	
	tmp = *take_a;
	*take_a = *take_b;
	*take_b = tmp;
}
// Helper function to find the pivot index for Quick Sort
int pivot(int *array, int start, int end)
{
    int i = start - 1;
    int pivot = array[end];
    
    for (int j = start; j <= end - 1; j++) {
        if (array[j] < pivot) {
            i++;
            swap(&array[i], &array[j]);
        }
    }
    swap(&array[i + 1], &array[end]);
    return i + 1; // Return pivot index
}

//implemmentation of quicksort 
void quick_sort(int *array, int start, int end)
{
	int pivot_o;

	if (start >= end)
		return ;
	pivot_o = pivot(array, start, end);
	quick_sort(array, start, pivot_o - 1);
	quick_sort(array, pivot_o + 1, end);
}
// switch the linked list to in array to make it easier to sort 
int *switch_to_array(l_list **stack_a, int size)
{
	int *array;
	int i;

	i =  0;
	array = malloc(sizeof(int) * size);
	while (*stack_a || i < size)
	{
		array[i] = *(*stack_a)->data;
		*stack_a = (*stack_a)->next;
		i++;
	}
	return (array);
}

//the immplemmentation od radix the implemmentaion of quicksort and swit to array is in helper functions
void 



int main()
{
    int array[] = {29, 10, 14, 37, 13};
    int size = sizeof(array) / sizeof(array[0]);

    quick_sort(array, 0, size - 1);

    // Output the sorted array
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    return 0;
}
