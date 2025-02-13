
#include "philo.h"

void    routine(t_philo *p)
{
    free(p);
}

static void init_philo(t_waiter *w, pthread_t *t)
{
    int i;

    i = -1;
    while (++i < w->nb_philos)
    {
        pthread_mutex_init(&w->p_t[i], NULL);
        w->p[i].id = i + 1;
        w->p[i].r_fork = &w->p_t[i];
        if (i != w->nb_philos - 1)
            w->p[i].l_fork = &w->p_t[i + 1];
        else
            w->p[i].l_fork = &w->p_t[0];
        pthread_create(&t[i], NULL, &routine, &w->p[i]);
    }
    usleep(200);
    pthread_create(&t[i], NULL, &routine, (void *)(w->p));
}

void    philo_start(t_waiter *w)
{
    pthread_t   *thread;
    int          i;

    i = -1;
    w->p = (t_philo *)ft_calloc(sizeof(t_philo), (w->nb_philos));
    thread = (pthread_t *)ft_calloc(sizeof(pthread_t), w->nb_philos + 1);
    w->p_t = (pthread_mutex_t *)ft_calloc(sizeof(pthread_mutex_t), w->nb_philos + 1);
    pthread_mutex_init(&w->print, NULL);
    w->t_start = get_time();
}