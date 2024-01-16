#include "header.h"

void    sa(l_linked **stack_a)
{
    int         tmp;
    l_linked    *current = NULL;

    tmp = 0;
    current = *stack_a;
    if (current && current->next)
    {
        tmp = current->data;
        current->data = current->next->data;
        current->next->data = tmp;
    }
    write(1, "sa\n", 3);
}

void    sb(l_linked **stack_b)
{
    int         tmp;
    l_linked    *current = NULL;

    tmp = 0;
    current = *stack_b;
    if (current && current->next)
    {
        tmp = current->data;
        current->data = current->next->data;
        current->next->data = tmp;
    }
    write(1, "sb\n", 3);
}

void    ss(l_linked **stack_a, l_linked **stack_b)
{
    int         tmp;
    l_linked    *current_a = NULL;
    l_linked    *current_b = NULL;

    tmp = 0;
    current_a = *stack_a;
    if (current_a && current_a->next)
    {
        tmp = current_a->data;
        current_a->data = current_a->next->data;
        current_a->next->data = tmp;
    }
    /*----------------sb---------------*/
    tmp = 0;
    current_b = *stack_b;
    if (current_b && current_b->next)
    {
        tmp = current_b->data;
        current_b->data = current_b->next->data;
        current_b->next->data = tmp;
    }
    write(1, "ss\n", 3);
}
