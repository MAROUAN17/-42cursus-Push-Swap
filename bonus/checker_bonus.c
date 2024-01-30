/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maglagal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 15:05:31 by maglagal          #+#    #+#             */
/*   Updated: 2024/01/29 16:32:50 by maglagal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	free_stack(t_linked **head)
{
	t_linked	*current;
	t_linked	*tmp;

	current = *head;
	while (current)
	{
		tmp = current;
		current = current->next;
		free(tmp);
	}
}

void	create_node(t_linked **head, int data)
{
	t_linked	*newnode;
	t_linked	*current;

	current = NULL;
	newnode = (t_linked *)malloc(sizeof(t_linked));
	if (!newnode)
		return ;
	newnode->data = data;
	newnode->next = NULL;
	newnode->index = 0;
	if (!*head)
	{
		*head = newnode;
		newnode->previous = NULL;
	}
	else
	{
		current = *head;
		while (current->next)
			current = current->next;
		current->next = newnode;
		newnode->previous = current;
	}
}

void	receive_instruction(t_linked **stack_a, t_linked **stack_b, int len)
{
	char	*instruction;

	instruction = get_next_line(0);
	while (instruction)
	{
		make_instruction(stack_a, stack_b, instruction);
		instruction = get_next_line(0);
		if (!instruction)
			check_sort(stack_a, len);
	}
}

int	main(int ac, char **av)
{
	t_linked	*stack_a;
	t_linked	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (ac >= 2)
	{
		check_arguments(ac, av, &stack_a, &stack_b);
		free_stack(&stack_a);
		free_stack(&stack_b);
	}
}
