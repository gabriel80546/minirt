
funcao="memcpy"

if [ $(whoami) = "gabriel" ]
then
    gcc $funcao.c ../libft.h ../sources/ft_$funcao.c -o main
else
    gcc $funcao.c ../libft.h ../sources/ft_$funcao.c
fi
