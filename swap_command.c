/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maglagal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 13:30:46 by maglagal          #+#    #+#             */
/*   Updated: 2024/01/27 13:30:47 by maglagal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	sa(t_linked **stack_a)
{
	int			tmp;
	t_linked	*current;

	current = *stack_a;
	if (current && current->next)
	{
		tmp = current->data;
		current->data = current->next->data;
		current->next->data = tmp;
		tmp = current->index;
		current->index = current->next->index;
		current->next->index = tmp;
	}
	write(1, "sa\n", 3);
}

void	sb(t_linked **stack_b)
{
	int			tmp;
	t_linked	*current;

	current = *stack_b;
	if (current && current->next)
	{
		tmp = current->data;
		current->data = current->next->data;
		current->next->data = tmp;
		tmp = current->index;
		current->index = current->next->index;
		current->next->index = tmp;
	}
	write(1, "sb\n", 3);
}

void	ss(t_linked **stack_a, t_linked **stack_b)
{
	int			tmp;
	t_linked	*current;

	current = *stack_a;
	if (current && current->next)
	{
		tmp = current->data;
		current->data = current->next->data;
		current->next->data = tmp;
		tmp = current->index;
		current->index = current->next->index;
		current->next->index = tmp;
	}
	current = *stack_b;
	if (current && current->next)
	{
		tmp = current->data;
		current->data = current->next->data;
		current->next->data = tmp;
		tmp = current->index;
		current->index = current->next->index;
		current->next->index = tmp;
	}
	write(1, "ss\n", 3);
}
