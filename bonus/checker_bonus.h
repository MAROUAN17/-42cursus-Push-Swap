#ifndef CHECKER_BONUS
#define CHECKER_BONUS

#include <unistd.h>
#include <stdlib.h>
#include <limits.h>

typedef struct t_linked {
    int             data;
    int             index;
    struct t_linked *next;
    struct t_linked *previous;
} l_linked;

void    receive_instruction(l_linked **stack_a, l_linked **stack_b, int len);
void    free_stack(l_linked **head);
void    check_one_argument(char **av, l_linked **stack_a, l_linked **stack_b);
void    check_multiple_arguments(int ac, char **av, l_linked **stack_a, l_linked **stack_b);
void    createNode(l_linked **head, int data);
char	*get_next_line(int fd);
char	*ft_strdup(const char *s1);
size_t	ft_strlen(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strchr(const char *s, int c);
void	terminating_string(char *buffer);
int     ft_printf(const char *format, ...);
char	**ft_split(char const *s, char c);
int     ft_strncmp(const char *s1, const char *s2, size_t n);
size_t  check_number(char *number);
int     check_doubles(l_linked *head);
int     check_max_min(long number);
int     check_m(const char *str, int *ptr_i);
long    ft_atoi(const char *str);
void    make_instruction(l_linked **stack_a, l_linked **stack_b, char *instruction);
void    check_sort(l_linked **stack_a, int stack_len);
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

#endif