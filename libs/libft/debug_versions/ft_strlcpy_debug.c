/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 10:59:01 by gpassos-          #+#    #+#             */
/*   Updated: 2021/02/18 07:27:44 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_strlcpy_p(char *dst, const char *src, size_t size)
{
	size_t	contador;
	int		zero;

	zero = 0;
	contador = 0;
	while (*((char *)src + contador) != '\0')
	{
		if (contador < size)
			*((char *)dst + contador) = *((char *)src + contador);
		else if (contador == size)
		{
			zero = 1;
			*((char *)dst + contador - 1) = '\0';
		}
		contador++;
	}
	
	if (zero == 0)
		*((char *)dst + contador) = '\0';
	return (contador);
}

size_t			ft_strlcpy(char *dst, const char *src, size_t size)
{
	if (dst == NULL || src == NULL)
		return (0);
	if (size == 0)
		return (ft_strlen(src));
	return (ft_strlcpy_p(dst, src, size));
}
