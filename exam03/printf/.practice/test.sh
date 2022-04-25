rm ft.txt pf.txt diff.txt
#forgot main.c
# check the order
gcc -Wall -Wextra -Werror ft_printf.c main.c -D PRINT="printf"  -o pf.out
gcc -Wall -Wextra -Werror ft_printf.c main.c -D PRINT="ft_printf" -o ft.out
./pf.out >> pf.txt
./ft.out >> ft.txt
rm pf.out ft.out
diff pf.txt ft.txt >> diff.txt
#diff -y --suppress-common-line pf.txt ft.txt
