rm res0.txt res.txt original.txt diff.txt
gcc -Wall -Wextra -Werror get_next_line.c main.c
./a.out << get_next_line.c >> res0.txt
cat -e res0.txt >> res.txt
cat -e get_next_line.c >> original.txt
diff -y res.txt original.txt >> diff.txt
