/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpassos- <gpassos-@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 10:57:50 by gpassos-          #+#    #+#             */
/*   Updated: 2021/02/17 10:57:52 by gpassos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

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
