NAME = philo CC = cc FLAGS = -Wall - Wextra - Werror - pthread
	- g SRC = ft_atol.c ft_calloc.c get_time.c parse_args.c philo.c philo_start.c rotine.c waiter_init.c OBJ_DIR =
									obj

										OBJ : = $(patsubst %.c, $(OBJ_DIR) /
												%.o, $(SRC))

															all
	: $(NAME)

			$(OBJ_DIR) /
		%.o : %.c @mkdir - p $(@D) $(CC) $(FLAGS) - c $ <
												-o $ @

													$(NAME)
	: $(OBJ) $(CC) $(OBJ) -
													o $(NAME) $(FLAGS)

														clean : @rm -
																rf $(OBJ_DIR) @echo "Objects files clean"

																fclean : clean @rm
																	-
																		rf $(NAME) @echo "executable removed: $(NAME)"

																		re : fclean all
