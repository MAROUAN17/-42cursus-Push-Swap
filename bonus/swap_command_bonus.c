/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_command_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maglagal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 15:19:53 by maglagal          #+#    #+#             */
/*   Updated: 2024/01/27 15:19:54 by maglagal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	sa(t_linked **stack_a)
{
	int			tmp;
	t_linked	*current;

	tmp = 0;
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
}

void	sb(t_linked **stack_b)
{
	int			tmp;
	t_linked	*current;

	tmp = 0;
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
}
