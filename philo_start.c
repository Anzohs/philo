
#include "philo.h"

static void    *philo_dead(t_temp *tmp)
{

}

static void    *routine(t_temp *t)
{
    t_philo *ph;

    ph = &t->w[t->index];
    if (ph->id % 2 == 0)
        my_sleep(t->w->t_to_eat);
    while (t->w->dead && ph->nb_times_eat != t->w->nb_meal)
    {
        pthread_mutex_lock(ph->l_fork);
        pthread_mutex_lock(ph->r_fork);
        philo_eat(ph);
        pthread_mutex_unlock(ph->l_fork);
        pthread_mutex_unlock(ph->r_fork);
        philo_sleep(ph);
        philo_think(ph);
    }
    reutnr (NULL);
}

static void init_philo(t_waiter *w, pthread_t *t)
{
    t_temp  temp;

    temp.index = -1;
    while (++temp.index < w->nb_philos)
    {
        pthread_mutex_init(&w->p_t[temp.index], NULL);
        w->p[temp.index].id = temp.index + 1;
        w->p[temp.index].r_fork = &w->p_t[temp.index];
        if (temp.index != w->nb_philos - 1)
            w->p[temp.index].l_fork = &w->p_t[temp.index + 1];
        else
            w->p[temp.index].l_fork = &w->p_t[0];
        pthread_create(&t[temp.index], NULL, &routine, &temp);
    }
    usleep(200);
    pthread_create(&t[temp.index], NULL, &philo_dead, &temp);
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
    init_philo(w, thread);
    while (++i < w->nb_philos)
        pthread_mutex_destroy(&w->p_t[i]);
    pthread_join(thread[i], NULL);
    pthread_mutex_destroy(&w->print);
    free(thread);
    free(w->p);
    free(w->p_t);
}