/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 14:25:10 by gabriel           #+#    #+#             */
/*   Updated: 2021/03/07 18:41:27 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <string.h>

// #ifndef BUFFER_SIZE
// # define BUFFER_SIZE 32
// #endif

size_t	ft_strlen(const char *s);

int	main(void)
{
	int fd;
	char *linha;
	int i;
	int retorno;

	i = 0;
	// fd = 123;
	fd = open("normal.txt", O_RDONLY);
	retorno = 1;
	while (retorno == 1)
	{
		retorno = get_next_line(fd, &linha);
		if (retorno != 1)
			break;
		printf("1: linha[%d] = '%s'(%ld); retorno = %i\n", i, linha, strlen(linha), retorno);
		free(linha);
		i++;
		// break;
	}
	if (retorno != -1)
	{
		printf("2: linha[%d] = '%s'(%ld); retorno = %i\n", i, linha, strlen(linha), retorno);
		free(linha);
	}
	else
		printf("get_next_line retornou -1\n");
	return (0);
}
