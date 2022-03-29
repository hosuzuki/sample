gcc -Wall -Werror -Wextra rstr_capitalizer.c -o rstr_capitalizer
./rstr_capitalizer | cat -e
./rstr_capitalizer "Premier PETIT TesT" | cat -e
./rstr_capitalizer "DeuxiEmE tEST uN PEU moinS  facile" "   attention C'EST pas dur QUAND mEmE" "ALLer UN DeRNier 0123456789pour LA rouTE    E " | cat -e
