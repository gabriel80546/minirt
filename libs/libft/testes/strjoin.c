/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strjoin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 12:33:59 by jtoty             #+#    #+#             */
/*   Updated: 2021/02/11 11:36:40 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "../libft.h"
#include <stdio.h>
#include <string.h>
#include <strings.h>

static void			ft_print_result(char const *s)
{
	int		len;

	len = 0;
	while (s[len])
		len++;
	if(write(1, s, len) > 0)
		return;
	else
		return;
}

static void			check_strjoin(char *s1, char *s2)
{
	char	*strjoin;

	if (!(strjoin = ft_strjoin(s1, s2)))
		ft_print_result("NULL");
	else
		ft_print_result(strjoin);
	if (strjoin == s1 || strjoin == s2)
		ft_print_result("\nA new string was not returned");
	else
		free(strjoin);
}

int					main_one(void)
{
	char *s1 = "my favorite animal is";
	char *s2 = " ";
	char *s3 = "the nyancat";
	char *res = ft_strjoin(ft_strjoin(s1, s2), s3);

	printf("res = '%s'\n", res);

	if (!strcmp(res, "my favorite animal is the nyancat")) {
		printf("TEST_SUCCESS\n");
		return (0); }
	printf("TEST_FAILED\n");
	return (1);
}

int					main_two(void)
{
	char *s1 = "my favorite animal is";
	char *s2 = " ";
	char *s3 = "the nyancat";
	char *tmp = ft_strjoin(s1, s2);
	char *res = ft_strjoin(tmp, s3);

	printf("res = '%s'\n", res);

	free(tmp);
	if (!strcmp(res, "my favorite animal is the nyancat"))
	{
			free(res);
			printf("TEST_SUCCESS\n");
			return (1);
	}
	free(res);
	printf("TEST_FAILED\n");
	return (0);
}

int					main(void)
{
	char *s1 = "my favorite animal is ";
	char *s2 = s1 + 20;
	char *res = ft_strjoin(s2, s1);

	printf("res = '%s'; strcmp(res, [teste]) = %d\n", res, strcmp(res, "s my favorite animal is "));

	if (!strcmp(res, "s my favorite animal is ")) {
		printf("TEST_SUCCESS\n");
		return (1); }
	printf("TEST_FAILED\n");
	return (0);
}

int					main_four(void)
{
	char *s1 = "where is my ";
	char *s2 = "malloc ???";
	char *s3 = "where is my malloc ???";


	char *res = ft_strjoin(s1, s2);

	printf("res = '%s'\n", res);


	if (!strcmp(res, s3)) {
		printf("TEST_SUCCESS\n");
		return (0); }
	printf("TEST_FAILED\n");
	return (1);
}

int					main_old(int argc, const char *argv[])
{
	char	s1[] = "lorem ipsum";
	char	s2[] = "dolor sit amet";
	int		arg;

	alarm(5);
	if (argc == 1)
		return (0);
	else if ((arg = atoi(argv[1])) == 1)
	{
		check_strjoin(s1, s2);
	}
	else if (arg == 2)
	{
		s1[0] = '\0';
		check_strjoin(s1, s2);
	}
	else if (arg == 3)
	{
		s2[0] = '\0';
		check_strjoin(s1, s2);
	}
	else if (arg == 4)
	{
		s1[0] = '\0';
		s2[0] = '\0';
		check_strjoin(s1, s2);
	}
	return (0);
}
