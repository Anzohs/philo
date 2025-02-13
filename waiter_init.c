#include "philo.h"

static void philo_count(t_waiter *w, long nb_philo)
{
    if (nb_philo > INT_MAX)
        return (w->nb_philos = 0, (void)nb_philo);
    w->nb_philos = (int)nb_philo;
}

static void philo_times(t_waiter *w, long t_eat, long t_die, long t_sleep)
{
    
}

bool    waiter_init(t_waiter *waiter, int ac, t_str *av)
{
    philo_count(waiter, ft_atol(av[1]));
    if (!philo_count)
        return (false);
    
}