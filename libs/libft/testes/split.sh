
funcao="split"

if [ $(whoami) = "gabriel" ]
then
    clang -Wextra -Wall -Werror -g3 -fsanitize=address $funcao.c ../libft.h ../ft_$funcao.c ../ft_strlen.c ../ft_calloc.c ../ft_memset.c
else
    clang -Wextra -Wall -Werror -g3 -fsanitize=address $funcao.c ../libft.h ../ft_$funcao.c ../ft_strlen.c ../ft_calloc.c ../ft_memset.c
fi
