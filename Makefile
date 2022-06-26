CC = gcc -g

CFLAGS = -Wall -Wextra -Werror
LEAKS = -fsanitize=address
SRC = src/push_swap.c src/push_swap_controls.c src/push_swap_init.c src/push_swap_checkers.c \
	  src/push_swap_short.c src/push_swap_validate.c src/push_swap_helpers.c src/push_swap_big_list.c \
 	  src/push_swap_split.c src/push_swap_split_helpers.c src/push_swap_checker_error.c
OBJ = $(SRC:.c=.o)
all: push_swap

push_swap: $(OBJ)
	$(CC) $(LEAKS) $(OBJ) -o push_swap
%.o : %.c
	gcc -c $< -o $@
clean:
	rm -f push_swap
fclean: clean
	rm -f $(OBJ)
re: fclean all

.PHONY: clean fclean re 
