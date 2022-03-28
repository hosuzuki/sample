rm a.out
gcc -Wall -Wextra -Werror expand_str.c -g
./a.out "vous   voyez   c'est   facile   d'afficher   la   meme   chose" | cat -e
./a.out " seulement          la c'est      plus dur " | cat -e
./a.out "comme c'est cocasse" "vous avez entendu, Mathilde ?" | cat -e
./a.out "" | cat -e
