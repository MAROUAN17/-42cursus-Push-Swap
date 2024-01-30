/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_rotate_command.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maglagal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 11:48:09 by maglagal          #+#    #+#             */
/*   Updated: 2024/01/29 15:54:57 by maglagal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	get_before_last_node(t_linked **before_last)
{
	t_linked	*current;

	current = *before_last;
	while (current->next)
	{
		*before_last = current;
		current = current->next;
	}
}

void	rra(t_linked **stack_a)
{
	t_linked	*last_node;
	t_linked	*before_last;

	if (*stack_a && (*stack_a)->next)
	{
		last_node = *stack_a;
		before_last = *stack_a;
		get_last_node(&last_node);
		get_before_last_node(&before_last);
		before_last->next = NULL;
		(*stack_a)->previous = last_node;
		last_node->next = *stack_a;
		last_node->previous = NULL;
		*stack_a = last_node;
	}
	write(1, "rra\n", 4);
}

void	rrb(t_linked **stack_b)
{
	t_linked	*last_node;
	t_linked	*before_last;

	if (*stack_b && (*stack_b)->next)
	{
		last_node = *stack_b;
		before_last = *stack_b;
		get_last_node(&last_node);
		get_before_last_node(&before_last);
		before_last->next = NULL;
		(*stack_b)->previous = last_node;
		last_node->next = *stack_b;
		last_node->previous = NULL;
		*stack_b = last_node;
	}
	write(1, "rrb\n", 4);
}

void	rrr(t_linked **stack_a, t_linked **stack_b)
{
	t_linked	*last_node;
	t_linked	*before_last;

	if (*stack_a && (*stack_a)->next && *stack_b && (*stack_b)->next)
	{
		last_node = *stack_a;
		before_last = *stack_a;
		get_last_node(&last_node);
		get_before_last_node(&before_last);
		before_last->next = NULL;
		(*stack_a)->previous = last_node;
		last_node->next = *stack_a;
		last_node->previous = NULL;
		*stack_a = last_node;
		last_node = *stack_b;
		before_last = *stack_b;
		get_last_node(&last_node);
		get_before_last_node(&before_last);
		before_last->next = NULL;
		(*stack_b)->previous = last_node;
		last_node->next = *stack_b;
		last_node->previous = NULL;
		*stack_b = last_node;
	}
	write(1, "rrr\n", 4);
}
