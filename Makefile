NAME := libftprintf.a
CC := cc
CFLAGS := -Wall -Wextra -Werror
SRC_FILES := ft_printf.c ft_help.c

OBJ_FILES = $(SRC_FILES:.c=.o)

all: obj $(NAME)

obj: $(SRC_FILES)

%.o: %.c ft_printf.h
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ_FILES)
	ar rc $(NAME) $(OBJ_FILES)
	ranlib $(NAME)

clean:
	rm -f $(OBJ_FILES)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re