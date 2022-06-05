CC = gcc

CFLAGS = -Wall -Wextra -Werror
LEAKS = -fsanitize=address
all:
	$(CC) $(CFLAGS) $(LEAKS) src/push_swap.c src/push_swap_controls.c
clean:
	rm -r a.out
