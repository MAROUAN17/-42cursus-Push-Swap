/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sort_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maglagal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 15:00:18 by maglagal          #+#    #+#             */
/*   Updated: 2024/01/29 16:17:01 by maglagal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

int	count_stack(t_linked **stack)
{
	int			count;
	t_linked	*current;

	count = 0;
	current = *stack;
	while (current)
	{
		count++;
		current = current->next;
	}
	return (count);
}

void	error_instruction(t_linked **stack_a, t_linked **stack_b)
{
	write(2, "Error\n", 6);
	free_stack(stack_a);
	free_stack(stack_b);
	exit(1);
}

void	make_instruction(t_linked **stack_a,
		t_linked **stack_b, char *instruction)
{
	if (ft_strncmp(instruction, "sa\n", 3) == 0)
		sa(stack_a);
	else if (ft_strncmp(instruction, "sb\n", 3) == 0)
		sb(stack_b);
	else if (ft_strncmp(instruction, "ss\n", 3) == 0)
		ss(stack_a, stack_b);
	else if (ft_strncmp(instruction, "pa\n", 3) == 0)
		pa(stack_a, stack_b);
	else if (ft_strncmp(instruction, "pb\n", 3) == 0)
		pb(stack_a, stack_b);
	else if (ft_strncmp(instruction, "ra\n", 3) == 0)
		ra(stack_a);
	else if (ft_strncmp(instruction, "rb\n", 3) == 0)
		rb(stack_b);
	else if (ft_strncmp(instruction, "rr\n", 3) == 0)
		rr(stack_a, stack_b);
	else if (ft_strncmp(instruction, "rra\n", 4) == 0)
		rra(stack_a);
	else if (ft_strncmp(instruction, "rrb\n", 4) == 0)
		rrb(stack_b);
	else if (ft_strncmp(instruction, "rrr\n", 4) == 0)
		rrr(stack_a, stack_b);
	else
		error_instruction(stack_a, stack_b);
}

void	check_sort(t_linked **stack_a, int stack_len)
{
	t_linked	*current;

	current = *stack_a;
	while (current->next)
	{
		if (current->data > current->next->data)
		{
			ft_printf("KO\n");
			exit(0);
		}
		current = current->next;
	}
	if (current)
	{
		if (count_stack(stack_a) != stack_len)
			ft_printf("KO\n");
		else
			ft_printf("OK\n");
	}
}
