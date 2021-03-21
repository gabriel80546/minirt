/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strlcpy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 09:33:54 by gabriel           #+#    #+#             */
/*   Updated: 2021/02/18 07:45:18 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include "../libft.h"
#include <stdlib.h>
#include <string.h>

size_t	strlcpy(char *dst, const char *src, size_t size);


int	main_old(void)
{
	char src[40];
	char dest_one[12];
	char dest_two[12];

	memset(dest_one, '\0', sizeof(dest_one));
	strcpy(src, "test string");
	strncpy(dest_one, src, 9);
	printf("Final copied string : %s\n", dest_one);
	memset(dest_two, '\0', sizeof(dest_two));
	strcpy(src, "test string");
	ft_strlcpy(dest_two, src, 9);
	printf("Final copied string : %s\n", dest_two);
	return (0);
}



void	ft_print_result(int n)
{
	// char c;

	// if (n >= 10)
	// 	ft_print_result(n / 10);
	// c = n % 10 + '0';
	// write (1, &c, 1);
	printf("%d", n);
}

size_t	check_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	x;
	int		temp;

	temp = (size - 1);
	temp = (temp < 0) ? 0 : temp;
	printf("dest = '%s'(%ld)\n", dest, strlen(dest));
	printf("src = '%s'(%ld)\n", src, strlen(src));
	printf("size = %ld\n", size);

	printf("\n--------------\n");
	printf("a saida seria substr(src('%s'(%ld)), 0, size(%ld) - 1)\n", src, strlen(src), size);
	printf("que é '%s'(%ld)\n", ft_substr(src, 0, temp), strlen(ft_substr(src, 0, temp)));
	printf("mas size é 0? %s\n", (size == 0) ? "sim" : "nao");
	if (size == 0)
	{
		printf("entao nao da para mostrar copiar nada\n");
		printf("e a saida é apenas dest('%s'(%ld))\n", dest, strlen(dest));
	}
	else
	{
		printf("então a saida é isso mesmo '%s'(%ld)\n", ft_substr(src, 0, temp), strlen(ft_substr(src, 0, temp)));
	}
	printf("--------------\n\n");

	x = ft_strlcpy(dest, src, size);
	printf("x = %ld\n", x);
	printf("dest = '%s'(%ld)\n", dest, strlen(dest));
}

int		main(int argc, const char *argv[])
{
	char	*dest;
	int		arg;
	int		x;

	alarm(5);
	if (!(dest = (char *)malloc(sizeof(*dest) * 15)) || argc == 1)
		return (0);
	memset(dest, 0, 15);
	memset(dest, 'r', 6);
	if ((arg = atoi(argv[1])) == 1)
	{
		check_strlcpy(dest, "lorem", 15);
		// ft_print_result(ft_strlcpy(dest, "lorem", 15));
		// write(1, "\n", 1);
		// write(1, dest, 15);
		// printf("\n%s", dest);
	}
	else if (atoi(argv[1]) == 2)
	{
		check_strlcpy(dest, "", 15);
		// ft_print_result(ft_strlcpy(dest, "", 15));
		// write(1, "\n", 1);
		// write(1, dest, 15);
		// printf("\n%s", dest);
	}
	else if (atoi(argv[1]) == 3)
	{
		check_strlcpy(dest, "lorem ipsum", 3);
		// ft_print_result(ft_strlcpy(dest, "lorem ipsum", 3));
		// write(1, "\n", 1);
		// write(1, dest, 15);
		// printf("\n%s", dest);
	}
	else if (atoi(argv[1]) == 4)
	{
		check_strlcpy(dest, "lorem ipsum dolor sit amet", 15);
		// ft_print_result(ft_strlcpy(dest, "lorem ipsum dolor sit amet", 15));
		// write(1, "\n", 1);
		// write(1, dest, 15);
		// printf("\n%s", dest);
	}
	else if (atoi(argv[1]) == 5)
	{
		check_strlcpy(dest, "lorem ipsum dolor sit amet", 0);
		// ft_print_result(ft_strlcpy(dest, "lorem ipsum dolor sit amet", 0));
		// write(1, "\n", 1);
		// write(1, dest, 15);
		// printf("\n%s", dest);
	}
	else if (atoi(argv[1]) == 6)
	{
		memset(dest, 'A', 10);
		check_strlcpy(dest, "coucou", 6);
		// x = strlcpy(dest, "coucou", 6);
		// printf("%s\n", (x == strlen("coucou")) ? "deu bom" : "deu ruim");
		// printf("saida = '%s'(%ld)\n", dest, strlen(dest));
		// printf("lego\n");
	}
	else if (atoi(argv[1]) == 7)
	{
		memset(dest, 'A', 10);
		check_strlcpy(dest, "coucou", -1);
	}
	return (0);
}
