/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maglagal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 10:54:14 by maglagal          #+#    #+#             */
/*   Updated: 2024/01/27 20:42:39 by maglagal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	get_last_node(t_linked **last_node)
{
	while ((*last_node)->next)
		*last_node = (*last_node)->next;
}

void	free_stack(t_linked **head)
{
	t_linked	*current;
	t_linked	*tmp;

	tmp = NULL;
	current = *head;
	while (current)
	{
		tmp = current;
		current = current->next;
		free(tmp);
	}
}

void	display(t_linked **stack)
{
	t_linked	*current;

	current = *stack;
	while (current)
	{
		ft_printf("index -> %d, nbr -> %d\n", current->index, current->data);
		current = current->next;
	}
}

void	create_node(t_linked **head, int data)
{
	t_linked	*new_node;
	t_linked	*current;

	current = NULL;
	new_node = (t_linked *)malloc(sizeof(t_linked));
	if (!new_node)
	{
		free_stack(head);
		return ;
	}
	new_node->data = data;
	new_node->next = NULL;
	new_node->index = 0;
	if (!*head)
	{
		*head = new_node;
		new_node->previous = NULL;
	}
	else
	{
		current = *head;
		get_last_node(&current);
		current->next = new_node;
		new_node->previous = current;
	}
}

int	main(int ac, char **av)
{
	int			check;
	t_linked	*stack_a;
	t_linked	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (ac >= 2)
	{
		check = check_arguments(ac, av, &stack_a);
		if (!check)
			ft_printf("Error");
		else if (check && !check_before_sort(&stack_a))
			sort(&stack_a, &stack_b);
		free_stack(&stack_a);
		free_stack(&stack_b);
	}
}
