/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hladeiro <hladeiro@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 19:04:00 by hladeiro          #+#    #+#             */
/*   Updated: 2025/02/16 17:32:54 by hladeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# include "libs.h"

typedef struct s_waiter	t_waiter;

typedef struct s_philo
{
	long				last_meal;
	int					nb_times_eat;
	int					id;
	pthread_mutex_t		*r_fork;
	pthread_mutex_t		*l_fork;
	t_waiter			*w;
}						t_philo;

typedef struct s_waiter
{
	int					nb_philos;
	int					nb_meal;
	int					all_eat;
	long				t_to_eat;
	long				t_to_sleep;
	long				t_to_die;
	long				t_start;
	pthread_mutex_t		print;
	pthread_mutex_t		*p_t;
	bool				dead;
	t_philo				*p;
}						t_waiter;

typedef enum s_ation
{
	EAT,
	SLEEP,
	THINK,
	LEFT,
	RIGHT,
	ALL_EAT,
	DEAD
}						t_action;

#endif
