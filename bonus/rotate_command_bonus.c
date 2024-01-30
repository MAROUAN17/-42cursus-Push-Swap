/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_command_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maglagal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 15:17:29 by maglagal          #+#    #+#             */
/*   Updated: 2024/01/27 15:17:30 by maglagal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	ra(t_linked **stack_a)
{
	t_linked	*last_node;
	t_linked	*first_node;

	if (*stack_a && (*stack_a)->next)
	{
		first_node = *stack_a;
		last_node = *stack_a;
		while (last_node->next)
			last_node = last_node->next;
		*stack_a = (*stack_a)->next;
		last_node->next = first_node;
		first_node->previous = last_node;
		first_node->next = NULL;
		(*stack_a)->previous = NULL;
	}
}

void	rb(t_linked **stack_b)
{
	t_linked	*last_node;
	t_linked	*first_node;

	if (*stack_b && (*stack_b)->next)
	{
		first_node = *stack_b;
		last_node = *stack_b;
		while (last_node->next)
			last_node = last_node->next;
		*stack_b = (*stack_b)->next;
		last_node->next = first_node;
		first_node->previous = last_node;
		first_node->next = NULL;
		(*stack_b)->previous = NULL;
	}
}

void	rr(t_linked **stack_a, t_linked **stack_b)
{
	t_linked	*last_node_a;
	t_linked	*first_node_a;
	t_linked	*last_node_b;
	t_linked	*first_node_b;

	if (*stack_a && (*stack_a)->next && *stack_b && (*stack_b)->next)
	{
		first_node_a = *stack_a;
		last_node_a = *stack_a;
		get_last_node(&last_node_a);
		*stack_a = (*stack_a)->next;
		last_node_a->next = first_node_a;
		first_node_a->previous = last_node_a;
		first_node_a->next = NULL;
		(*stack_a)->previous = NULL;
		first_node_b = *stack_b;
		last_node_b = *stack_b;
		get_last_node(&last_node_b);
		*stack_b = (*stack_b)->next;
		last_node_b->next = first_node_b;
		first_node_b->previous = last_node_b;
		first_node_b->next = NULL;
		(*stack_b)->previous = NULL;
	}
}
