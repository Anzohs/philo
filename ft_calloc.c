/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hladeiro <hladeiro@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 19:04:13 by hladeiro          #+#    #+#             */
/*   Updated: 2025/02/13 19:04:41 by hladeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	*ft_call(size_t c)
{
	char	*ptr;
	size_t	i;

	ptr = malloc(c);
	if (!ptr)
		return (NULL);
	i = 0;
	while (i < c)
		ptr[i++] = 0;
	return (ptr);
}

void	*ft_calloc(size_t count, size_t size)
{
	size_t	ct;

	ct = count * size;
	if (count > size && size != 0 && size != 1)
	{
		if (count > ct)
			return (NULL);
	}
	else if (count < size && count != 0 && count != 1)
	{
		if (size > ct)
			return (NULL);
	}
	else if (count == size && size != 0)
	{
		if (ct < count)
			return (NULL);
	}
	return (ft_call(ct));
}
