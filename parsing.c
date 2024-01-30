/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maglagal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 10:30:35 by maglagal          #+#    #+#             */
/*   Updated: 2024/01/29 16:18:02 by maglagal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	count_strings(char **numbers)
{
	int	nbr_num;

	nbr_num = 0;
	while (numbers[nbr_num])
		nbr_num++;
	return (nbr_num);
}

void	free_2d_table(char **numbers)
{
	int	index;

	index = 0;
	while (numbers[index] && index < count_strings(numbers))
	{
		free(numbers[index]);
		index++;
	}
	free(numbers);
}

int	create_nodes_from_arguments(t_linked **stack_a, char **numbers)
{
	int	index;
	int	check;

	index = 0;
	check = 0;
	if (count_strings(numbers) == 0)
		check = 1;
	while (index < count_strings(numbers))
	{
		if ((check_number(numbers[index]) != ft_strlen(numbers[index]))
			|| (check_max_min(ft_atoi(numbers[index])) == 1) || !numbers[index])
		{
			check = 1;
			break ;
		}
		create_node(stack_a, ft_atoi(numbers[index]));
		index++;
	}
	free_2d_table(numbers);
	return (check);
}

int	check_arguments(int ac, char **av, t_linked **stack_a)
{
	int			number;
	int			index;
	int			check;
	char		**numbers;

	index = 1;
	check = 0;
	number = 0;
	while (index < ac)
	{
		numbers = ft_split(av[index], ' ');
		if (!numbers)
		{
			free_stack(stack_a);
			exit(0);
		}
		check = create_nodes_from_arguments(stack_a, numbers);
		if (check)
			break ;
		index++;
	}
	if (check || check_doubles(*stack_a) || check_before_sort(stack_a))
		return (0);
	else
		return (1);
}
