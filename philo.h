#ifndef PHILO_H
# define PHILO_H

# include "structs.h"

//error messages
# define ERROR_ARGS		"Wrong number of arguments\n"
# define ERROR_MEM		"Memory alocation failed\n"
# define ERROR_USAGE	"It shold be use in the following order: \n"
# define ERROR_USAGE1	"<num_of_philos> <time_to_die> <time_to_eat> <time_to_sleep> [optional <num_of_times_to_eat>]\n"
# define EXAMPLE		"20 200 100 100\n"


//funtions of the program

//parsing function of the arguments
bool	parse_args(int argc, t_str *argv);

//memory alocation, creating my own calloc. 
void	*ft_calloc(size_t count, size_t size);
#endif