#include "header.h"

void pa(l_linked **stack_a, l_linked **stack_b)
{
    l_linked *first_node = NULL;
    // l_linked *newNode = NULL;

    first_node = malloc(sizeof(l_linked));
    if(!first_node)
        return;
    *first_node = **stack_b;
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
    write(1, "pa\n", 3);
}

void pb(l_linked **stack_a, l_linked **stack_b)
{
    l_linked *first_node = NULL;

    first_node = malloc(sizeof(l_linked));
    if(!first_node)
        return;
    *first_node = **stack_a;
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
    write(1, "pb\n", 3);
}
