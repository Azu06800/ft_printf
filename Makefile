SRCS = ft_isspace.c \
	   ft_putchar.c ft_putnbr.c ft_putptr.c ft_putstr.c \
	   ft_putunbr_base.c ft_putunbr.c \
	   ft_strchr.c ft_strlen.c \
	   ft_printf.c

OBJS  = ${SRCS:.c=.o}

NAME = libftprintf.a

all: $(NAME)

$(NAME): $(OBJS)
			ar crs $(NAME) $(OBJS)

.c.o:
	gcc -Werror -Wextra -Wall -c $< -o $(<:.c=.o)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: 	fclean all

.PHONY: all clean fclean re
