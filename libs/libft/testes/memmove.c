/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memmove.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 07:39:48 by gabriel           #+#    #+#             */
/*   Updated: 2021/02/11 19:40:18 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include "../libft.h"
#include <stdlib.h>
#include <unistd.h>


int	main_old(void)
{
	char		destino[50];
	const char	source[] = "newstring";

	strcpy(destino, "oldstring");
	printf("Before memmove destino = %s, source = %s\n", destino, source);
	memmove(destino, source, 9);
	printf("After memmove destino = %s, source = %s\n", destino, source);
	strcpy(destino, "oldstring");
	printf("Before ft_memmove destino = %s, source = %s\n", destino, source);
	ft_memmove(destino, source, 9);
	printf("After ft_memmove destino = %s, source = %s\n", destino, source);



	printf("$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n");
	printf("$@##@#@#@##@#@#@#@#@#@#@###@@@#@#@#@#@#@#@#@#@#@#@$\n");
	printf("$#@#@#@#@#@#@#@#@#@#@#@ Parte 2 @#@#@#@#@#@#@#@#@#$\n");
	printf("$#@@@#@#@#@@@@##@#@#@#@#@##@@@@#@#@#@#@@@@#@#@@@@#$\n");
	printf("$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n");


	char	src[] = "lorem ipsum dolor sit amet";
	char	*dest;
	int		arg;

	dest = src + 1;

	dest = memmove(dest, "consectetur", 5);
	printf("%s\n", dest);
	dest = src + 1;
	dest = memmove(dest, "con\0sec\0\0te\0tur", 10);
	printf("%s\n", dest);
	dest = src + 1;
	dest = memmove(dest, src, 8);
	printf("%s\n", dest);
	dest = src + 1;
	dest = memmove(src, dest, 8);
	printf("%s\n", dest);
	dest = src + 1;
	dest = memmove(src, dest, 0);
	printf("%s\n", dest);

	printf("$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n");
	printf("$@##@#@#@##@#@#@#@#@#@#@###@@@#@#@#@#@#@#@#@#@#@#@$\n");
	printf("$#@#@#@#@#@#@#@#@#@#@#@ Parte 3 @#@#@#@#@#@#@#@#@#$\n");
	printf("$#@@@#@#@#@@@@##@#@#@#@#@##@@@@#@#@#@#@@@@#@#@@@@#$\n");
	printf("$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n");


	dest = src + 1;
	dest = memmove(dest, "consectetur", 5);
	printf("%s\n", dest);
	dest = src + 1;
	dest = memmove(dest, "con\0sec\0\0te\0tur", 10);
	printf("%s\n", dest);
	dest = src + 1;
	printf("antes tava assim => (%s)\n", (dest == 0) ? "(NULL)" : (char *)dest);
	printf("antes tava assim => (%s)\n", (src == 0) ? "(NULL)" : (char *)src);
	dest = memmove(dest, src, 8);
	printf("%s\n", dest);
	dest = src + 1;
	dest = memmove(src, dest, 8);
	printf("%s\n", dest);
	dest = src + 1;
	dest = memmove(src, dest, 0);
	printf("%s\n", dest);

	printf("$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n");
	printf("$@##@#@#@##@#@#@#@#@#@#@###@@@#@#@#@#@#@#@#@#@#@#@$\n");
	printf("$#@#@#@#@#@#@#@#@#@#@#@ Parte 4 @#@#@#@#@#@#@#@#@#$\n");
	printf("$#@@@#@#@#@@@@##@#@#@#@#@##@@@@#@#@#@#@@@@#@#@@@@#$\n");
	printf("$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n");


	dest = src + 1;
	dest = ft_memmove(dest, "consectetur", 5);
	printf("%s\n", dest);
	dest = src + 1;
	dest = ft_memmove(dest, "con\0sec\0\0te\0tur", 10);
	printf("%s\n", dest);
	dest = src + 1;
	printf("antes tava assim => (%s)\n", (dest == 0) ? "(NULL)" : (char *)dest);
	printf("antes tava assim => (%s)\n", (src == 0) ? "(NULL)" : (char *)src);
	dest = ft_memmove(dest, src, 8);
	printf("%s\n", dest);
	dest = src + 1;
	dest = ft_memmove(src, dest, 8);
	printf("%s\n", dest);
	dest = src + 1;
	dest = ft_memmove(src, dest, 0);
	printf("%s\n", dest);


	int size = 128 * 1024 * 1024;
	char *dst = (char *)malloc(sizeof(char) * size);
	char *data = (char *)malloc(sizeof(char) * size);

	memset(data, 'A', size);
	if (!dst) {
		printf("TEST_INVISIBLE"); return (0); }
	ft_memmove(dst, data, size);
	printf("TEST_SUCCESS"); return (0);



	return (0);
}
// printf("antes tava assim => (%s)\n", (mem == 0) ? "(NULL)" : (char *)mem);


// src  = lcon							<= estava assim antes
// dest = con							<= estava assim antes
// dest = ft_memmove(dest, src, 8)		<= argumentos passados
// dest = lcon							<= valor esperado
// dest = con							<= valor retornado

static void		check_memmove(void *dest, void *src, int n)
{
	if (dest != ft_memmove(dest, src, n))
		write(1, "dest's adress was not returned\n", 31);
	write(1, dest, 22);
}

int				main(int argc, const char *argv[])
{
	char	src[] = "lorem ipsum dolor sit amet";
	char	*dest;
	int		arg;

	dest = src + 1;
	alarm(5);
	if (argc == 1)
		return (0);
	else if ((arg = atoi(argv[1])) == 1)
		check_memmove(dest, "consectetur", 5);
	else if (arg == 2)
		check_memmove(dest, "con\0sec\0\0te\0tur", 10);
	else if (arg == 3)
		check_memmove(dest, src, 8);
	else if (arg == 4)
		check_memmove(src, dest, 8);
	else if (arg == 5)
		check_memmove(src, dest, 0);
	return (0);
}
