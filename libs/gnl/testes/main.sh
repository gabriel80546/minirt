#clang -Wall -Wextra -Werror -g3 -fsanitize=address -D BUFFER_SIZE=$1 main.c ../get_next_line.c ../get_next_line_utils.c
clang -Wall -Wextra -Werror -D BUFFER_SIZE=$1 -g main.c ../get_next_line.c ../get_next_line.h ../get_next_line_utils.c
#clang -Wall -Wextra -Werror -g -D BUFFER_SIZE=$1 main.c ../get_next_line.c -o main -L../libft/ -lft
#clang -Wall -Wextra -Werror -D BUFFER_SIZE=$1 main.c ../old_strategy/get_next_line.c -o main -L../libft/ -lft
# clang -Wall -Wextra -Werror -D BUFFER_SIZE=$1 main.c ../get_next_line.c -o main -L../libft/ -lft
