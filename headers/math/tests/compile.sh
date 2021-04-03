compile="gcc -g3 -fsanitize=address main.c ../*.c -I .. -lm -o main"
compile="gcc -g main.c ../*.c -I .. -lm -o main"
echo $compile
$compile
