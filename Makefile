CC 			= 	cc
FLAGS		=	-g -Wall -Wextra -Werror
INCS		=	-Iinc
SRC_DIR		=	src
OBJ_DIR		=	build
SRCS		=	main.c										\
				args.c										\
				clean.c										\
				init.c										\
				monitor.c									\
				mutexes.c									\
				routine.c									\
				time.c										\
				threads.c									\
				structs.c									\
				utils.c
SRC_FILES	=	$(addprefix $(SRC_DIR)/, $(SRCS))
OBJS		=	$(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC_FILES))
NAME		=	philo

all:		$(NAME)

$(NAME):	$(OBJS)
	@$(CC) $(OBJS) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(FLAGS) $(INCS) -c $< -o $@

clean:
	@rm -rf $(OBJ_DIR)

fclean:		clean
	@rm -f $(NAME)

re:			fclean all
