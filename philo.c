/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hladeiro <hladeiro@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 19:04:52 by hladeiro          #+#    #+#             */
/*   Updated: 2025/02/13 19:04:53 by hladeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	error_argc(void)
{
	printf("%s", ERROR_ARGS);
	printf("%s", ERROR_USAGE);
	printf("%s", ERROR_USAGE1);
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
	philo_start(w);
	return (free(w), 1);
}

// https://github.com/wtandoor/philo42/blob
