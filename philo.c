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

int	main(int argc, t_str *argv)
{
	t_waiter	*w;

	if (argc < 5 || argc > 6)
		return (error_argc());
	if (!parse_args(argc, argv))
		return (error_types());
	w = (t_waiter *)ft_calloc(sizeof(t_waiter), 1);
	if (!w)
		return (printf("Memory allocation error \n"));
	
}