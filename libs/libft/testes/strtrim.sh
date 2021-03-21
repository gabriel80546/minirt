
funcao="strtrim"

if [ $(whoami) = "gabriel" ]
then
    clang -Wextra -Wall -Werror -g3 -fsanitize=address $funcao.c ../libft.h ../ft_$funcao.c ../ft_strchr.c ../ft_strlen.c ../ft_substr.c
else
    clang -Wextra -Wall -Werror -g3 -fsanitize=address $funcao.c ../libft.h ../ft_$funcao.c ../ft_strchr.c ../ft_strlen.c ../ft_substr.c
fi
