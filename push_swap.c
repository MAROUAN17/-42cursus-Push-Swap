#include "header.h"

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

void    display(l_linked **stack)
{
    l_linked *current;

    current = *stack;
    while(current)
    {
        ft_printf("index -> %d, nbr -> %d\n", current->index, current->data);
        current = current->next;
    }
}

void    createNode(l_linked **head, int data)
{
    l_linked    *newNode = NULL;
    l_linked    *current = NULL;

    newNode = (l_linked *)malloc(sizeof(l_linked));
    if(!newNode)
    {
        if(*head)
            free_stack(head);
        return;
    }
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
