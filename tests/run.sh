#!/bin/bash
shopt -s globstar

valone="--leak-check=full"
valtwo="--track-origins=yes"
valthree="--show-leak-kinds=all"

rm ./val.md

fun="mat44_rotate_z"
clang -g -O3 -Weverything -I ../srcs -I ../assets/minilibx-linux/ \
-I ../headers/math/ -I ../headers/list/ -c ./check.c ./$fun.c
clang ./$fun.o ./check.o ../srcs/**.o  -L ../assets/minilibx-linux -lm -lmlx -lXext -lX11
echo "$fun" >>./val.md
valgrind "$valone" "$valtwo" "$valthree" --log-fd=9 9>>./val.md ./a.out
rm ./*.o

fun="reflect"
clang -g -O3 -Weverything -I ../srcs -I ../assets/minilibx-linux/ \
-I ../headers/math/ -I ../headers/list/ -c ./check.c ./$fun.c
clang ./$fun.o ./check.o ../srcs/**.o  -L ../assets/minilibx-linux -lm -lmlx -lXext -lX11
echo "$fun" >>./val.md
valgrind "$valone" "$valtwo" "$valthree" --log-fd=9 9>>./val.md ./a.out
rm ./*.o

fun="lighting_1"
clang -g -O3 -Weverything -I ../srcs -I ../assets/minilibx-linux/ \
-I ../headers/math/ -I ../headers/list/ -c ./check.c ./$fun.c
clang ./$fun.o ./check.o ../srcs/**.o  -L ../assets/minilibx-linux -lm -lmlx -lXext -lX11
echo "$fun" >>./val.md
valgrind "$valone" "$valtwo" "$valthree" --log-fd=9 9>>./val.md ./a.out
rm ./*.o

fun="lighting_2"
clang -g -O3 -Weverything -I ../srcs -I ../assets/minilibx-linux/ \
-I ../headers/math/ -I ../headers/list/ -c ./check.c ./$fun.c
clang ./$fun.o ./check.o ../srcs/**.o  -L ../assets/minilibx-linux -lm -lmlx -lXext -lX11
echo "$fun" >>./val.md
valgrind "$valone" "$valtwo" "$valthree" --log-fd=9 9>>./val.md ./a.out
rm ./*.o

fun="lighting_3"
clang -g -O3 -Weverything -I ../srcs -I ../assets/minilibx-linux/ \
-I ../headers/math/ -I ../headers/list/ -c ./check.c ./$fun.c
clang ./$fun.o ./check.o ../srcs/**.o  -L ../assets/minilibx-linux -lm -lmlx -lXext -lX11
echo "$fun" >>./val.md
valgrind "$valone" "$valtwo" "$valthree" --log-fd=9 9>>./val.md ./a.out
rm ./*.o

fun="lighting_4"
clang -g -O3 -Weverything -I ../srcs -I ../assets/minilibx-linux/ \
-I ../headers/math/ -I ../headers/list/ -c ./check.c ./$fun.c
clang ./$fun.o ./check.o ../srcs/**.o  -L ../assets/minilibx-linux -lm -lmlx -lXext -lX11
echo "$fun" >>./val.md
valgrind "$valone" "$valtwo" "$valthree" --log-fd=9 9>>./val.md ./a.out
rm ./*.o

fun="lighting_5"
clang -g -O3 -Weverything -I ../srcs -I ../assets/minilibx-linux/ \
-I ../headers/math/ -I ../headers/list/ -c ./check.c ./$fun.c
clang ./$fun.o ./check.o ../srcs/**.o  -L ../assets/minilibx-linux -lm -lmlx -lXext -lX11
echo "$fun" >>./val.md
valgrind "$valone" "$valtwo" "$valthree" --log-fd=9 9>>./val.md ./a.out
rm ./*.o


