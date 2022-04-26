gcc -Wall -Wextra -Werror main.c -D PRINT="printf" ft_printf.c -o pf.out
gcc -Wall -Wextra -Werror main.c -D PRINT="ft_printf" ft_printf.c -o ft.out
./pf.out > pf.txt
./ft.out > ft.txt
diff -y --suppress-common-line pf.txt ft.txt > diff.txt
