#include "header.h"

l_linked    *find_in_stack_a(l_linked **stack, l_linked *node, int len)
{
    l_linked    *curr = NULL;
    int         i;

    i = 1;
    while(!curr && i <= len)
    {
        curr = *stack;
        while(curr && curr->index != node->index + i)
            curr = curr->next;
        if(!curr)
            i++;
    }
    if(!curr)
        curr = find_lowest(stack);
    return(curr);
}

l_linked    *find_in_stack_b(l_linked **stack, l_linked *node)
{
    l_linked    *curr = NULL;
    int         i;

    i = 1;
    while(!curr)
    {
        curr = *stack;
        while(curr && curr->index != node->index - i)
            curr = curr->next;
        if(!curr)
            i++;
    }
    return(curr);
}

l_linked    *correct_position(l_linked **stack, l_linked *node, int len, int back)
{
    l_linked    *curr = NULL;

    if(back == 0)
        curr = find_in_stack_b(stack, node);
    else if(back == 1)
        curr = find_in_stack_a(stack, node, len);
    return(curr);
}

int count_stack_mid(l_linked **stack)
{
    int mid;
    
    mid = count_stack(stack) / 2;
    if(count_stack(stack) % 2 != 0)
        mid += 1;
    else if(count_stack(stack) == 2)
        mid = 2;
    return (mid);
}

l_linked    *check_before_sort(l_linked **stack_a)
{
    l_linked    *curr = NULL;

    curr = *stack_a;
    while(curr->next)
    {
        if(curr->data < curr->next->data)
            curr = curr->next;
        else
        {
            curr = NULL;  
            break;
        }
    }
    return (curr);
}
