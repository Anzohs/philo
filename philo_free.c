/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hladeiro <hladeiro@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 20:47:04 by hladeiro          #+#    #+#             */
/*   Updated: 2025/03/14 20:47:05 by hladeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "structs.h"
#include <sys/_pthread/_pthread_t.h>

void	free_thread_mutex(t_waiter *w, pthread_t *thread)
{
	int	i;

	i = -1;
	while (++i < w->nb_philos)
	{
		pthread_join(thread[i], NULL);
		pthread_mutex_lock(&w->p_t[i]);
		pthread_mutex_unlock(&w->p_t[i]);
		pthread_mutex_destroy(&w->p_t[i]);
	}
	pthread_join(thread[i], NULL);
	pthread_mutex_destroy(&w->print);
}

void	fork_mutex_init(t_waiter *w)
{
	long	i;

	i = -1;
	while (++i < w->nb_philos)
		pthread_mutex_init(&w->p_t[i], NULL);
}
