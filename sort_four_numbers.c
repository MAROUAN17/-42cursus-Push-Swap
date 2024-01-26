#include "header.h"

void    four_numbers_sort(l_linked **stack_a, l_linked **stack_b)
{
    l_linked *lowest_node = NULL;

    lowest_node = find_lowest(stack_a);
    while((*stack_a)->data != lowest_node->data)
        ra(stack_a);
    pb(stack_a, stack_b);
    three_numbers_sort(stack_a);
    pa(stack_a, stack_b);
}