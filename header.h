/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maglagal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 19:22:45 by maglagal          #+#    #+#             */
/*   Updated: 2024/01/29 16:32:41 by maglagal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <unistd.h>
# include <stdlib.h>

typedef struct l_linked
{
	int				data;
	int				index;
	struct l_linked	*next;
	struct l_linked	*previous;
}	t_linked;

void		get_last_node(t_linked **head);
int			moves_to_head(t_linked **stack_a, t_linked **stack_b,
				t_linked *to_find, t_linked *to_find_b);
int			r_moves_to_head(t_linked **current_a, t_linked **current_b,
				t_linked *to_find, t_linked *to_find_b);
t_linked	*check_before_sort(t_linked **stack_a);
void		free_stack(t_linked **head);
void		bring_to_top_a(t_linked **stack_a, t_linked *cheapest_node,
				int reverse);
void		bring_to_top_b(t_linked **stack_b, t_linked *to_find_b,
				int reverse);
int			before_mid(t_linked **stack_a, t_linked **stack_b,
				t_linked *to_find, t_linked *to_find_b);
int			after_mid(t_linked **stack_a, t_linked **stack_b,
				t_linked *to_find, t_linked *to_find_b);
int			after_before(t_linked **stack_a, t_linked **stack_b,
				t_linked *to_find, t_linked *to_find_b);
int			before_after(t_linked **stack_a, t_linked **stack_b,
				t_linked *to_find, t_linked *to_find_b);
void		cheapest_after_mid(t_linked **stack_a, t_linked **stack_b,
				t_linked *cheapest_node, t_linked *to_find_b);
int			count_stack_mid(t_linked **stack);
t_linked	*correct_position(t_linked **stack,
				t_linked *node, int len, int reverse);
t_linked	*find_lowest(t_linked **stack);
t_linked	*find_greatest(t_linked **stack);
int			find_position(t_linked **stack, t_linked *to_find);
t_linked	*correct_position(t_linked **stack,
				t_linked *node, int len, int back);
int			count_moves(t_linked **stack,
				t_linked *to_find, int reverse, int mid);
int			count_stack(t_linked **stack);
int			check_arguments(int ac, char **av,
				t_linked **stack_a);
void		create_node(t_linked **head, int data);
int			ft_printf(const char *format, ...);
size_t		ft_strlen(const char *s);
char		**ft_split(char const *s, char c);
size_t		check_number(char *number);
int			check_doubles(t_linked *head);
int			check_max_min(long number);
long		ft_atoi(const char *str);
int			count_cheapest(t_linked **stack_a,
				t_linked **stack_b, t_linked *to_find);
void		sort(t_linked **stack_a, t_linked **stack_b);
void		sa(t_linked **stack_a);
void		sb(t_linked **stack_b);
void		ss(t_linked **stack_a, t_linked **stack_b);
void		pa(t_linked **stack_a, t_linked **stack_b);
void		pb(t_linked **stack_a, t_linked **stack_b);
void		ra(t_linked **stack_a);
void		rb(t_linked **stack_b);
void		rr(t_linked **stack_a, t_linked **stack_b);
void		rra(t_linked **stack_a);
void		rrb(t_linked **stack_b);
void		rrr(t_linked **stack_a, t_linked **stack_b);
void		two_numbers_sort(t_linked **stack_a);
void		three_numbers_sort(t_linked **stack_a);
void		four_numbers_sort(t_linked **stack_a, t_linked **stack_b);
void		rest_of_numbers_sort(t_linked **stack_a, t_linked **stack_b);

#endif