compile="gcc -g main.c ../*.c -I .. -o main"
compile="gcc -g3 -fsanitize=address main.c ../*.c -I .. -o main"
echo $compile
$compile
