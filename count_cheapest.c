/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_cheapest.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maglagal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 19:19:29 by maglagal          #+#    #+#             */
/*   Updated: 2024/01/26 19:38:13 by maglagal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	moves_to_head(t_linked **current_a, t_linked **current_b,
	t_linked *to_find, t_linked *to_find_b)
{
	int	count;

	count = 0;
	while (*current_a && current_b && (*current_a)->index != to_find->index
		&& (*current_b)->index != to_find_b->index)
	{
		count++;
		*current_a = (*current_a)->next;
		*current_b = (*current_b)->next;
	}
	return (count);
}

int	r_moves_to_head(t_linked **current_a, t_linked **current_b,
	t_linked *to_find, t_linked *to_find_b)
{
	int	count;

	count = 0;
	while ((*current_a)->next)
		*current_a = (*current_a)->next;
	while ((*current_b)->next)
		*current_b = (*current_b)->next;
	while (*current_a && *current_b
		&& (*current_a)->previous && (*current_b)->previous
		&& (*current_a)->index != to_find->index
		&& (*current_b)->index != to_find_b->index)
	{
		count++;
		*current_a = (*current_a)->previous;
		*current_b = (*current_b)->previous;
	}
	return (count);
}

int	push_to_b(t_linked **stack_a, t_linked **stack_b,
	t_linked *to_find, t_linked *current_bl)
{
	int			position_a;
	int			position_b;
	int			mid_a;
	int			mid_b;
	int			count;

	count = 0;
	mid_a = count_stack_mid(stack_a);
	mid_b = count_stack_mid(stack_b);
	position_a = find_position(stack_a, to_find);
	position_b = find_position(stack_b, current_bl);
	if (position_a <= mid_a && position_b <= mid_b)
		count += before_mid(stack_a, stack_b, to_find, current_bl);
	else if (position_a > mid_a && position_b > mid_b)
		count += after_mid(stack_a, stack_b, to_find, current_bl);
	if (position_a <= mid_a && position_b > mid_b)
		count += before_after(stack_a, stack_b, to_find, current_bl);
	else if (position_a > mid_a && position_b <= mid_b)
		count += after_before(stack_a, stack_b, to_find, current_bl);
	return (count);
}

int	new_smallest_greatest(t_linked **stack_a,
	t_linked **stack_b, t_linked *to_find)
{
	int	position_a;
	int	position_b;
	int	mid_a;
	int	mid_b;
	int	count;

	count = 0;
	mid_a = count_stack_mid(stack_a);
	mid_b = count_stack_mid(stack_b);
	position_a = find_position(stack_a, to_find);
	position_b = find_position(stack_b, find_greatest(stack_b));
	if (position_a <= mid_a && position_b <= mid_b)
		count += before_mid(stack_a, stack_b, to_find, find_greatest(stack_b));
	else if (position_a > mid_a && position_b > mid_b)
		count += after_mid(stack_a, stack_b, to_find, find_greatest(stack_b));
	if (position_a <= mid_a && position_b > mid_b)
		count += before_after(stack_a, stack_b,
				to_find, find_greatest(stack_b));
	else if (position_a > mid_a && position_b <= mid_b)
		count += after_before(stack_a, stack_b,
				to_find, find_greatest(stack_b));
	return (count);
}

int	count_cheapest(t_linked **stack_a, t_linked **stack_b, t_linked *to_find)
{
	t_linked	*current_bl;
	int			count;
	int			len_b;

	count = 0;
	len_b = count_stack(stack_b);
	if (to_find->index > find_greatest(stack_b)->index
		|| to_find->index < find_lowest(stack_b)->index)
		count += new_smallest_greatest(stack_a, stack_b, to_find);
	else
	{
		current_bl = correct_position(stack_b, to_find, len_b, 0);
		count += push_to_b(stack_a, stack_b, to_find, current_bl);
	}
	return (count + 1);
}
