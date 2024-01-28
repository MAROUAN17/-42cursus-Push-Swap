/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maglagal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 10:35:55 by maglagal          #+#    #+#             */
/*   Updated: 2024/01/27 10:35:56 by maglagal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

t_linked	*find_lowest(t_linked **stack)
{
	t_linked	*current;
	t_linked	*lowest;

	current = *stack;
	lowest = current;
	while (current)
	{
		if (current->data < lowest->data)
			lowest = current;
		current = current->next;
	}
	return (lowest);
}

t_linked	*find_greatest(t_linked **stack)
{
	t_linked	*current;
	t_linked	*greatest;

	current = *stack;
	greatest = current;
	while (current)
	{
		if (current->data > greatest->data)
			greatest = current;
		current = current->next;
	}
	return (greatest);
}

int	find_position(t_linked **stack, t_linked *to_find)
{
	t_linked	*current;
	int			position;

	current = *stack;
	position = 1;
	while (current->data != to_find->data)
	{
		position++;
		current = current->next;
	}
	return (position);
}

int	count_stack(t_linked **stack)
{
	int			count;
	t_linked	*current;

	count = 0;
	current = *stack;
	while (current)
	{
		count++;
		current = current->next;
	}
	return (count);
}

int	count_moves(t_linked **stack, t_linked *to_find, int reverse, int mid)
{
	t_linked	*current;
	int			count;

	count = 0;
	current = *stack;
	if (reverse == 0)
	{
		while (current->index != to_find->index && count <= mid)
		{
			count++;
			current = current->next;
		}
	}
	else
	{
		while (current && current->previous
			&& current->index != to_find->index && count < mid)
		{
			count++;
			current = current->previous;
		}
		count++;
	}
	return (count);
}
