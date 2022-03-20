#!/bin/bash

rm diff.txt pf.txt ft.txt pf.out ft.out
gcc -Wall -Werror -Wextra -D PRINT="printf" utils.c ft_printf.c  ft_print_deci.c ft_print_hex.c ft_print_str.c main.c  -o pf.out
gcc -Wall -Werror -Wextra -D PRINT="ft_printf"  utils.c ft_printf.c  ft_print_deci.c ft_print_hex.c ft_print_str.c main.c -o ft.out -g
./pf.out >> pf.txt
./ft.out >> ft.txt
diff ft.txt pf.txt >> diff.txt
