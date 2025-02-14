/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   waiter_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hladeiro <hladeiro@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 19:06:36 by hladeiro          #+#    #+#             */
/*   Updated: 2025/02/13 19:06:37 by hladeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	philo_count(t_waiter *w, long nb_philo)
{
	if (nb_philo > INT_MAX)
		return (w->nb_philos = 0, (void)nb_philo);
	w->nb_philos = (int)nb_philo;
}

static void	philo_times(t_waiter *w, long t_die, long t_eat, long t_sleep)
{
	w->t_to_eat = t_eat;
	w->t_to_die = t_die;
	w->t_to_sleep = t_sleep;
}

bool	waiter_init(t_waiter *waiter, int ac, char **av)
{
	philo_count(waiter, ft_atol(av[1]));
	if (!waiter->nb_philos)
		return (false);
	philo_times(waiter, ft_atol(av[2]), ft_atol(av[3]), ft_atol(av[4]));
	if (waiter->t_to_die > INT_MAX || waiter->t_to_eat > INT_MAX
		|| waiter->t_to_sleep > INT_MAX)
		return (printf("Times must be max INT values\n"), false);
	if (waiter->t_to_die < 60 || waiter->t_to_eat < 60
		|| waiter->t_to_sleep < 60)
		return (printf("The times of the program must be min 60\n"), false);
	if (ac == 6)
	{
		waiter->nb_meal = ft_atol(av[5]);
		if (waiter->nb_meal > INT_MAX)
			return (printf("Use int a small number of times to eat \n"), false);
		if (!waiter->nb_meal)
			return (printf("Use an number bigger than 0"), false);
		return (true);
	}
	return (waiter->nb_meal = -1, true);
}
