#include <unistd.h>
#include "header.h"

size_t check_number(char *number)
{
    size_t index;

    index = 0;
    if(*(number + index) == '-' || *(number + index) == '+')
        index++;
    while((*(number + index) && *(number + index) >= '0' && *(number + index) <= '9'))
        index++;
    return (index);
}

int check_doubles(l_linked *head)
{
    l_linked *current = NULL;
    l_linked *prev = NULL;

    current = head;
    while(current)
    {
        if(current->previous)
        {
            prev = current->previous;
            while(prev)
            {
                if(prev->data == current->data)
                    return (1);
                prev = prev->previous;
            }
        }
        current = current->next;
    }
    return (0);
}

int check_max_min(long number)
{
    int i;

    i = 0;
    if(number > 2147483647)    
        return (1);
    else if(number < -2147483648)
        return (1);
    return (0);
}

int	check_m(const char *str, int *ptr_i)
{
	int	i;
	int	m;

	i = 0;
	m = 1;
	while ((str[i] == ' ') || (str[i] >= 9 && str[i] <= 13)) 
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			m = -m;
		i++;
	}
	*ptr_i = i;
	return (m);
}

long ft_atoi(const char *str)
{
	int		i;
	int     m;
	long	res;

	res = 0;
	m = check_m(str, &i);
	while (str[i] && (str[i] >= '0' && str[i] <= '9'))
	{
		res = res * 10 + (str[i] - '0');
		i++;
	}
	return ((res * m));
}
