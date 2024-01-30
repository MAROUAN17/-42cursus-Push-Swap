/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_command.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maglagal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 13:19:36 by maglagal          #+#    #+#             */
/*   Updated: 2024/01/29 09:59:48 by maglagal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ra(t_linked **stack_a)
{
	t_linked	*last_node;
	t_linked	*first_node;

	if (*stack_a)
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
	write(1, "ra\n", 3);
}

void	rb(t_linked **stack_b)
{
	t_linked	*last_node;
	t_linked	*first_node;

	if (*stack_b)
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
	write(1, "rb\n", 3);
}

void	rr(t_linked **stack_a, t_linked **stack_b)
{
	t_linked	*last_node;
	t_linked	*first_node;

	if (*stack_a && *stack_b)
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
	write(1, "rr\n", 3);
}
