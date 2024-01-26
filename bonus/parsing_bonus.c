#include "checker_bonus.h"

void    check_multiple_arguments(int ac, char **av, l_linked **stack_a, l_linked **stack_b)
{
    int         number;
    int         index;
    int         check;

    index = 1;
    check = 0;
    number = 0;
    while(index < ac)
    {
        if((check_number(av[index]) != ft_strlen(av[index]))
            || (check_max_min(ft_atoi(av[index])) == 1))
        {   
            check = 1;
            break;
        }
        createNode(stack_a, ft_atoi(av[index]));
        index++;
    }
    if(check || check_doubles(*stack_a))
        ft_printf("Error\n");
    else
        receive_instruction(stack_a, stack_b, ac);
}

void    check_one_argument(char **av, l_linked **stack_a, l_linked **stack_b)
{
    int     check;
    int     index;
    int     nbr_num;
    char    **numbers;

    check = 0;
    index = 0;
    nbr_num = 0;
    *stack_b = NULL;
    numbers = ft_split(av[1], ' ');
    while(numbers[nbr_num])
        nbr_num++;
    while(index < nbr_num)
    {
        if(((check_number(numbers[index]) != ft_strlen(numbers[index]))
            || (check_max_min(ft_atoi(numbers[index])) == 1)))
        {
            check = 1;
            break;
        }
        createNode(stack_a, ft_atoi(numbers[index]));
        index++;
    }
    if(check || check_doubles(*stack_a))    
        ft_printf("Error\n");
    else
        receive_instruction(stack_a, stack_b, index + 1);
}