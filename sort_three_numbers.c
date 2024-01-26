#include "header.h"

void    three_numbers_sort(l_linked **stack_a)
{
    if((*stack_a)->data > (*stack_a)->next->data && (*stack_a)->next->data < (*stack_a)->next->next->data && (*stack_a)->data < (*stack_a)->next->next->data)
            sa(stack_a);
    else if((*stack_a)->data > (*stack_a)->next->data && (*stack_a)->next->data > (*stack_a)->next->next->data)
    {    
        sa(stack_a);
        rra(stack_a);
    }
    else if((*stack_a)->data > (*stack_a)->next->data && (*stack_a)->next->data < (*stack_a)->next->next->data && (*stack_a)->data > (*stack_a)->next->next->data)
        ra(&(*stack_a));
    else if((*stack_a)->data < (*stack_a)->next->data && (*stack_a)->next->data > (*stack_a)->next->next->data && (*stack_a)->data < (*stack_a)->next->next->data)
    {
        sa(stack_a);
        ra(stack_a);
    }
    else if((*stack_a)->data < (*stack_a)->next->data && (*stack_a)->next->data > (*stack_a)->next->next->data && (*stack_a)->data > (*stack_a)->next->next->data)
        rra(stack_a);
}
