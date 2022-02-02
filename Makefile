SRC_FILES= push_swap.c check_args.c push.c swap.c reverse.c rotate.c make_stack.c get_nbr.c \
			best_movement.c stack_size.c stack_check_functions.c test_sa.c smart_rotate.c free_stack.c get_args.c
SRC_B_FILES= 
SRC=$(addprefix src/, $(SRC_FILES))
SRC_B=$(addprefix src_bonus/, $(SRC_B_FILES))
OBJ=$(addprefix obj/, $(SRC_FILES:.c=.o))
OBJ_DIR=obj
OBJ_B=$(addprefix obj_bonus/, $(SRC_B_FILES:.c=.o))
OBJ_B_DIR=obj_bonus
LIBFT=libft/libft.a
LIBFT_DIR=libft
NAME=push_swap
NAME_B=checker

all: $(NAME)

bonus: $(NAME_B)

$(NAME): $(LIBFT) $(OBJ_DIR) $(OBJ)
	gcc -Wall -Werror -Wextra $(OBJ) $(LIBFT) -o $(NAME)

$(NAME_B): $(LIBFT) $(OBJ_B_DIR) $(OBJ_B)
	gcc -Wall -Werror -Wextra $(OBJ_B) $(LIBFT) -o $(NAME_B)

obj/%.o: src/%.c
	gcc -Wall -Werror -Wextra -c $< -o $@

obj_bonus/%.o: src_bonus/%.c
	gcc -Wall -Werror -Wextra -c $< -o $@

$(OBJ_DIR):
	mkdir $(OBJ_DIR)

$(OBJ_B_DIR):
	mkdir $(OBJ_B_DIR)

$(LIBFT):
	make -C $(LIBFT_DIR)

clean:
	rm -rf $(OBJ)
	rm -rf $(OBJ_B)
	make -C $(LIBFT_DIR) clean

fclean: clean
	rm -rf $(NAME)
	make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
