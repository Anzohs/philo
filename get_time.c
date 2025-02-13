#include "philo.h"

long    get_time(void)
{
    struct timeval  start;

    gettimeofday(&start, NULL);
    return (start.tv_sec * 1000 + start.tv_usec / 1000);
}

int time_dif(long current)
{
    return ((int)(get_time() - current));
}

void    my_sleep(int start)
{
    long    current;

    current = get_time();
    while (get_time() - current  < start)
        usleep(50);
}