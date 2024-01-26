#include "header.h"

l_linked *find_lowest(l_linked **stack)
{
    l_linked *current = NULL;
    l_linked *lowest = NULL;

    current = *stack;
    lowest = current;
    while(current)
    {
        if(current->data < lowest->data)
            lowest = current;
        current = current->next;
    }
    return (lowest);
}

l_linked *find_greatest(l_linked **stack)
{
    l_linked *current = NULL;
    l_linked *greatest = NULL;

    current = *stack;
    greatest = current;
    while(current)
    {
        if(current->data > greatest->data)
            greatest = current;
        current = current->next;
    }
    return (greatest);
}

int find_position(l_linked **stack, l_linked *to_find)
{
    l_linked *current = NULL;
    int position;

    current = *stack;
    position = 1;
    while(current->data != to_find->data)
    {
        position++;
        current = current->next;
    }
    return (position);
}

int count_stack(l_linked **stack)
{
    int         count;
    l_linked    *current = NULL;

    count = 0;
    current = *stack;
    while(current)
    {
        count++;
        current = current->next;
    }
    return (count);
}

int count_moves(l_linked **stack, l_linked *to_find, int reverse, int mid)
{
    l_linked *current = NULL;
    int count;

    count = 0;
    current = *stack;
    if(reverse == 0)
    {
        while(current->index != to_find->index && count <= mid)
        {
            count++;
            current = current->next;
        }
    }
    else
    {
        while(current && current->previous && current->index != to_find->index && count < mid)
        {
            count++;
            current = current->previous;
        }
        count++;
    }
    return (count);
}
