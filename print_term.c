/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_term.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hladeiro <hladeiro@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 16:49:33 by hladeiro          #+#    #+#             */
/*   Updated: 2025/03/11 20:46:24 by hladeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <pthread.h>

int	print_term(t_philo *p, t_waiter *w, t_action act)
{
	pthread_mutex_lock(&w->print);
	if (act == DEAD)
	{
		printf("%d %d died\n", time_dif(w->t_start), p->id);
		pthread_mutex_unlock(&w->print);
		return (1);
	}
	if (w->dead)
	{
		pthread_mutex_unlock(&w->print);
		return (1);
	}
	if (act == EAT)
		(printf("%d %d is eating\n", time_dif(w->t_start), p->id));
	else if (act == SLEEP)
		printf("%d %d is sleeping\n", time_dif(w->t_start), p->id);
	else if (act == THINK)
		printf("%d %d is thinking\n", time_dif(w->t_start), p->id);
	else if (act == LEFT)
		(printf("%d %d has taken the fork\n", \
				time_dif(w->t_start), p->id));
	else if (act == RIGHT)
		(printf("%d %d has taken the fork\n", \
			time_dif(w->t_start), p->id));
	pthread_mutex_unlock(&w->print);
	return (0);
}
