rm ft.txt pf.txt
gcc -Wall -Werror -Wextra ft_printf.c main.c -D PRINT="ft_printf" -g -o ft.out
gcc -Wall -Werror -Wextra ft_printf.c main.c -D PRINT="printf" -o pf.out
./ft.out >> ft.txt
./pf.out >> pf.txt
rm ft.out pf.out
diff -y --suppress-common-line ft.txt pf.txt
