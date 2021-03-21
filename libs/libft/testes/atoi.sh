
funcao="atoi"

if [ $(whoami) = "gabriel" ]
then
    gcc $funcao.c ../libft.h ../sources/ft_$funcao.c ../sources/ft_memset.c ../sources/ft_strlen.c ../sources/ft_strchr.c -o main
else
    gcc $funcao.c ../libft.h ../sources/ft_$funcao.c ../sources/ft_memset.c ../sources/ft_strlen.c ../sources/ft_strchr.c
fi
