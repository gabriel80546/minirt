compile="gcc -g3 -fsanitize=address main.c ../*.c -I .. -lm -o main"
compile="clang -Wall -Wextra -Weverything -O3 -g main.c ../*.c -I .. -lm"
echo $compile
$compile
