#include "checker_bonus.h"

void free_stack(l_linked **head)
{
    l_linked *current = NULL;
    l_linked *tmp = NULL;

    current = *head;
    while(current)
    {    
        tmp = current;
        current = current->next;
        free(tmp);
    }
}

void    createNode(l_linked **head, int data)
{
    l_linked    *newNode = NULL;
    l_linked    *current = NULL;

    newNode = (l_linked *)malloc(sizeof(l_linked));
    if(!newNode)
        return;
    newNode->data = data;
    newNode->next = NULL;
    newNode->index = 0;
    if(!*head)
    {
        *head = newNode;
        newNode->previous = NULL;
    }
    else
    {
        current = *head;
        while(current->next)
            current = current->next;
        current->next = newNode;
        newNode->previous = current;
    }
}

void    receive_instruction(l_linked **stack_a, l_linked **stack_b, int len)
{
    char *instruction;

    instruction = get_next_line(0);
    while(instruction)
    {
        make_instruction(stack_a, stack_b, instruction);
        instruction = get_next_line(0);
        if(!instruction)
            check_sort(stack_a, len);
    }
}

int main(int ac, char **av)
{
    l_linked    *stack_a = NULL;
    l_linked    *stack_b = NULL;

    if(ac > 2)
        check_multiple_arguments(ac, av, &stack_a, &stack_b);
    else if(ac == 2)  
        check_one_argument(av, &stack_a, &stack_b);
    free_stack(&stack_a);
    free_stack(&stack_b);
}
