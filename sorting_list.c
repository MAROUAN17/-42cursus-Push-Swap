/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maglagal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 13:26:33 by maglagal          #+#    #+#             */
/*   Updated: 2024/01/27 20:00:55 by maglagal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	bring_to_top_a(t_linked **stack_a, t_linked *cheapest_node, int reverse)
{
	if (*stack_a && cheapest_node && reverse == 0)
	{
		while (*stack_a && (*stack_a)->index != cheapest_node->index)
			ra(stack_a);
	}
	else if (*stack_a && cheapest_node && reverse == 1)
	{
		while (*stack_a && (*stack_a)->index != cheapest_node->index)
			rra(stack_a);
	}
}

void	bring_to_top_b(t_linked **stack_b, t_linked *to_find_b, int reverse)
{
	if (*stack_b && to_find_b && reverse == 0)
	{
		while (*stack_b && (*stack_b)->index != to_find_b->index)
			rb(stack_b);
	}
	else if (*stack_b && to_find_b && reverse == 1)
	{
		while (*stack_b && (*stack_b)->index != to_find_b->index)
			rrb(stack_b);
	}
}

void	index_stack(t_linked **stack)
{
	int			lowest;
	t_linked	*first_node;
	t_linked	*browse_node;
	t_linked	*current;

	lowest = 0;
	first_node = (*stack);
	while (first_node)
	{
		lowest = 0;
		current = first_node;
		browse_node = *stack;
		while (browse_node)
		{
			if (current->data > browse_node->data)
				lowest++;
			browse_node = browse_node->next;
		}
		current->index = lowest;
		first_node = first_node->next;
	}
}

void	sort(t_linked **stack_a, t_linked **stack_b)
{
	int	count;

	index_stack(stack_a);
	count = count_stack (stack_a);
	if (count == 2)
		two_numbers_sort(stack_a);
	else if (count == 3)
		three_numbers_sort(stack_a);
	else if (count == 4)
		four_numbers_sort(stack_a, stack_b);
	else
		rest_of_numbers_sort(stack_a, stack_b);
}
