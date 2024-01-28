/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three_numbers.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maglagal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 13:21:16 by maglagal          #+#    #+#             */
/*   Updated: 2024/01/27 13:23:05 by maglagal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	three_numbers_sort(t_linked **stack_a)
{
	if ((*stack_a)->data > (*stack_a)->next->data
		&& (*stack_a)->next->data < (*stack_a)->next->next->data
		&& (*stack_a)->data < (*stack_a)->next->next->data)
		sa(stack_a);
	else if ((*stack_a)->data > (*stack_a)->next->data
		&& (*stack_a)->next->data > (*stack_a)->next->next->data)
	{
		sa(stack_a);
		rra(stack_a);
	}
	else if ((*stack_a)->data > (*stack_a)->next->data
		&& (*stack_a)->next->data < (*stack_a)->next->next->data
		&& (*stack_a)->data > (*stack_a)->next->next->data)
		ra(&(*stack_a));
	else if ((*stack_a)->data < (*stack_a)->next->data
		&& (*stack_a)->next->data > (*stack_a)->next->next->data
		&& (*stack_a)->data < (*stack_a)->next->next->data)
	{
		sa(stack_a);
		ra(stack_a);
	}
	else if ((*stack_a)->data < (*stack_a)->next->data
		&& (*stack_a)->next->data > (*stack_a)->next->next->data
		&& (*stack_a)->data > (*stack_a)->next->next->data)
		rra(stack_a);
}
