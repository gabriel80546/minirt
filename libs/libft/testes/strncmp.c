/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strncmp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 12:07:32 by jtoty             #+#    #+#             */
/*   Updated: 2021/02/08 14:06:31 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "../libft.h"
#include <stdio.h>

static void		ft_print_result(int n)
{
	// unsigned char teste = n;
		printf("%d", n);
	// if (n > 0)
	// 	printf("%ld", n);
	// else if (n < 0)
	// 	printf("-1");
	// else
	// 	printf("0");
}
static void		print_char_array(char *string)
{
	size_t i;
	for(i = 0; i < strlen(string); i++) {
		printf("\t%i,", (unsigned char)string[i]);
	}
}

static void     warp(const char *s1, const char *s2, size_t n)
{
	printf("s1 = '%s', size = %ld\n", s1, strlen(s1));
	printf("s2 = '%s', size = %ld\n", s2, strlen(s2));
	printf("s1 = [");
	print_char_array((char *)s1);
	printf("];\n");
	printf("s2 = [");
	print_char_array((char *)s2);
	printf("];\n");
	printf("n = %ld\n\nexec ft_strncmp(s1, s2, n)\n\nsaida => ", n);
	ft_print_result(strncmp(s1, s2, n));
	printf("\n\n");
}

int				main(int argc, const char *argv[])
{
	int		arg;

	alarm(5);
	if (argc == 1)
		return (0);
	else if ((arg = atoi(argv[1])) == 1)
		warp("salut", "salut", 5);
	else if (arg == 2)
		warp("test", "testss", 7);
	else if (arg == 3)
		warp("testss", "test", 7);
	else if (arg == 4)
		warp("test", "tEst", 4);
	else if (arg == 5)
		warp("", "test", 4);
	else if (arg == 6)
		warp("test", "", 4);
	else if (arg == 7)
		warp("abcdefghij", "abcdefgxyz", 3);
	else if (arg == 8)
		warp("abcdefgh", "abcdwxyz", 4);
	else if (arg == 9)
		warp("zyxbcdefgh", "abcdwxyz", 0);
	else if (arg == 10)
		warp("abcdefgh", "", 0);
	else if (arg == 11)
		warp("test\200", "test\0", 6);
	else if (arg == 12)
		warp("atoms\0\0\0\0", "atoms\0abc", 8);
	return (0);
}
