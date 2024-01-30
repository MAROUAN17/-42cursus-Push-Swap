/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maglagal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 15:12:07 by maglagal          #+#    #+#             */
/*   Updated: 2024/01/29 16:17:43 by maglagal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

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

int	create_nodes_from_arguments(t_linked **stack_a, char **numbers,
		int *ptr_len)
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
			|| (check_max_min(ft_atoi(numbers[index])) == 1)
			|| !numbers[index])
		{
			check = 1;
			break ;
		}
		create_node(stack_a, ft_atoi(numbers[index]));
		index++;
	}
	*ptr_len += count_strings(numbers);
	free_2d_table(numbers);
	return (check);
}

void	check_arguments(int ac, char **av,
		t_linked **stack_a, t_linked **stack_b)
{
	int		check;
	int		index;
	int		len;
	char	**numbers;

	check = 0;
	index = 1;
	len = 0;
	while (index < ac)
	{
		numbers = ft_split(av[index], ' ');
		if (!numbers)
		{
			free_stack(stack_a);
			exit(1);
		}
		check = create_nodes_from_arguments(stack_a, numbers, &len);
		if (check)
			break ;
		index++;
	}
	if (check || check_doubles(*stack_a))
		write(2, "Error\n", 6);
	else
		receive_instruction(stack_a, stack_b, len);
}
