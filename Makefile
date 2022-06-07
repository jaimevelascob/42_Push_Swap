CC = gcc

CFLAGS = -Wall -Wextra -Werror
LEAKS = -fsanitize=address
SRC = src/push_swap.c src/push_swap_controls.c src/push_swap_init.c src/push_swap_checkers.c
OBJ = $(SRC:.c=.o)
all: push_swap

push_swap: $(OBJ)
	$(CC) $(LEAKS) $(OBJ) -o push_swap
%.o : %.c
	gcc -c $< -o $@
clean:
	rm -r a.out
