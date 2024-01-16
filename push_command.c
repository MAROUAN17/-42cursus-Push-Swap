#include "header.h"

void pa(l_linked **stack_a, l_linked **stack_b)
{
    l_linked *newNode = NULL;

    if(stack_b)
    {
        newNode = malloc(sizeof(l_linked));
        newNode->data = (*stack_b)->data;
        newNode->next = *stack_a;
        newNode->previous = NULL;
        *stack_b = (*stack_b)->next;
        if((*stack_b))
            (*stack_b)->previous = NULL;
        *stack_a = newNode;
    }
    write(1, "pa\n", 3);
}

void pb(l_linked **stack_a, l_linked **stack_b)
{
    l_linked *newNode = NULL;

    if(stack_a)
    {
        newNode = malloc(sizeof(l_linked));
        newNode->data = (*stack_a)->data;
        newNode->next = *stack_b;
        newNode->previous = NULL;
        *stack_a = (*stack_a)->next;
        if((*stack_a))
            (*stack_a)->previous = NULL;
        *stack_b = newNode;
    }
    write(1, "pb\n", 3);
}
