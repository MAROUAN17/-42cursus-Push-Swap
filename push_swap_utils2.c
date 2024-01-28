/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maglagal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 10:38:56 by maglagal          #+#    #+#             */
/*   Updated: 2024/01/27 16:32:29 by maglagal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

t_linked	*find_in_stack_a(t_linked **stack, t_linked *node, int len)
{
	t_linked	*curr;
	int			i;

	curr = NULL;
	i = 1;
	while (!curr && i <= len)
	{
		curr = *stack;
		while (curr && curr->index != node->index + i)
			curr = curr->next;
		if (!curr)
			i++;
	}
	if (!curr)
		curr = find_lowest(stack);
	return (curr);
}

t_linked	*find_in_stack_b(t_linked **stack, t_linked *node)
{
	t_linked	*curr;
	int			i;

	curr = NULL;
	i = 1;
	while (!curr)
	{
		curr = *stack;
		while (curr && curr->index != node->index - i)
			curr = curr->next;
		if (!curr)
			i++;
	}
	return (curr);
}

t_linked	*correct_position(t_linked **stack, t_linked *node,
			int len, int back)
{
	t_linked	*curr;

	curr = NULL;
	if (back == 0)
		curr = find_in_stack_b(stack, node);
	else if (back == 1)
		curr = find_in_stack_a(stack, node, len);
	return (curr);
}

int	count_stack_mid(t_linked **stack)
{
	int	mid;

	mid = count_stack(stack) / 2;
	if (count_stack(stack) % 2 != 0)
		mid += 1;
	else if (count_stack(stack) == 2)
		mid = 2;
	return (mid);
}

t_linked	*check_before_sort(t_linked **stack_a)
{
	t_linked	*curr;

	curr = *stack_a;
	while (curr->next)
	{
		if (curr->data < curr->next->data)
			curr = curr->next;
		else
		{
			curr = NULL;
			break ;
		}
	}
	return (curr);
}
