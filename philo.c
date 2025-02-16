/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hladeiro <hladeiro@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 19:04:52 by hladeiro          #+#    #+#             */
/*   Updated: 2025/02/16 18:24:28 by hladeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	error_argc(void)
{
	printf("%s", ERROR_ARGS);
	printf("%s", ERROR_USAGE);
	printf("%s", ERROR_USAGE1);
	printf("%s", ERROR_USAGE2);
	return (0);
}

static int	error_types(void)
{
	printf("%s", "It should be positive int as a arguments!\n");
	printf("%s", "Example: \n");
	printf("%s", EXAMPLE);
	return (0);
}

int	main(int argc, char *argv[])
{
	t_waiter	*w;

	if (argc < 5 || argc > 6)
		return (error_argc());
	if (!parse_args(argc, argv))
		return (error_types());
	w = (t_waiter *)ft_calloc(sizeof(t_waiter), 1);
	if (!w)
		return (printf("Memory allocation error \n"));
	if (!waiter_init(w, argc, argv))
		return (free(w), 1);
	w->t_start = get_time();
	philo_start(w);
	return (free(w), 1);
}

// https://github.com/wtandoor/philo42/blob
