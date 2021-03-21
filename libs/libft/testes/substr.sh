
funcao="substr"

if [ $(whoami) = "gabriel" ]
then
    gcc -O2 -funroll-loops -Werror -Wall -Wextra $funcao.c ../libft.h ../ft_$funcao.c ../ft_strlen.c -o main
else
    gcc -O2 -funroll-loops -Werror -Wall -Wextra $funcao.c ../libft.h ../ft_$funcao.c ../ft_strlen.c
fi
