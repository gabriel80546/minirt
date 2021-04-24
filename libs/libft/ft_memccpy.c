/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpassos- <gpassos-@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 10:57:54 by gpassos-          #+#    #+#             */
/*   Updated: 2021/02/17 10:57:56 by gpassos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (*((const char *)src + i) == (char)c)
		{
			*((unsigned char *)dest + i) = *((const unsigned char *)src + i);
			return ((char *)dest + i + 1);
		}
		*((unsigned char *)dest + i) = *((const unsigned char *)src + i);
		i++;
	}
	return (NULL);
}
