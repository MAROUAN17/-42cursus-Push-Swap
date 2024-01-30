/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_command_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maglagal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 15:13:26 by maglagal          #+#    #+#             */
/*   Updated: 2024/01/29 15:51:56 by maglagal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	pa(t_linked **stack_a, t_linked **stack_b)
{
	t_linked	*first_node;

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
}

void	pb(t_linked **stack_a, t_linked **stack_b)
{
	t_linked	*first_node;

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
}
