NAME = bsq
SRC =	check_input.c \
		find_bsq.c \
		get_int_map.c \
		put_array.c \
		read_map.c \
		struct_map.c \
		utils.c \
		utils2.c \
		main.c
OBJ = $(SRC:.c=.o)
CC = cc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all