gcc -Wall -Werror -Wextra print_hex.c -g -o print_hex
./print_hex "10" | cat -e
./print_hex "15" | cat -e
./print_hex "16" | cat -e
./print_hex "17" | cat -e
./print_hex "255" | cat -e
./print_hex "5156454" | cat -e
./print_hex | cat -e
