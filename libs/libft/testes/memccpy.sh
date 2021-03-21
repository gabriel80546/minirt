
funcao="memccpy"

if [ $(whoami) = "gabriel" ]
then
    gcc $funcao.c ../libft.h ../ft_$funcao.c -o main
else
    gcc $funcao.c ../libft.h ../ft_$funcao.c
fi
