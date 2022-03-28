rm a.out ft.txt
gcc -Wall -Werror -Wextra epur_str.c -g
./a.out "vous voyez c'est facile d'afficher la meme chose" | cat -e >> ft.txt
./a.out " seulement      la c'est     plus dur " | cat -e >> ft.txt
./a.out "comme c'est cocasse" "vous avez entendu, Mathilde ?" | cat -e >> ft.txt
./a.out "" | cat -e >> ft.txt
