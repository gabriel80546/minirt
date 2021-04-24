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

const void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	contador;
	size_t	i;
	const char	*saida;

	saida = s;
	contador = 0;
	i = 0;
	while (contador < n)
	{
		if (*(saida + i) == (char)c)
			return (const void *)((const char *)saida + i);
		i++;
		contador++;
	}
	return (NULL);
}
