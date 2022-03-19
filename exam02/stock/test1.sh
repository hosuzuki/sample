gcc -Wall -Werror -Wextra get_next_line1.c main.c -o get_next_line
#<<out
./get_next_line < get_next_line1.c > yours_.res
cat -e yours_.res > yours.res
cat -e < get_next_line1.c > original.res
diff -y --suppress-common-line original.res yours.res
out
#rm -rf original.res yours_.res yours.res get_next_line
