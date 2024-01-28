/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_four_numbers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maglagal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 13:21:07 by maglagal          #+#    #+#             */
/*   Updated: 2024/01/27 19:58:32 by maglagal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	four_numbers_sort(t_linked **stack_a, t_linked **stack_b)
{
	t_linked	*lowest_node;

	lowest_node = find_lowest(stack_a);
	while (*stack_a && (*stack_a)->data != lowest_node->data)
		ra(stack_a);
	pb(stack_a, stack_b);
	three_numbers_sort(stack_a);
	pa(stack_a, stack_b);
}
