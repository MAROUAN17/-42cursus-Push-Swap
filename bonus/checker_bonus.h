/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maglagal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 15:20:42 by maglagal          #+#    #+#             */
/*   Updated: 2024/01/27 18:54:28 by maglagal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

typedef struct t_linked
{
	int				data;
	int				index;
	struct t_linked	*next;
	struct t_linked	*previous;
}	t_linked;

void	get_last_node(t_linked **last_node);
void	receive_instruction(t_linked **stack_a, t_linked **stack_b, int len);
void	free_stack(t_linked **head);
void	check_arguments(int ac, char **av,
			t_linked **stack_a, t_linked **stack_b);
void	create_node(t_linked **head, int data);
char	*get_next_line(int fd);
char	*ft_strdup(const char *s1);
size_t	ft_strlen(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strchr(const char *s, int c);
void	terminating_string(char *buffer);
int		ft_printf(const char *format, ...);
char	**ft_split(char const *s, char c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
size_t	check_number(char *number);
int		check_doubles(t_linked *head);
int		check_max_min(long number);
int		check_m(const char *str, int *ptr_i);
long	ft_atoi(const char *str);
void	make_instruction(t_linked **stack_a,
			t_linked **stack_b, char *instruction);
void	check_sort(t_linked **stack_a, int stack_len);
void	sa(t_linked **stack_a);
void	sb(t_linked **stack_b);
void	ss(t_linked **stack_a, t_linked **stack_b);
void	pa(t_linked **stack_a, t_linked **stack_b);
void	pb(t_linked **stack_a, t_linked **stack_b);
void	ra(t_linked **stack_a);
void	rb(t_linked **stack_b);
void	rr(t_linked **stack_a, t_linked **stack_b);
void	rra(t_linked **stack_a);
void	rrb(t_linked **stack_b);
void	rrr(t_linked **stack_a, t_linked **stack_b);

#endif
