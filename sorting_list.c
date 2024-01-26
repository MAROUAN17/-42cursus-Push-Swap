#include "header.h"

void   bring_to_top_a(l_linked **stack_a, l_linked *cheapest_node, int reverse)
{
    if(reverse == 0)
    {
        while((*stack_a)->index != cheapest_node->index)
            ra(stack_a);
    }
    else if(reverse == 1)
    {
        while ((*stack_a)->index != cheapest_node->index)
            rra(stack_a);
    }
}

void    bring_to_top_b(l_linked **stack_b, l_linked *to_find_b, int reverse)
{
    if(reverse == 0)
    {
        while((*stack_b)->index != to_find_b->index)
            rb(stack_b);
    }
    
    else if(reverse == 1)
    {
        while ((*stack_b)->index != to_find_b->index)
            rrb(stack_b);
    }
}

void    index_stack(l_linked **stack)
{
    int         lowest;
    l_linked    *first_node = NULL;
    l_linked    *browse_node = NULL;
    l_linked    *current = NULL;

    lowest = 0;
    first_node = (*stack);
    while(first_node)
    {
        lowest = 0;
        current = first_node;
        browse_node = *stack;
        while(browse_node)
        {
            if(current->data > browse_node->data)
                lowest++;
            browse_node = browse_node->next;
        }
        current->index = lowest;
        first_node = first_node->next;
    }
}

void    sort(l_linked **stack_a, l_linked **stack_b)
{
    int         count;

    index_stack(stack_a);
    count = count_stack(stack_a);
    if(count == 2)    
        two_numbers_sort(stack_a);
    else if(count == 3)   
        three_numbers_sort(stack_a);
    else if(count == 4)   
        four_numbers_sort(stack_a, stack_b);
    else if(count == 5)    
        five_numbers_sort(stack_a, stack_b);
    else   
        rest_of_numbers_sort(stack_a, stack_b);
}
