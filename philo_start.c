/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_start.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hladeiro <hladeiro@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 19:04:59 by hladeiro          #+#    #+#             */
/*   Updated: 2025/02/13 19:05:02 by hladeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "structs.h"

static bool	is_dead(t_philo *p, t_waiter *w, int index)
{
	pthread_mutex_lock(&w->print);
	if (w->t_to_die + 1 <= time_dif(w->t_start - p[index].last_meal))
	{
		w->dead = true;
		printf("dead %i\n", p[index].id);
		pthread_mutex_unlock(&w->print);
		return (true);
	}
	if (p[index].nb_times_eat == w->nb_meal)
	{
		if (++w->all_eat == w->nb_philos)
		{
			printf("All ate\n");
			pthread_mutex_unlock(&w->print);
			return (true);
		}
	}
	pthread_mutex_unlock(&w->print);
	return (false);
}

static void	*philo_dead(void *tmp)
{
	t_waiter	*w;
	int			i;

	w = (t_waiter *)tmp;
	while (1)
	{
		i = -1;
		w->all_eat = 0;
		while (++i < w->nb_philos)
		{
			if (is_dead(w->p, w, i))
				return (NULL);
			my_sleep(1);
		}
	}
	return (NULL);
}

static void	*routine(void *tp)
{
	t_philo	*ph;

	ph = (t_philo *) tp;
	if (ph->id % 2 == 0)
		my_sleep(ph->w->t_to_eat);
	while (!ph->w->dead && ph->nb_times_eat != ph->w->nb_meal)
	{
		pthread_mutex_lock(ph->l_fork);
		pthread_mutex_lock(ph->r_fork);
		philo_eat(ph, ph->w);
		pthread_mutex_unlock(ph->l_fork);
		pthread_mutex_unlock(ph->r_fork);
		philo_sleep(ph, ph->w);
		philo_think(ph, ph->w);
	}
	return (NULL);
}

static void	init_philo(t_waiter *w, pthread_t *t)
{
	int		i;

	i = -1;
	while (i++ < w->nb_philos)
	{
		pthread_mutex_init(&w->p_t[i], NULL);
		w->p[i].id = i + 1;
		w->p[i].last_meal = 0;
		w->p[i].r_fork = &w->p_t[i];
		w->p[i].w = w;
		if (i != w->nb_philos - 1)
			w->p[i].l_fork = &w->p_t[i + 1];
		else
			w->p[i].l_fork = &w->p_t[0];
		pthread_create(&t[i], NULL, &routine, (void *)(&w->p[i]));
	}
	usleep(200);
	pthread_create(&t[i], NULL, &philo_dead, (void *)(w));
}

void	philo_start(t_waiter *w)
{
	pthread_t	*thread;
	int			i;

	i = -1;
	w->p = (t_philo *)ft_calloc(sizeof(t_philo), (w->nb_philos));
	thread = (pthread_t *)ft_calloc(sizeof(pthread_t), w->nb_philos + 1);
	w->p_t = (pthread_mutex_t *)ft_calloc(sizeof(pthread_mutex_t), w->nb_philos
			+ 1);
	w->dead = false;
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
