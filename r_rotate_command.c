#include "header.h"

void    rra(l_linked **stack_a)
{
    l_linked *last_node;
    l_linked *newNode;

    last_node = *stack_a;
    while(last_node->next)
        last_node = last_node->next;
    newNode = malloc(sizeof(l_linked));
    newNode->data = last_node->data;
    newNode->next = *stack_a;
    newNode->previous = NULL;
    last_node = last_node->previous;
    last_node->next = NULL;
    (*stack_a)->previous = newNode;
    *stack_a = newNode;
    write(1, "rra\n", 4);
}

void    rrb(l_linked **stack_b)
{
    l_linked *last_node;
    l_linked *newNode;

    last_node = *stack_b;
    while(last_node->next)
        last_node = last_node->next;
    newNode = malloc(sizeof(l_linked));
    newNode->data = last_node->data;
    newNode->next = *stack_b;
    newNode->previous = NULL;
    last_node = last_node->previous;
    last_node->next = NULL;
    (*stack_b)->previous = newNode;
    *stack_b = newNode;
    write(1, "rrb\n", 4);
}

void rrr(l_linked **stack_a, l_linked **stack_b)
{
    l_linked *current_a = NULL;
    l_linked *current_b = NULL;
    l_linked *newNode = NULL;

    current_a = *stack_a;
    while(current_a->next)
        current_a = current_a->next;
    newNode = malloc(sizeof(l_linked));
    newNode->data = current_a->data;
    newNode->next = *stack_a;
    newNode->previous = NULL;
    current_a->previous->next = NULL;
    (*stack_a)->previous = newNode;
    *stack_a = newNode;
    /*----------rotate rrb------------*/
    current_b = *stack_b;
    while(current_b->next)
        current_b = current_b->next;
    newNode = malloc(sizeof(l_linked));
    newNode->data = current_b->data;
    newNode->next = *stack_b;
    newNode->previous = NULL;
    current_b->previous->next = NULL;
    (*stack_b)->previous = newNode;
    *stack_b = newNode;
    write(1, "rrr\n", 4);
}
