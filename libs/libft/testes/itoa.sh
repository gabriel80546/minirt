
funcao="itoa"

if [ $(whoami) = "gabriel" ]
then
    gcc $funcao.c ../libft.h ../sources/ft_$funcao.c ../sources/ft_strlcpy.c ../sources/ft_strlcat.c ../sources/ft_strlen.c -o main
else
    gcc $funcao.c ../libft.h ../sources/ft_$funcao.c ../sources/ft_strlcpy.c ../sources/ft_strlcat.c ../sources/ft_strlen.c
fi
