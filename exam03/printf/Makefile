SRC		= ft_printf.c
NAME		= libftprintf.a
CC = gcc -Wall -Wextra -Werror

$(NAME) : 
	${CC} -c ${SRC} -o ft_printf.o
	ar rc $(NAME) ft_printf.o libft.a
	ranlib $(NAME)

all : ${NAME}

clean :
	rm ft_printf.o

fclean : clean
	rm $(NAME)

re : fclean all

.PHONY : all clean fclean re
