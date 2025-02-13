#include "philo.h"

long    ft_atol(t_str s)
{
    long    i;

    i = 0;
    while (*s)
    {
        i = i * 10 + (*s - '0');
        s++;
    }
    return (i);
}