#ifndef HEADER_H
#define HEADER_H

#include <unistd.h>
#include <stdlib.h>

typedef struct t_linked {
    int             data;
    struct t_linked *next;
    struct t_linked *previous;
} l_linked;

void    display(l_linked **stack);
void    check_multiple_arguments(int ac, char **av, l_linked **stack_a, l_linked **stack_b);
void    check_one_argument(char **av, l_linked **stack_a, l_linked **stack_b);
void    createNode(l_linked **head, int data);
int     ft_printf(const char *format, ...);
size_t	ft_strlen(const char *s);
char	**ft_split(char const *s, char c);
size_t  check_number(char *number);
int     check_doubles(l_linked *head);
int     check_max_min(long number);
long    ft_atoi(const char *str);
void    sa(l_linked **stack_a);
void    sb(l_linked **stack_b);
void    ss(l_linked **stack_a, l_linked **stack_b);
void    pa(l_linked **stack_a, l_linked **stack_b);
void    pb(l_linked **stack_a, l_linked **stack_b);
void    ra(l_linked **stack_a);
void    rb(l_linked **stack_b);
void    rr(l_linked **stack_a, l_linked **stack_b);
void    rra(l_linked **stack_a);
void    rrb(l_linked **stack_b);
void    rrr(l_linked **stack_a, l_linked **stack_b);
void    sort(l_linked **stack_a, l_linked **stack_b);
int     count_numbers(l_linked **stack);

#endif