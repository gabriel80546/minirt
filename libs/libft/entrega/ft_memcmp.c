/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpassos- <gpassos-@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 10:58:04 by gpassos-          #+#    #+#             */
/*   Updated: 2021/02/17 10:58:06 by gpassos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	int				contador;
	unsigned char	left;
	unsigned char	right;

	contador = 0;
	while (contador < (int)n)
	{
		left = *((unsigned char *)s1 + contador);
		right = *((unsigned char *)s2 + contador);
		if (left != right)
			return (left - right);
		contador++;
	}
	return (0);
}
