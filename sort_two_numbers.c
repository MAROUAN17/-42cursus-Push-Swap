/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_two_numbers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maglagal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 13:23:25 by maglagal          #+#    #+#             */
/*   Updated: 2024/01/27 20:43:07 by maglagal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	two_numbers_sort(t_linked **stack_a)
{
	if (*stack_a && (*stack_a)->next
		&& (*stack_a)->data > (*stack_a)->next->data)
		sa(stack_a);
}
