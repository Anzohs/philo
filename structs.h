#ifndef STRUCTS_H
# define STRUCTS_H

# include "libs.h"


typedef struct s_philo
{
    long    last_meal;
    int     nb_times_eat;
    int     id;
    pthread_mutex_t *r_fork;
    pthread_mutex_t *l_fork;
}       t_philo;


typedef struct  s_waiter
{
    int     nb_philos;
    int     nb_meal;
    long    t_to_eat;
    long    t_to_sleep;
    long    t_to_die;
    long    t_start;
    pthread_mutex_t print;
    pthread_mutex_t *p_t;
    bool    dead;
    t_philo *p;
}       t_waiter;

typedef struct s_temp
{
    int         index;
    t_waiter    *w;
}           t_temp;

#endif