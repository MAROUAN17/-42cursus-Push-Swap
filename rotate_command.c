#include "header.h"

void    ra(l_linked **stack_a)
{
    l_linked    *last_node = NULL;
    l_linked    *first_node = NULL;

    first_node = *stack_a;
    last_node = *stack_a;
    while(last_node->next)
        last_node = last_node->next;
    *stack_a = (*stack_a)->next;
    last_node->next = first_node;
    first_node->previous = last_node;
    first_node->next = NULL;
    (*stack_a)->previous = NULL;
    // decrease_index(stack_a);
    // last_node->next->index = last_node->index + 1;
    write(1, "ra\n", 3);
}

void    rb(l_linked **stack_b)
{
    l_linked    *last_node = NULL;
    l_linked    *first_node = NULL;

    first_node = *stack_b;
    last_node = *stack_b;
    while(last_node->next)
        last_node = last_node->next;
    *stack_b = (*stack_b)->next;
    last_node->next = first_node;
    first_node->previous = last_node;
    first_node->next = NULL;
    (*stack_b)->previous = NULL;
    // decrease_index(stack_b);
    // last_node->next->index = last_node->index + 1;
    write(1, "rb\n", 3);
}

void rr(l_linked **stack_a, l_linked **stack_b)
{
    l_linked    *last_node_a = NULL;
    l_linked    *first_node_a = NULL;
    l_linked    *last_node_b = NULL;
    l_linked    *first_node_b = NULL;

    first_node_a = *stack_a;
    last_node_a = *stack_a;
    while(last_node_a->next)
        last_node_a = last_node_a->next;
    *stack_a = (*stack_a)->next;
    last_node_a->next = first_node_a;
    first_node_a->previous = last_node_a;
    first_node_a->next = NULL;
    (*stack_a)->previous = NULL;
    // decrease_index(stack_a);
    // last_node_a->next->index = last_node_a->index + 1;
    /*-------------rb------------------*/
    first_node_b = *stack_b;
    last_node_b = *stack_b;
    while(last_node_b->next)
        last_node_b = last_node_b->next;
    *stack_b = (*stack_b)->next;
    last_node_b->next = first_node_b;
    first_node_b->previous = last_node_b;
    first_node_b->next = NULL;
    (*stack_b)->previous = NULL;
    // decrease_index(stack_b);
    // last_node_b->next->index = last_node_b->index + 1;
    write(1, "rr\n", 3);
}
