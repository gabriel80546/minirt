# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gpassos- <gpassos-@student.42sp.org>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/17 10:56:13 by gpassos-          #+#    #+#              #
#    Updated: 2021/02/17 10:56:18 by gpassos-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS = -Wall -Wextra -Werror
CC = clang
NAME = libft.a

SOURCES = ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c \
		ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c ft_memccpy.c \
		ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c \
		ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c \
		ft_split.c ft_strchr.c ft_strdup.c ft_strjoin.c ft_strlcat.c \
		ft_strlcpy.c ft_strlen.c ft_strmapi.c ft_strncmp.c ft_strnstr.c \
		ft_strrchr.c ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c

OBJS = $(SOURCES:.c=.o)

$(NAME): all

all: $(OBJS)
	ar -rc $(NAME) $^

clean:
	rm -f -- *.o
	rm -f -- libft.h.gch

fclean: clean
	rm -f -- $(NAME)

re: fclean all

%.o: %.c
	$(CC) -c $(CFLAGS) libft.h $^

so:
	$(CC) -fPIC $(CFLAGS) *.c
	gcc -shared -o libft.so $(OBJS)

bonus:
	printf ""
