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

l_linked *correct_position(l_linked **stack, l_linked *node, int len,int reverse)
{
    l_linked    *curr = NULL;
    int         i;

    i = 1;
    if(reverse == 0)
    {
        while(!curr)
        {
            curr = *stack;
            while(curr && curr->index != node->index - i)
                curr = curr->next;
            if(!curr)
                i++;
        }
    }
    else if(reverse == 1)
    {
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
    }
    return (curr);
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
        // while(current->next)
        // {
        //     count++;
        //     current = current->next;
        // }
        // ft_printf("mid -> %d\n", mid);
        // ft_printf("current -> %d\n", current->data);
        while(current && current->previous && current->index != to_find->index && count < mid)
        {
            count++;
            current = current->previous;
        }
        count++;
        // ft_printf("reverse pos -> %d\n", count);
    }
    return (count);
}

int count_cheapest(l_linked **stack_a,l_linked **stack_b, l_linked *to_find)
{
    int count;
    int position_a;
    int position_b;
    int mid_a;
    int mid_b;
    int i;
    int len_a;
    int len_b;
    l_linked *current_a = NULL;
    l_linked *current_b = NULL;
    l_linked *current_bl = NULL;

    len_a = count_stack(stack_a);
    len_b = count_stack(stack_b);
    mid_a = count_stack(stack_a) / 2;
    if(count_stack(stack_a) % 2 != 0)
        mid_a += 1;
    mid_b = count_stack(stack_b) / 2;
    if(count_stack(stack_b) % 2 != 0)
        mid_b += 1;
    count = 0;
    i = 1;
    position_a = find_position(stack_a, to_find);
    current_a = *stack_a;
    current_b = *stack_b;
    if(to_find->index > find_greatest(stack_b)->index || to_find->index < find_lowest(stack_b)->index)
    {
        position_b = find_position(stack_b, find_greatest(stack_b));
        if(position_a <= mid_a && position_b <= mid_b)
        {
            while(current_a->index != to_find->index && current_b->index != find_greatest(stack_b)->index)
            {
                count++;
                current_a = current_a->next;
                current_b = current_b->next;
            }
            if(current_a->index == to_find->index && current_b->index == find_greatest(stack_b)->index)
                count++;
            else
            {
                count += count_moves(&current_a, to_find, 0, mid_a);
                count += count_moves(&current_b, find_greatest(stack_b), 0, mid_b);
            }
        }
        else if (position_a > mid_a && position_b > mid_b)
        {
            // ft_printf("position_a -> %d\n", position_a);
            // ft_printf("mid_a -> %d\n", mid_a);
            // ft_printf("position_b -> %d\n", position_b);
            // ft_printf("mid_b -> %d\n", mid_b);
            while(current_a->next)
                current_a = current_a->next;
            while(current_b->next)
                current_b = current_b->next;
            if(current_a->index == to_find->index && current_b->index != find_greatest(stack_b)->index)
            {
                count++;
                current_b = current_b->previous;
            }
            else if(current_a->index != to_find->index && current_b->index == find_greatest(stack_b)->index)
            {
                count++;
                current_a = current_a->previous;
            }
            while(current_a && current_b && current_a->previous && current_b->previous 
                && current_a->index != to_find->index && current_b->index != find_greatest(stack_b)->index)
            {
                count++;
                current_a = current_a->previous;
                current_b = current_b->previous;
            }
            if(current_a->index == to_find->index && current_b->index == find_greatest(stack_b)->index)
                count++;
            else
            {
                if(current_a->index != to_find->index)
                    count += count_moves(&current_a, to_find, 1, mid_a);
                if(current_b->index != find_greatest(stack_b)->index)
                    count += count_moves(&current_b, find_greatest(stack_b), 1, mid_b);
            }
        }
        if(position_a <= mid_a && position_b > mid_b)
        {
            count += count_moves(stack_a, to_find, 0, mid_a);
            while(current_b->next)
                current_b = current_b->next;
            count += count_moves(&current_b, find_greatest(stack_b), 1, mid_b);
        }
        else if(position_a > mid_a && position_b <= mid_b)
        {
            // ft_printf("position_a -> %d\n", position_a);
            // ft_printf("mid_a -> %d\n", mid_a);
            // ft_printf("position_b -> %d\n", position_b);
            // ft_printf("mid_b -> %d\n", mid_b);
            while(current_a->next)
                current_a = current_a->next;
            count += count_moves(&current_a, to_find, 1, mid_a);
            count += count_moves(stack_b, find_greatest(stack_b), 0, mid_b);
        }
    }
    else
    {
        current_bl = correct_position(stack_b, to_find, len_b, 0);
        position_b = find_position(stack_b, current_bl);
        if(position_a <= mid_a && position_b <= mid_b)
        {
            while(current_a && current_b && current_a->next && current_b->next && current_a->index != to_find->index && current_b->index != current_bl->index)
            {
                count++;
                current_a = current_a->next;
                current_b = current_b->next;
            }
            count += count_moves(&current_a, to_find, 0, mid_a);
            count += count_moves(&current_b, current_bl, 0, mid_b);
        }
        else if(position_a > mid_a && position_b > mid_b)
        {
            while(current_a->next)
                current_a = current_a->next;
            while(current_b->next)
                current_b = current_b->next;
            if(current_a->index == to_find->index && current_b->index != current_bl->index)
            {
                count++;
                current_b = current_b->previous;
            }
            else if(current_a->index != to_find->index && current_b->index == current_bl->index)
            {
                count++;
                current_a = current_a->previous;
            }
            while(current_a && current_b && current_a->previous && current_b->previous && current_a->index != to_find->index && current_b->index != current_bl->index)
            {
                current_a = current_a->previous;
                current_b = current_b->previous;
                count++;
            }
            if(current_a->index == to_find->index && current_b->index == current_bl->index)
                count++;
            else
            {
                if(current_a->index != to_find->index)
                    count += count_moves(&current_a, to_find, 1, mid_a);
                if(current_b->index != current_bl->index)
                    count += count_moves(&current_b, current_bl, 1, mid_b);
            }
        }
        if(position_a <= mid_a && position_b > mid_b)
        {
            count += count_moves(stack_a, to_find, 0, mid_a);
            while(current_b->next)
                current_b = current_b->next;
            count += count_moves(&current_b, current_bl, 1, mid_b);
        }
        else if(position_a > mid_a && position_b <= mid_b)
        {
            // ft_printf("position_a -> %d\n", position_a);
            // ft_printf("mid_a -> %d\n", mid_a);
            // ft_printf("position_b -> %d\n", position_b);
            // ft_printf("mid_b -> %d\n", mid_b);
            while(current_a->next)
                current_a = current_a->next;
            count += count_moves(&current_a, to_find, 1, mid_a);
            count += count_moves(stack_b, current_bl, 0, mid_b);
        }
    }
    return (count + 1);
}

void    index_stack(l_linked **stack)
{
    int         lowest;
    l_linked    *first_node = NULL;
    l_linked    *browse_node = NULL;
    l_linked    *current = NULL;

    lowest = 0;
    first_node = (*stack);
    while(first_node)
    {
        lowest = 0;
        current = first_node;
        browse_node = *stack;
        while(browse_node)
        {
            if(current->data > browse_node->data)
                lowest++;
            browse_node = browse_node->next;
        }
        current->index = lowest;
        first_node = first_node->next;
    }
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
    // int lowest;
    // l_linked *smallest = NULL;
    l_linked *lowest_node = NULL;
    // l_linked *greatest_node = NULL;

    // lowest = 0;
    // smallest = 0;
    count = count_stack(stack_a);
    // if(count == 2)
    //     two_numbers_sort(stack_a);
    // if(count == 3)
    // {
    //     (void)stack_b;
    //     three_numbers_sort(stack_a);
    // }
    // else if(count == 4)
    // {
    //     lowest_node = find_lowest(stack_a);
    //     while((*stack_a)->data != lowest_node->data)
    //         ra(stack_a);
    //     pb(stack_a, stack_b);
    //     three_numbers_sort(stack_a);
    //     pa(stack_a, stack_b);
    // }
    // else if(count == 5)
    // {
    //     while(count_stack(stack_a) > 3)
    //     {
    //         lowest_node = find_lowest(stack_a);
    //         while((*stack_a)->data != lowest_node->data)
    //             ra(stack_a);
    //         pb(stack_a, stack_b);
    //     }
    //     three_numbers_sort(stack_a);
    //     pa(stack_a, stack_b);
    //     pa(stack_a, stack_b);
    // }
    if(count > 5)
    {
        l_linked *cheapest_node = NULL;
        l_linked *current = NULL;
        l_linked *curr = NULL;
        int count = 0;
        int mid_a = 0;
        int mid_b = 0;
        int start;
        int end;
        int len_a;
        int len_b;
        len_a = count_stack(stack_a);
        len_b = count_stack(stack_b);
        lowest_node = find_lowest(stack_a);
        index_stack(stack_a);
        start = 0;
        end = 19;
        pb(stack_a, stack_b);
        pb(stack_a, stack_b);
        // display(stack_a);
        // ft_printf("| a\n");
        // display(stack_b);
        // ft_printf("| b\n");
        while(count_stack(stack_a) > 3)
        {
            current = (*stack_a)->next;
            cheapest_node = *stack_a;
            // ft_printf("default cheapest is %d\n", cheapest_node->data);
            // ft_printf("default cheapest moves %d\n", count_cheapest(stack_a, stack_b, cheapest_node));
            while(current)
            {
                // ft_printf("cheapest is %d\n", current->data);
                // ft_printf("nbr of moves -> %d\n", count_cheapest(stack_a, stack_b, current));
                if(count_cheapest(stack_a, stack_b, current) == 1)
                {    
                    cheapest_node = current;
                    break;
                }
                else if(count_cheapest(stack_a, stack_b, current) < count_cheapest(stack_a, stack_b, cheapest_node))
                {
                    count = count_cheapest(stack_a, stack_b, current);
                    cheapest_node = current;
                }
                current = current->next;
            }
            // display(stack_a);
            // ft_printf("| a\n");
            // display(stack_b);
            // ft_printf("| b\n");
            // ft_printf("cheapest is %d\n", cheapest_node->data);
            mid_a = count_stack(stack_a) / 2;
            if(count_stack(stack_a) % 2 != 0)
                mid_a += 1;
            mid_b = count_stack(stack_b) / 2;
            if(count_stack(stack_b) % 2 != 0)
                mid_b += 1;
            if(cheapest_node->index > find_greatest(stack_b)->index || cheapest_node->index < find_lowest(stack_b)->index)
            {
                if(find_position(stack_a, cheapest_node) < mid_a && find_position(stack_b, find_greatest(stack_b)) < mid_b)
                {
                    while((*stack_a)->index != cheapest_node->index && (*stack_b)->index != find_greatest(stack_b)->index)
                        rr(stack_a, stack_b);
                }
                else if(find_position(stack_a, cheapest_node) >= mid_a && find_position(stack_b, find_greatest(stack_b)) >= mid_b)
                {
                    while((*stack_a)->index != cheapest_node->index && (*stack_b)->index != find_greatest(stack_b)->index)
                        rrr(stack_a, stack_b);
                }
                if(find_position(stack_a, cheapest_node) < mid_a)
                {
                    while((*stack_a)->index != cheapest_node->index)
                        ra(stack_a);
                }
                else
                {
                    while((*stack_a)->index != cheapest_node->index)
                        rra(stack_a);
                }
                if(find_position(stack_b, find_greatest(stack_b)) < mid_b)
                {
                    while ((*stack_b)->index != find_greatest(stack_b)->index)
                        rb(stack_b);
                }
                else
                {
                    while ((*stack_b)->index != find_greatest(stack_b)->index)
                        rrb(stack_b);
                }
            }
            else
            {
                curr = correct_position(stack_b, cheapest_node, len_b, 0);
                if(find_position(stack_a, cheapest_node) < mid_a && find_position(stack_b, curr) < mid_b)
                {
                    while((*stack_a)->index != cheapest_node->index && (*stack_b)->index != curr->index)
                        rr(stack_a, stack_b);
                }
                else if(find_position(stack_a, cheapest_node) >= mid_a && find_position(stack_b, curr) >= mid_b)
                {
                    while((*stack_a)->index != cheapest_node->index && (*stack_b)->index != curr->index)
                        rrr(stack_a, stack_b);
                }
                if(find_position(stack_a, cheapest_node) < mid_a)
                {
                    while((*stack_a)->index != cheapest_node->index)
                        ra(stack_a);
                }
                else
                {
                    while((*stack_a)->index != cheapest_node->index)
                        rra(stack_a);
                }
                if(find_position(stack_b, curr) < mid_b)
                {
                    while ((*stack_b)->index != curr->index)
                        rb(stack_b);
                }
                else
                {
                    while ((*stack_b)->index != curr->index)
                        rrb(stack_b);
                }
            }
            pb(stack_a, stack_b);
            // display(stack_a);
            // ft_printf("| a\n");
            // display(stack_b);
            // ft_printf("| b\n");
        }
        three_numbers_sort(stack_a);
        // display(stack_a);
        // ft_printf("| a\n");
        // display(stack_b);
        // ft_printf("| b\n");
        // ft_printf("back to a!!\n");
        while(*stack_b)
        {
            curr = correct_position(stack_a, *stack_b, len_a ,1);
            mid_a = count_stack(stack_a) / 2;
            if(count_stack(stack_a) % 2 != 0)
                mid_a += 1;
            int position1 = find_position(stack_a, curr);
            if(position1 < mid_a)
            {
                while((*stack_a)->index != curr->index)
                    ra(stack_a);
            }
            else
            {
                while((*stack_a)->index != curr->index)
                    rra(stack_a);
            }
            // display(stack_a);
            // ft_printf("| a\n");
            // display(stack_b);
            // ft_printf("| b\n");
            pa(stack_a, stack_b);
        }
        // display(stack_a);
        // ft_printf("| a\n");
        // display(stack_b);
        // ft_printf("| b\n");
        mid_a = count_stack(stack_a) / 2;
        if(count_stack(stack_a) % 2 != 0)
            mid_a += 1;
        // ft_printf("count stack -> %d\n", count_stack(stack_a));
        // ft_printf("mid_a -> %d\n", mid_a);
        // display(stack_a);
        // ft_printf("| a\n");
        // display(stack_b);
        // ft_printf("| b\n");
        int position2 = find_position(stack_a, find_lowest(stack_a));
        // ft_printf("position of lowest -> %d\n", find_position(stack_a, find_lowest(stack_a)));
        // ft_printf("mid of the stack -> %d\n", mid_a);
        if(position2 < mid_a)
        {
            while((*stack_a)->index != find_lowest(stack_a)->index)
                ra(stack_a);
        }
        else
        {
            while((*stack_a)->index != find_lowest(stack_a)->index)
                rra(stack_a);
        }

    // display(stack_a);
    // ft_printf("| a\n");
    // display(stack_b);
    // ft_printf("| b\n");
    }
}
