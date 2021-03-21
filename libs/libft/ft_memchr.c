/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpassos- <gpassos-@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 10:57:59 by gpassos-          #+#    #+#             */
/*   Updated: 2021/02/17 10:58:02 by gpassos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	contador;
	char	*saida;

	saida = (char *)s;
	contador = 0;
	while (contador < n)
	{
		if (*(saida) == (char)c)
			return (saida);
		saida++;
		contador++;
	}
	return (NULL);
}
