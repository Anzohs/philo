/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotine.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hladeiro <hladeiro@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 19:05:09 by hladeiro          #+#    #+#             */
/*   Updated: 2025/02/13 19:05:11 by hladeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_sleep(t_philo *p, t_waiter *w)
{
	if (w->dead)
		return ;
	printf("sleep %i\n", p->id);
	my_sleep(w->t_to_sleep);
}

void	philo_eat(t_philo *p, t_waiter *w)
{
	if (w->dead)
		return ;
	printf("philo_eat %i\n", p->id);
	p->last_meal = time_dif(w->t_start);
	my_sleep(w->t_to_eat);
	if (p->nb_times_eat < INT_MAX)
		p->nb_times_eat++;
}

void	philo_think(t_philo *p, t_waiter *w)
{
	if (w->dead)
		return ;
	printf("philo_sleep %i\n", p->id);
}
