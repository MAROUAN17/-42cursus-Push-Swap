#include "checker_bonus.h"

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

void    make_instruction(l_linked **stack_a, l_linked **stack_b, char *instruction)
{
    if(ft_strncmp(instruction, "sa\n", 3) == 0)   
        sa(stack_a);
    else if(ft_strncmp(instruction, "sb\n", 3) == 0)
        sb(stack_a);
    else if(ft_strncmp(instruction, "ss\n", 3) == 0)
        ss(stack_a, stack_b);
    else if(ft_strncmp(instruction, "pa\n", 3) == 0)
        pa(stack_a, stack_b);
    else if(ft_strncmp(instruction, "pb\n", 3) == 0)
        pb(stack_a, stack_b);
    else if(ft_strncmp(instruction, "ra\n", 3) == 0)
        ra(stack_a);
    else if(ft_strncmp(instruction, "rb\n", 3) == 0)
        rb(stack_b);
    else if(ft_strncmp(instruction, "rr\n", 3) == 0)
        rr(stack_a, stack_b);
    else if(ft_strncmp(instruction, "rra\n", 4) == 0)    
        rra(stack_a);
    else if(ft_strncmp(instruction, "rrb\n", 4) == 0)
        rrb(stack_b);
    else if(ft_strncmp(instruction, "rrr\n", 4) == 0)
        rrr(stack_a, stack_b);
    else
    {    
        ft_printf("Error");
        exit(0);
    }
}

void    check_sort(l_linked **stack_a, int stack_len)
{
    l_linked *current = NULL;

    current = *stack_a;
    while(current->next)
    {
        if(current->data > current->next->data)
        {  
            ft_printf("KO");
            exit(0);
        }
        current = current->next;
    }
    if(current)
    {
        if(count_stack(stack_a) != stack_len - 1)
            ft_printf("KO");
        else
            ft_printf("OK");
        exit(1);
    }
}