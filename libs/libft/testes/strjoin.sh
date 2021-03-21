
funcao="strjoin"

if [ $(whoami) = "gabriel" ]
then
    gcc -O2 -funroll-loops -Werror -Wall -Wextra $funcao.c ../sources/ft_strjoin.c ../sources/ft_strlen.c -c
    clang -O2 -funroll-loops -Werror -Wall -Wextra strjoin.o ft_strjoin.o ft_strlen.o -o main
	rm *.o
else
    gcc -O2 -funroll-loops -Werror -Wall -Wextra $funcao.c ../sources/ft_strjoin.c ../sources/ft_strlen.c -c
    clang -O2 -funroll-loops -Werror -Wall -Wextra strjoin.o ft_strjoin.o ft_strlen.o
	rm *.o
fi
