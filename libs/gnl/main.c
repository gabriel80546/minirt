/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 14:25:10 by gabriel           #+#    #+#             */
/*   Updated: 2021/02/28 21:18:43 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <string.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 32
#endif

static int	ft_itoa_log(long n)
{
	int contador;
	int temp;

	contador = 0;
	if (n < 0)
	{
		contador++;
		n = -n;
	}
	temp = n;
	while (n > 9)
	{
		n = n / 10;
		contador++;
	}
	n = temp;
	contador++;
	return (contador + 1);
}

static char	*ft_itoa_overfl(void)
{
	char	*saida;

	saida = (char *)malloc(sizeof(char) * 12);
	*(saida + 0) = '-';
	*(saida + 1) = '2';
	*(saida + 2) = '1';
	*(saida + 3) = '4';
	*(saida + 4) = '7';
	*(saida + 5) = '4';
	*(saida + 6) = '8';
	*(saida + 7) = '3';
	*(saida + 8) = '6';
	*(saida + 9) = '4';
	*(saida + 10) = '8';
	*(saida + 11) = '\0';
	return (saida);
}

char		*ft_itoa(int n)
{
	char	*saida;
	int		contador;

	if (n == -2147483648LL)
		return (ft_itoa_overfl());
	saida = (char *)malloc(sizeof(char) * ft_itoa_log(n));
	if (saida == NULL)
		return (NULL);
	*(saida + 0) = '-';
	contador = (ft_itoa_log(n) - 1);
	n = (n < 0) ? (-n) : n;
	*(saida + contador) = '\0';
	while (n > 9)
	{
		*(saida + contador - 1) = (n % 10) + '0';
		n = (n / 10);
		contador--;
	}
	*(saida + contador - 1) = (n % 10) + '0';
	return (saida);
}

// size_t	ft_strlen(const char *s)
// {
// 	int	contador;

// 	if (s == NULL)
// 		return (0);
// 	contador = 0;
// 	while (*(s + contador) != '\0')
// 		contador++;
// 	return (contador);
// }

size_t	ft_strlen(const char *s);

int	main(void)
{
	int fd;
	char *linha;
	int i;
	int retorno;

	i = 0;
	fd = open("antigo.txt", O_RDONLY);
	while ((retorno = get_next_line(fd, &linha) == 1) && (i < 1 || 1))
	{
		printf("linha[%d] = '%s'(%ld); retorno = %i\n", i, linha, strlen(linha), retorno);
		free(linha);
		i++;
		// break;
	}
	if (retorno != -1)
	{
		printf("linha[%d] = '%s'(%ld); retorno = %i\n", i, linha, strlen(linha), retorno);
		free(linha);
	}
	return (0);
}

// while (read(fd, buffer, BUFFER_SIZE) > 0)
// {
// 	printf("buffer = '%s'\n", buffer);
// }
// printf("buffer = '%s'\n", buffer);