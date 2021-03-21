
funcao="strnstr"

if [ $(whoami) = "gabriel" ]
then
    gcc $funcao.c ../libft.h ../sources/ft_$funcao.c ../sources/ft_strlen.c ../sources/ft_strncmp.c -lbsd -o main
else
    gcc $funcao.c ../libft.h ../sources/ft_$funcao.c ../sources/ft_strlen.c ../sources/ft_strncmp.c
fi
