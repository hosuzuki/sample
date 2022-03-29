gcc -Wall -Werror -Wextra str_capitalizer.c -o str_capitalizer
./str_capitalizer | cat -e
./str_capitalizer "Premier PETIT TesT" | cat -e
./str_capitalizer "DeuxiEmE tEST uN PEU moinS  facile" "   attention C'EST pas dur QUAND mEmE" "ALLer UN DeRNier 0123456789pour LA rouTE    E " | cat -e
