/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maglagal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 10:33:01 by maglagal          #+#    #+#             */
/*   Updated: 2024/01/29 15:55:45 by maglagal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	pa(t_linked **stack_a, t_linked **stack_b)
{
	t_linked	*first_node;

	first_node = NULL;
	if (*stack_b)
	{
		first_node = *stack_b;
		if ((*stack_b)->next)
		{
			*stack_b = (*stack_b)->next;
			(*stack_b)->previous = NULL;
		}
		else
			(*stack_b) = NULL;
		first_node->next = *stack_a;
		first_node->previous = NULL;
		if (*stack_a)
			(*stack_a)->previous = first_node;
		*stack_a = first_node;
	}
	write(1, "pa\n", 3);
}

void	pb(t_linked **stack_a, t_linked **stack_b)
{
	t_linked	*first_node;

	first_node = NULL;
	if (*stack_a)
	{
		first_node = *stack_a;
		if ((*stack_a)->next)
		{
			*stack_a = (*stack_a)->next;
			(*stack_a)->previous = NULL;
		}
		else
			*stack_a = NULL;
		first_node->next = *stack_b;
		first_node->previous = NULL;
		if (*stack_b)
			(*stack_b)->previous = first_node;
		*stack_b = first_node;
	}
	write(1, "pb\n", 3);
}
