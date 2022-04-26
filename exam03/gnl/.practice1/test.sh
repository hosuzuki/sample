gcc -Wall -Wextra -Werror  main.c get_next_line.c -g
./a.out < get_next_line.c > my_.txt
cat -e my_.txt > my.txt
cat -e get_next_line.c > original.txt
diff -y --suppress-common-line my.txt original.txt > diff.txt
