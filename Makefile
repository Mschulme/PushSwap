NAME = push_swap

OBJ = $(SRC:%.c=%.o)

SRC = push_swap.c ft_stack_utils.c ft_stack_rotations.c ft_split.c \
		ft_sort.c ft_radixsort.c ft_helper.c ft_createarray_and_index.c free_stack.c \
		ft_init_stack_1.c ft_init_stack_2.c ft_atoi.c ft_sort_small.c ft_stack_push.c

CC = gcc

CFLAGS = -Wall -Werror -Wextra

%.o: %.c
	$(CC) $(CFLAGS) -c $^ -o $@

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
