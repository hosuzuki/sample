gcc -Wall -Werror -Wextra  utils.c get_next_line.c main.c -o get_next_line -g
#gcc -g -fsanitize=address get_next_line.c utils.c main.c -o get_next_line
#<<out
./get_next_line < get_next_line.c > yours_.res
cat -e yours_.res > yours.res
#cat -e < get_next_line.c > original.res
cat -e get_next_line.c > original.res
diff -y --suppress-common-line original.res yours.res
#rm -rf original.res yours_.res yours.res
#rm -rf get_next_line
#out
