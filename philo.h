/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hladeiro <hladeiro@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 19:03:46 by hladeiro          #+#    #+#             */
/*   Updated: 2025/02/13 19:03:51 by hladeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include "structs.h"

// error messages
# define ERROR_ARGS "Wrong number of arguments\n"
# define ERROR_MEM "Memory alocation failed\n"
# define ERROR_USAGE "It shold be use in the following order: \n"
# define ERROR_USAGE1 "<num_of_philos> <time_to_die> <time_to_eat> <time_to_sleep> [optional <num_of_times_to_eat>]\n"
# define EXAMPLE "20 200 100 100\n"
# define EAT "EATING"
# define SLEEP "SLEEPING"
# define THINK "THINKING"
// funtions of the program

// parsing function of the arguments
bool	parse_args(int argc, t_str *argv);

// memory alocation, creating my own calloc.
void	*ft_calloc(size_t count, size_t size);

// char * into long
long	ft_atol(t_str s);

// time management
void	my_sleep(int start);
int		time_dif(long current);
long	get_time(void);
// initialize the main struct
bool	waiter_init(t_waiter *waiter, int ac, t_str *av);
// rotine
void	philo_eat(t_philo *p, t_waiter *w);
void	philo_sleep(t_philo *p, t_waiter *w);
void	philo_think(t_philo *p, t_waiter *w);

#endif
