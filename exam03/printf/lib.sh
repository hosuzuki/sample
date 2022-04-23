gcc -Wall -Werror -Wextra -c ft_printf.c -o ft_printf.o
ar rc libftprintf.a ft_printf.o
ranlib libftprintf.a
