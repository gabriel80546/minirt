#!/bin/bash
shopt -s globstar

valone="--leak-check=full"
valtwo="--track-origins=yes"
valthree="--show-leak-kinds=all"

fun="mat44_rotate_z"
rm ./val.md
clang -g -O3 -Weverything -I ../srcs -I ../assets/minilibx-linux/ \
-I ../headers/math/ -I ../headers/list/ -c ./check.c ./$fun.c
clang ./$fun.o ./check.o ../srcs/**.o  -L ../assets/minilibx-linux -lm -lmlx -lXext -lX11
echo "$fun" >>./val.md
valgrind "$valone" "$valtwo" "$valthree" --log-fd=9 9>>./val.md ./a.out
rm ./*.o

fun="lighting_1"
rm ./val.md
clang -g -O3 -Weverything -I ../srcs -I ../assets/minilibx-linux/ \
-I ../headers/math/ -I ../headers/list/ -c ./check.c ./$fun.c
clang ./$fun.o ./check.o ../srcs/**.o  -L ../assets/minilibx-linux -lm -lmlx -lXext -lX11
echo "$fun" >>./val.md
valgrind "$valone" "$valtwo" "$valthree" --log-fd=9 9>>./val.md ./a.out
rm ./*.o
