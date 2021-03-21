/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpassos- <gpassos-@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 08:30:46 by gpassos-          #+#    #+#             */
/*   Updated: 2021/02/18 08:30:49 by gpassos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	ft_min(int a, int b)
{
	if (a > b)
		return (b);
	else
		return (a);
}

char		*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*saida;
	size_t	contador;
	size_t	s_len;
	int		alocar;

	if (s == NULL)
		return (NULL);
	s_len = ft_strlen(s);
	alocar = ((start >= s_len) ? 1 : ft_min(s_len + 1, len + 1));
	saida = (char *)malloc(sizeof(char) * alocar);
	if (saida == NULL)
		return (NULL);
	if (start > s_len)
	{
		*(saida + 0) = '\0';
		return (saida);
	}
	contador = start;
	while ((contador < (start + len)) && (contador < s_len))
	{
		*(saida + (contador - start)) = *((char *)s + contador);
		contador++;
	}
	*(saida + (contador - start)) = '\0';
	return (saida);
}
