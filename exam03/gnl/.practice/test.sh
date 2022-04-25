#rm res0.txt res.txt original.txt diff.txt
#rm yours_.res yours.res original.res get_next_line
gcc -Wall -Wextra -Werror get_next_line.c main.c -o get_next_line -g
#./a.out << get_next_line.c >> res0.txt
#./get_next_line < get_next_line.c > yours_.res
./get_next_line < get_next_line.c > yours_.txt
#cat -e yours_.res > yours.res
cat -e yours_.txt > yours.txt
#cat -e get_next_line.c > original.res
cat -e get_next_line.c > original.txt
#diff -y --suppress-common-line  yours.res original.res > diff.txt
diff -y --suppress-common-line  yours.txt original.txt > diff.txt
