NAME = push_swap.a
SOURCES = \
	push_swap.c \


OBJECTS = $(SOURCES:.c=.o)
CFLAGS = -Wall -Wextra -Werror
CC = gcc
all: $(NAME)
$(NAME): $(OBJECTS)
	$(AR) -r $@ $?
%.o: %.c
	$(CC) -c $(CFLAGS) $?
	
clean:
	rm -f $(OBJECTS)
fclean: clean
	rm -f $(NAME)
re: fclean all
.PHONY: all bonus clean fclean re