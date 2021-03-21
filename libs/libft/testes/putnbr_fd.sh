
funcao="putnbr_fd"

if [ $(whoami) = "gabriel" ]
then
    gcc $funcao.c ../libft.h ../sources/ft_$funcao.c ../sources/ft_itoa.c ../sources/ft_strlcpy.c ../sources/ft_putstr_fd.c ../sources/ft_putchar_fd.c ../sources/ft_memset.c -o main
else
    gcc $funcao.c ../libft.h ../sources/ft_$funcao.c ../sources/ft_itoa.c ../sources/ft_strlcpy.c ../sources/ft_putstr_fd.c ../sources/ft_putchar_fd.c ../sources/ft_memset.c
fi
