#!/bin/bash

rm diff.txt pf.txt ft.txt pf.out ft.out
gcc  -D PRINT="printf" ft_printf.c main.c -o pf.out
gcc -Wall -Werror -Wextra -D  PRINT="ft_printf"  ft_printf.c main.c -o ft.out -g
./pf.out >> pf.txt
./ft.out >> ft.txt
diff ft.txt pf.txt >> diff.txt
