NAME = rush-02

CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRCS = main.c \
       utils.c \
       validation.c \
       dictionary.c \
       convert.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

%.o: %.c rush02.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re