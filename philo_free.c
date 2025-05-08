/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hladeiro <hladeiro@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 20:47:04 by hladeiro          #+#    #+#             */
/*   Updated: 2025/03/19 20:46:14 by hladeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "structs.h"
#include <pthread.h>
#include <string.h>

void	free_thread_mutex(t_waiter *w, pthread_t *thread)
{
	int	i;

	i = -1;
	while (++i < w->nb_philos)
		pthread_join(thread[i], NULL);
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
