/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_start.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hladeiro <hladeiro@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 19:04:59 by hladeiro          #+#    #+#             */
/*   Updated: 2025/03/14 20:55:18 by hladeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "structs.h"

static bool	is_dead(t_philo *p, t_waiter *w, long time, int index)
{
	pthread_mutex_lock(&w->print);
	if (w->t_to_die <= time_dif(w->t_start) - time)
	{
		w->dead = true;
		pthread_mutex_unlock(&w->print);
		print_term(p, w, DEAD);
		return (true);
	}
	if (p[index].nb_times_eat == w->nb_meal)
	{
		if (++w->all_eat == w->nb_philos)
		{
			w->dead = true;
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
	long		time;
	int			i;

	w = (t_waiter *)tmp;
	while (1)
	{
		i = -1;
		w->all_eat = 0;
		while (++i < w->nb_philos)
		{
			pthread_mutex_lock(&w->print);
			time = w->p[i].last_meal;
			pthread_mutex_unlock(&w->print);
			if (is_dead(w->p, w, time, i))
				return (NULL);
		}
	}
	return (NULL);
}

static void	*routine(void *tp)
{
	t_philo	*ph;

	ph = (t_philo *)tp;
	if (ph->w->nb_philos == 1)
	{
		pthread_mutex_lock(ph->l_fork);
		print_term(ph, ph->w, LEFT);
		my_sleep((int)ph->w->t_to_die);
		pthread_mutex_unlock(ph->l_fork);
		return (NULL);
	}
	if (ph->id % 2 == 0)
		my_sleep(ph->w->t_to_sleep);
	while (loop(ph))
		my_routine(ph);
	return (NULL);
}

static void	init_philo(t_waiter *w, pthread_t *t)
{
	long	i;

	i = -1;
	while (++i < w->nb_philos)
	{
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

	w->p = (t_philo *)ft_calloc(sizeof(t_philo), (w->nb_philos));
	if (!w->p)
		return (printf("Memory allocation failed"), (void)0);
	thread = (pthread_t *)ft_calloc(sizeof(pthread_t), w->nb_philos + 1);
	if (!thread)
		return (printf("Memory allocation failed"), free(w->p));
	w->p_t = (pthread_mutex_t *)ft_calloc(sizeof(pthread_mutex_t), w->nb_philos
			+ 1);
	if (!w->p_t)
		return (printf("Memory allocation failed"), free(w->p), free(thread));
	w->dead = false;
	pthread_mutex_init(&w->print, NULL);
	w->t_start = get_time();
	fork_mutex_init(w);
	init_philo(w, thread);
	free_thread_mutex(w, thread);
	return (free(thread), free(w->p), free(w->p_t));
}
