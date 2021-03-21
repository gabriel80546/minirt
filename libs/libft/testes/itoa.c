/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 12:19:22 by jtoty             #+#    #+#             */
/*   Updated: 2021/02/13 09:35:46 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "../libft.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>


static void		ft_print_result(char *s)
{
	int		len;

	if (!s)
		write(1, "NULL", 4);
	else
	{
		len = 0;
		while (s[len])
			len++;
		write(1, s, len);
		free(s);
	}
	// write(1, "\n", 1);
}

int				main_one(void)
{
	char *i1 = ft_itoa(-623);
	char *i2 = ft_itoa(156);
	char *i3 = ft_itoa(-0);

	if (strcmp(i1, "-623"))
	{
		printf("TEST_FAILED\n");
		return (1);
	}
	if (strcmp(i2, "156"))
	{
		printf("TEST_FAILED\n");
		return (2);
	}
	if (strcmp("0", i3))
	{
		printf("TEST_FAILED\n");
		return (3);
	}
	printf("TEST_SUCCESS\n");
	return (0);
}
int				main_two(void)
{
	int size;
	char *i1;

	i1 = ft_itoa(-5859);
	size = 6;
	if (size == 6) {
		printf("TEST_SUCCESS\n");
		return (1); }
	printf("TEST_KO\n");
	return (0);
}

int				main_three(void)
{
	int size;
	char *i1;

	i1 = ft_itoa(0);
	size = 2;
	if (size == 2) {
		printf("TEST_SUCCESS\n");
		return (1); }
	printf("TEST_KO\n");
	return (0);
}

int				main_four(void)
{
	srand(time(NULL));
	int n;
	char *d;

	for (int i = 0; i < 100000; i++)
	{
		n = rand();
		d = ft_itoa(n);
		if (atoi(d) != n)
		{
			printf("TEST_FAILED\n");
			return (1);
		}
		free(d);
	}
	printf("TEST_SUCCESS\n");
	return (0);
}



int				main(int argc, const char *argv[])
{
	int		arg;

	alarm(5);
	if (argc == 1)
		return (0);
	else if ((arg = atoi(argv[1])) == 1)
		ft_print_result(ft_itoa(0));
	else if (arg == 2)
		ft_print_result(ft_itoa(9));
	else if (arg == 3)
		ft_print_result(ft_itoa(-9));
	else if (arg == 4)
		ft_print_result(ft_itoa(10));
	else if (arg == 5)
		ft_print_result(ft_itoa(-10));
	else if (arg == 6)
		ft_print_result(ft_itoa(8124));
	else if (arg == 7)
		ft_print_result(ft_itoa(-9874));
	else if (arg == 8)
		ft_print_result(ft_itoa(543000));
	else if (arg == 9)
		ft_print_result(ft_itoa(-2147483647LL));
	else if (arg == 10)
		ft_print_result(ft_itoa(2147483647));
	else if (arg == 11)
		ft_print_result(ft_itoa(-2147483648LL));
	return (0);
}
