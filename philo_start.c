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

static bool	is_dead(t_philo *p, t_waiter *w, int index)
{
	pthread_mutex_lock(&w->print);
	if (w->t_to_die + 1 <= time_dif(p[index].last_meal))
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
	t_temp	*t;
	t_philo	*p;
	int		i;

	t = tmp;
	p = t->w->p;
	while (1)
	{
		i = -1;
		while (++i < t->w->nb_philos)
		{
			if (is_dead(p, t->w, i))
				return (NULL);
			my_sleep(1);
		}
	}
	return (NULL);
}

static void	*routine(void *tp)
{
	t_philo	*ph;
	t_temp	t;

	t = *(t_temp *)tp;
	ph = &t.w->p[t.index];
	free(tp);
	if (ph->id % 2 == 0)
		my_sleep(t.w->t_to_eat);
	while (t.w->dead && ph->nb_times_eat != t.w->nb_meal)
	{
		pthread_mutex_lock(ph->l_fork);
		pthread_mutex_lock(ph->r_fork);
		philo_eat(ph, t.w);
		pthread_mutex_unlock(ph->l_fork);
		pthread_mutex_unlock(ph->r_fork);
		philo_sleep(ph, t.w);
		philo_think(ph, t.w);
	}
	return (NULL);
}

static void	init_philo(t_waiter *w, pthread_t *t)
{
	t_temp	*temp;
	int		i;

	i = -1;
	while (i++ < w->nb_philos)
	{
		temp = (t_temp *)ft_calloc((sizeof(t_temp)), 1);
		temp->index = i;
		temp->w = w;
		pthread_mutex_init(&w->p_t[i], NULL);
		w->p[i].id = i + 1;
		w->p[i].r_fork = &w->p_t[i];
		if (i != w->nb_philos - 1)
			w->p[i].l_fork = &w->p_t[i + 1];
		else
			w->p[i].l_fork = &w->p_t[0];
		pthread_create(&t[i], NULL, &routine, temp);
	}
	usleep(200);
	temp = (t_temp *)ft_calloc((sizeof(t_temp)), 1);
	temp->index = i;
	temp->w = w;
	pthread_create(&t[i], NULL, &philo_dead, temp);
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
	pthread_mutex_init(&w->print, NULL);
	w->t_start = get_time();
	init_philo(w, thread);
	while (++i < w->nb_philos)
		pthread_join(thread[i], NULL);
	pthread_join(thread[i], NULL);
	pthread_mutex_destroy(&w->print);
	free(thread);
	free(w->p);
	free(w->p_t);
}
