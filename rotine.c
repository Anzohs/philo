/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotine.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hladeiro <hladeiro@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 19:05:09 by hladeiro          #+#    #+#             */
/*   Updated: 2025/02/16 18:11:07 by hladeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "structs.h"
#include <pthread.h>
#include <sys/_pthread/_pthread_mutex_t.h>

void	philo_sleep(t_philo *p, t_waiter *w)
{
	pthread_mutex_lock(&w->print);
	if (w->dead)
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
	if (w->dead)
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
	if (w->dead)
	{
		pthread_mutex_unlock(&w->print);
		return ;
	}
	pthread_mutex_unlock(&w->print);
	print_term(p, w, THINK);
}
