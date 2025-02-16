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

void	philo_sleep(t_philo *p, t_waiter *w)
{
	if (w->dead)
		return ;
	print_term(p, w, SLEEP);
	my_sleep((int)w->t_to_sleep);
}

void	philo_eat(t_philo *p, t_waiter *w)
{
	if (w->dead)
		return ;
	print_term(p, w, EAT);
	p->last_meal = time_dif(w->t_start);
	my_sleep((int)w->t_to_eat);
	if (p->nb_times_eat < INT_MAX)
		p->nb_times_eat++;
}

void	philo_think(t_philo *p, t_waiter *w)
{
	if (w->dead)
		return ;
	print_term(p, w, THINK);
}
