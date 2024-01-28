/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_cheapest_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maglagal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 18:24:19 by maglagal          #+#    #+#             */
/*   Updated: 2024/01/27 09:45:50 by maglagal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	before_mid(t_linked **stack_a, t_linked **stack_b,
	t_linked *to_find, t_linked *to_find_b)
{
	t_linked	*current_a;
	t_linked	*current_b;
	int			mid_a;
	int			mid_b;
	int			count;

	count = 0;
	mid_a = count_stack_mid(stack_a);
	mid_b = count_stack_mid(stack_b);
	current_a = *stack_a;
	current_b = *stack_b;
	count += moves_to_head(&current_a, &current_b, to_find, to_find_b);
	if (current_a->index != to_find->index)
		count += count_moves(&current_a, to_find, 0, mid_a);
	if (current_b->index != to_find_b->index)
		count += count_moves(&current_b, to_find_b, 0, mid_b);
	return (count);
}

int	after_mid(t_linked **stack_a, t_linked **stack_b,
	t_linked *to_find, t_linked *to_find_b)
{
	t_linked	*current_a;
	t_linked	*current_b;
	int			mid_a;
	int			mid_b;
	int			count;

	count = 0;
	mid_a = count_stack_mid(stack_a);
	mid_b = count_stack_mid(stack_b);
	current_a = *stack_a;
	current_b = *stack_b;
	count += r_moves_to_head(&current_a, &current_b, to_find, to_find_b);
	if (current_a->index == to_find->index
		&& current_b->index == to_find_b->index)
		count++;
	else
	{
		if (current_a->index != to_find->index)
			count += count_moves(&current_a, to_find, 1, mid_a);
		if (current_b->index != to_find_b->index)
			count += count_moves(&current_b, to_find_b, 1, mid_b);
	}
	return (count);
}

int	after_before(t_linked **stack_a, t_linked **stack_b,
	t_linked *to_find, t_linked *to_find_b)
{
	t_linked	*current_a;
	int			mid_a;
	int			mid_b;
	int			count;

	count = 0;
	current_a = *stack_a;
	mid_a = count_stack_mid(stack_a);
	mid_b = count_stack_mid(stack_b);
	if (count_stack(stack_b) % 2 != 0)
		mid_b += 1;
	while (current_a->next)
		current_a = current_a->next;
	count += count_moves(&current_a, to_find, 1, mid_a);
	count += count_moves(stack_b, to_find_b, 0, mid_b);
	return (count);
}

int	before_after(t_linked **stack_a, t_linked **stack_b,
	t_linked *to_find, t_linked *to_find_b)
{
	t_linked	*current_b;
	int			mid_a;
	int			mid_b;
	int			count;

	count = 0;
	current_b = *stack_b;
	mid_a = count_stack_mid(stack_a);
	mid_b = count_stack_mid(stack_b);
	count += count_moves(stack_a, to_find, 0, mid_a);
	while (current_b->next)
		current_b = current_b->next;
	count += count_moves(&current_b, to_find_b, 1, mid_b);
	return (count);
}
