#include "header.h"

int count_numbers(l_linked **stack)
{
    int         count;
    l_linked    *current = NULL;

    count = 0;
    current = *stack;
    while(current)
    {
        current = current->next;
        count++;
    }
    return (count);
}

int count_cheapest(l_linked **stack_a, l_linked *to_find, int reverse)
{
    l_linked *current;
    int counter;

    counter = 0;
    if(reverse == 0)
    {
        current = *stack_a;
        while(current && current->data != to_find->data)
        {    
            counter++;
            current = current->next;
        }
    }
    else
    {
        current = *stack_a;
        while(current->next)
            current = current->next;
        while(current && to_find->data != current->data)
        {   
            counter++;
            current = current->previous;
        }
        counter++;
    }
    return (counter);
}

l_linked    *find_in_chunk(l_linked **stack, l_linked *hold_first, int start, int end)
{
    l_linked *current = NULL;
    int count;
    int mid;

    count = 0;
    if(count_numbers(stack) % 2 != 0)
        mid = (count_numbers(stack) / 2) + 1;
    else
        mid = (count_numbers(stack) / 2);
    current = *stack;
    while(current && count <= mid)
    {
        if (current->data >= start && current->data <= end)
        {
            hold_first = current;
            return (hold_first);
        }
        else
        {
            current = current->next;
            count++;
        }
    }
    return (NULL);
}

l_linked    *r_find_in_chunk(l_linked **stack, l_linked *hold_second, int start, int end)
{
    l_linked *current = NULL;
    int count;
    int mid;

    count = 0;
    if(count_numbers(stack) % 2 != 0)
        mid = (count_numbers(stack) / 2) + 1;
    else
        mid = (count_numbers(stack) / 2);
    current = *stack;
    while(current->next)
    {    
        current = current->next;
        count++;
    }
    while(current && count > mid)
    {
        if(current->data >= start && current->data <= end)
        {
            hold_second = current;
            return (hold_second);
        }
        else
        {
            current = current->previous;
            count--;
        }
    }
    return (NULL);
}

int find_position(l_linked **stack, l_linked *to_find)
{
    l_linked *current = NULL;
    int position;

    current = *stack;
    position = 0;
    while(current->data != to_find->data)
    {
        position++;
        current = current->next;
    }
    return (position);
}

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

void    three_numbers_sort(l_linked **stack_a)
{
    if((*stack_a)->data > (*stack_a)->next->data && (*stack_a)->next->data < (*stack_a)->next->next->data && (*stack_a)->data < (*stack_a)->next->next->data)
            sa(stack_a);
    else if((*stack_a)->data > (*stack_a)->next->data && (*stack_a)->next->data > (*stack_a)->next->next->data)
    {    
        sa(stack_a);
        rra(stack_a);
    }
    else if((*stack_a)->data > (*stack_a)->next->data && (*stack_a)->next->data < (*stack_a)->next->next->data && (*stack_a)->data > (*stack_a)->next->next->data)
        ra(&(*stack_a));
    else if((*stack_a)->data < (*stack_a)->next->data && (*stack_a)->next->data > (*stack_a)->next->next->data && (*stack_a)->data < (*stack_a)->next->next->data)
    {
        sa(stack_a);
        ra(stack_a);
    }
    else if((*stack_a)->data < (*stack_a)->next->data && (*stack_a)->next->data > (*stack_a)->next->next->data && (*stack_a)->data > (*stack_a)->next->next->data)
        rra(stack_a);
}

void    two_numbers_sort(l_linked **stack)
{
    if((*stack)->data > (*stack)->next->data)
        sa(stack);
}

void    sort(l_linked **stack_a, l_linked **stack_b)
{
    int count;
    int lowest;
    l_linked *smallest = NULL;
    l_linked *lowest_node = NULL;
    l_linked *greatest_node = NULL;

    lowest = 0;
    smallest = 0;
    count = count_numbers(stack_a);
    if(count == 2)
        two_numbers_sort(stack_a);
    if(count == 3)
    {
        (void)stack_b;
        three_numbers_sort(stack_a);
    }
    else if(count == 4)
    {
        lowest_node = find_lowest(stack_a);
        while((*stack_a)->data != lowest_node->data)
            ra(stack_a);
        pb(stack_a, stack_b);
        three_numbers_sort(stack_a);
        pa(stack_a, stack_b);
    }
    else if(count == 5)
    {
        while(count_numbers(stack_a) > 3)
        {
            lowest_node = find_lowest(stack_a);
            while((*stack_a)->data != lowest_node->data)
                ra(stack_a);
            pb(stack_a, stack_b);
        }
        three_numbers_sort(stack_a);
        pa(stack_a, stack_b);
        pa(stack_a, stack_b);
    }
    else
    {
        l_linked *hold_first = NULL;
        l_linked *hold_second = NULL; 
        int start;
        int end;

        lowest_node = find_lowest(stack_a);
        start = lowest_node->data;
        end = start + 19;
        while(*stack_a && end <= find_greatest(stack_a)->data)
        {
            while(*stack_a && !hold_first && !hold_second)
            {
                if(count_numbers(stack_a) > 1)
                {

                    hold_first = find_in_chunk(stack_a, hold_first, start, end);
                    hold_second = r_find_in_chunk(stack_a, hold_second, start, end);
                    if(!hold_first && !hold_second)
                        break;
                    else if(hold_first && hold_second)
                    {
                        if(count_cheapest(stack_a, hold_first, 0) <= count_cheapest(stack_a, hold_second, 1))
                        {
                            while((*stack_a)->data != hold_first->data)
                                ra(stack_a);
                        }
                        else if(count_cheapest(stack_a, hold_first, 0) > count_cheapest(stack_a, hold_second, 1))
                        {
                            while((*stack_a)->data != hold_second->data)
                                rra(stack_a);
                        }
                    }
                    else
                    {
                        if(hold_first)
                        {
                            while((*stack_a)->data != hold_first->data)
                                ra(stack_a);
                        }
                        else
                        {
                            while((*stack_a)->data != hold_second->data)    
                                rra(stack_a);
                        }
                    }
                }
                if(*stack_b)
                {
                    lowest_node = find_lowest(stack_b);
                    if(count_cheapest(stack_b, lowest_node, 0) <=  count_cheapest(stack_b, lowest_node, 1))
                    { 
                        while((*stack_b)->data != lowest_node->data)
                            rb(stack_b);
                    }
                    else
                    {
                        while((*stack_b)->data != lowest_node->data)
                            rrb(stack_b);
                    }
                }
                if(*stack_a)
                    pb(stack_a, stack_b);
                hold_first = NULL;
                hold_second = NULL;
            }
            start = end;
            end += 19;
        }
        while(*stack_b)
        {
            greatest_node = find_greatest(stack_b);
            if(count_cheapest(stack_b, greatest_node, 0) <=  count_cheapest(stack_b, greatest_node, 1))
            {
                while((*stack_b)->data != greatest_node->data)
                    rb(stack_b);
            }
            else
            {
                while((*stack_b)->data != greatest_node->data)
                    rrb(stack_b);
            }
            pa(stack_a, stack_b);
        }
    }

    display(stack_a);
    ft_printf("| a\n");
    display(stack_b);
    ft_printf("| b\n");
}
