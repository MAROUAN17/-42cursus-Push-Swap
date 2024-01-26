#include "header.h"

l_linked *find_cheapest(l_linked **stack_a, l_linked **stack_b)
{
    l_linked *current = NULL;
    l_linked *cheapest_node = NULL;
    int count;
    
    current = (*stack_a)->next;
    cheapest_node = *stack_a;
    while(current)
    {
        if(count_cheapest(stack_a, stack_b, current) == 1)
        {    
            cheapest_node = current;
            return (cheapest_node);
        }
        else if(count_cheapest(stack_a, stack_b, current) < count_cheapest(stack_a, stack_b, cheapest_node))
        {
            count = count_cheapest(stack_a, stack_b, current);
            cheapest_node = current;
        }
        current = current->next;
    }
    return (cheapest_node);
}

void    applying_cheapest(l_linked **stack_a, l_linked **stack_b, l_linked *cheapest_node, l_linked *to_find_b)
{
    int mid_a;
    int mid_b;

    mid_a = count_stack_mid(stack_a);
    mid_b = count_stack_mid(stack_b);
    if(find_position(stack_a, cheapest_node) <= mid_a && find_position(stack_b, to_find_b) <= mid_b)
    {
        while((*stack_a)->index != cheapest_node->index && (*stack_b)->index != to_find_b->index)
            rr(stack_a, stack_b);
    }
    else if(find_position(stack_a, cheapest_node) > mid_a && find_position(stack_b, to_find_b) > mid_b)
    {
        while((*stack_a)->index != cheapest_node->index && (*stack_b)->index != to_find_b->index)
            rrr(stack_a, stack_b);
    }
    if(find_position(stack_a, cheapest_node) <= mid_a)
        bring_to_top_a(stack_a, cheapest_node, 0);
    else
        bring_to_top_a(stack_a, cheapest_node, 1);
    if(find_position(stack_b, to_find_b) <= mid_b)
        bring_to_top_b(stack_b, to_find_b, 0);
    else
        bring_to_top_b(stack_b, to_find_b, 1);
}

void    back_to_b(l_linked **stack_a, l_linked **stack_b, int len)
{
    l_linked *curr = NULL;
    int mid_a;
    int position;
    
    mid_a = count_stack_mid(stack_a);
    curr = correct_position(stack_a, *stack_b, len, 1);
    position = find_position(stack_a, curr);
    if(position <= mid_a)
        bring_to_top_a(stack_a, curr, 0);
    else
        bring_to_top_a(stack_a, curr, 1);
    pa(stack_a, stack_b);
}

void    make_lowest_at_top(l_linked **stack_a)
{
    int mid_a;
    int position;

    mid_a = count_stack_mid(stack_a);
    position = find_position(stack_a, find_lowest(stack_a));
    if(position <= mid_a)
        bring_to_top_a(stack_a, find_lowest(stack_a), 0);
    else
        bring_to_top_a(stack_a, find_lowest(stack_a), 1);
}

void rest_of_numbers_sort(l_linked **stack_a, l_linked **stack_b)
{
    l_linked    *cheapest_node = NULL;
    l_linked    *curr = NULL;
    int         len_a;
    int         len_b;

    len_a = count_stack(stack_a);
    len_b = count_stack(stack_b);
    pb(stack_a, stack_b);
    pb(stack_a, stack_b);
    while(count_stack(stack_a) > 3)
    {
        cheapest_node = find_cheapest(stack_a, stack_b);
        if(cheapest_node->index > find_greatest(stack_b)->index || cheapest_node->index < find_lowest(stack_b)->index)
            applying_cheapest(stack_a, stack_b, cheapest_node, find_greatest(stack_b));
        else
        {
            curr = correct_position(stack_b, cheapest_node, len_b, 0);
            applying_cheapest(stack_a, stack_b, cheapest_node, curr);
        }
        pb(stack_a, stack_b);
    }
    three_numbers_sort(stack_a);
    while(*stack_b)
        back_to_b(stack_a, stack_b, len_a);
    make_lowest_at_top(stack_a);
}
