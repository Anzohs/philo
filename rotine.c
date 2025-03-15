/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotine.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hladeiro <hladeiro@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 19:05:09 by hladeiro          #+#    #+#             */
/*   Updated: 2025/03/15 14:11:39 by hladeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "structs.h"
#include <pthread.h>

void	my_routine(t_philo *ph)
{
	pthread_mutex_lock(ph->l_fork);
	pthread_mutex_lock(ph->r_fork);
	print_term(ph, ph->w, LEFT);
	print_term(ph, ph->w, RIGHT);
	philo_eat(ph, ph->w);
	pthread_mutex_unlock(ph->l_fork);
	pthread_mutex_unlock(ph->r_fork);
	philo_sleep(ph, ph->w);
	philo_think(ph, ph->w);
}

bool	loop(t_philo *tp)
{
	bool	is_dead;
	int		i;

	pthread_mutex_lock(&tp->w->print);
	is_dead = tp->w->dead;
	i = tp->nb_times_eat;
	pthread_mutex_unlock(&tp->w->print);
	return (!is_dead && i != tp->w->nb_meal);
}

void	philo_sleep(t_philo *p, t_waiter *w)
{
	pthread_mutex_lock(&w->print);
	if (w->dead || p->nb_times_eat == w->nb_meal)
	{
		pthread_mutex_unlock(&w->print);
		return ;
	}
	pthread_mutex_unlock(&w->print);
	print_term(p, w, SLEEP);
	my_sleep((int)w->t_to_sleep);
}

void	philo_eat(t_philo *p, t_waiter *w)
{
	pthread_mutex_lock(&w->print);
	if (w->dead || p->nb_times_eat == w->nb_meal)
	{
		pthread_mutex_unlock(&w->print);
		return ;
	}
	pthread_mutex_unlock(&w->print);
	print_term(p, w, EAT);
	pthread_mutex_lock(&w->print);
	p->last_meal = time_dif(w->t_start);
	pthread_mutex_unlock(&w->print);
	my_sleep((int)w->t_to_eat);
	pthread_mutex_lock(&w->print);
	if (p->nb_times_eat < INT_MAX)
	{
		p->nb_times_eat++;
		pthread_mutex_unlock(&w->print);
		return ;
	}
	pthread_mutex_unlock(&w->print);
}

void	philo_think(t_philo *p, t_waiter *w)
{
	pthread_mutex_lock(&w->print);
	if (w->dead || p->nb_times_eat == w->nb_meal)
	{
		pthread_mutex_unlock(&w->print);
		return ;
	}
	pthread_mutex_unlock(&w->print);
	print_term(p, w, THINK);
}
