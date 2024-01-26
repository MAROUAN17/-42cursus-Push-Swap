#include "checker_bonus.h"

void pa(l_linked **stack_a, l_linked **stack_b)
{
    l_linked *first_node = NULL;

    first_node = *stack_b;
    if((*stack_b)->next)    
    {    
        *stack_b = (*stack_b)->next;
        (*stack_b)->previous = NULL;
    }
    else
        (*stack_b) = NULL;
    first_node->next = *stack_a;
    first_node->previous = NULL;
    if(*stack_a)
        (*stack_a)->previous = first_node;
    *stack_a = first_node;
}

void pb(l_linked **stack_a, l_linked **stack_b)
{
    l_linked *first_node = NULL;

    first_node = *stack_a;
    if((*stack_a)->next)
    {    
        *stack_a = (*stack_a)->next;
        (*stack_a)->previous = NULL;
    }
    else
        *stack_a = NULL;
    first_node->next = *stack_b;
    first_node->previous = NULL;
    if(*stack_b)
        (*stack_b)->previous = first_node;
    *stack_b = first_node;
}
