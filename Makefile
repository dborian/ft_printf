SRCS =	ft_printf.c \
		ft_putchar.c \
		ft_putnbr.c \

cc = cc
FLAGS = -Wall -Wextra -Werror
HEADER = ft_printf.h
OBJS = $(addprefix $(DIR_OBJS)/, $(SRCS:.c=.o))
DIR_OBJS = .objs
NAME = libftprintf.a

$(DIR_OBJS)/%.o: %.c $(HEADER) Makefile
	@mkdir -p $(DIR_OBJS)
	@$(CC) $(FLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	@echo "\033[32m scrs compiled \033[0m"
	@ar rcs $(NAME) $(OBJS)
	@echo "\033[32m lib created \033[0m"

clean:
	@rm -f $(OBJS)
	@rm -rf $(DIR_OBJS)
	@echo "\033[0;31m objs removed \033[0m"

fclean: clean;
	@rm -f $(NAME)
	@echo "\033[0;31m lib removed \033[0m"

re: fclean all

.PHONY: all clean fclean re