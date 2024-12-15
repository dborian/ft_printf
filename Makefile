SRCS =	ft_printf.c \
		ft_putchar.c \
		ft_putnbr.c \

cc = cc
FLAGS = -Wall -Wextra -Werror
HEADER = ft_printf.h
OBJS = $(SRCS:.c=.o)
NAME = libftprintf.a

%.o: %.c $(HEADER) Makefile
	$(CC) $(FLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean;
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re