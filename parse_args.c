#include "philo.h"

static size_t len(t_str s)
{
	size_t	i;

	if(!s || !(*s))
		return (12);
	i = 0;
	while(s[i])
		i++;
	return (i);
}

static bool	is_digit(t_str s)
{
	size_t	i;

	i = -1;
	while (s[++i])
		if (!(s[i] >= '0' && s[i] <= '9'))
			return (false);
	return (true);
}

bool	parse_args(int argc, t_str *argv)
{
	int	i;

	i = 0;
	while(++i < argc)
		if (len(argv[i]) > 11 || !is_digit(argv[i]))
			return (false);
	return (true);
}