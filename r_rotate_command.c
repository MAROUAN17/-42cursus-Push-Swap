#include "header.h"

void    rra(l_linked **stack_a)
{
    l_linked    *last_node = NULL;
    l_linked    *before_last = NULL;
    
    last_node = *stack_a;
    while(last_node->next)
    {
        before_last = last_node;
        last_node = last_node->next;
    }
    before_last->next = NULL;
    (*stack_a)->previous = last_node;
    last_node->next = *stack_a;
    last_node->previous = NULL;
    *stack_a = last_node;
    // increase_index(stack_a);
    // (*stack_a)->index = 0;
    write(1, "rra\n", 4);
}

void    rrb(l_linked **stack_b)
{
    l_linked *last_node = NULL;
    l_linked *before_last = NULL;
    
    last_node = *stack_b;
    while(last_node->next)
    {
        before_last = last_node;
        last_node = last_node->next;
    }
    before_last->next = NULL;
    (*stack_b)->previous = last_node;
    last_node->next = *stack_b;
    last_node->previous = NULL;
    *stack_b = last_node;
    // increase_index(stack_b);
    // (*stack_b)->index = 0;
    write(1, "rrb\n", 4);
}

void rrr(l_linked **stack_a, l_linked **stack_b)
{
    l_linked    *last_node_a = NULL;
    l_linked    *last_node_b = NULL;
    l_linked    *before_last_a = NULL;
    l_linked    *before_last_b = NULL;
    
    last_node_a = *stack_a;
    while(last_node_a->next)
    {
        before_last_a = last_node_a;
        last_node_a = last_node_a->next;
    }
    before_last_a->next = NULL;
    (*stack_a)->previous = last_node_a;
    last_node_a->next = *stack_a;
    last_node_a->previous = NULL;
    *stack_a = last_node_a;
    // increase_index(stack_a);
    // (*stack_a)->index = 0;
    /*----------rotate rrb------------*/
    last_node_b = *stack_b;
    while(last_node_b->next)
    {
        before_last_b = last_node_b;
        last_node_b = last_node_b->next;
    }
    before_last_b->next = NULL;
    (*stack_b)->previous = last_node_b;
    last_node_b->next = *stack_b;
    last_node_b->previous = NULL;
    *stack_b = last_node_b;
    // increase_index(stack_b);
    // (*stack_b)->index = 0;
    write(1, "rrr\n", 4);
}
