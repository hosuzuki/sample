gcc -Wall -Wextra -Werror ft_printf.c main.c -D PRINT="printf" -o pf.out
gcc -Wall -Wextra -Werror ft_printf.c main.c -D PRINT="ft_printf" -o ft.out -g
./pf.out > pf.txt
./ft.out > ft.txt
diff -y --suppress-common-line pf.txt ft.txt
