/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpassos- <gpassos-@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 08:29:49 by gpassos-          #+#    #+#             */
/*   Updated: 2021/02/18 08:29:52 by gpassos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_strlcpy_p(char *dest, const char *src, size_t size)
{
	int		i;

	i = 0;
	while (*((char *)src + i) != '\0' && i < ((int)size - 1))
	{
		*(dest + i) = *(src + i);
		i++;
	}
	*(dest + i) = '\0';
	return (ft_strlen(src));
}

size_t			ft_strlcpy(char *dest, const char *src, size_t size)
{
	if (dest == NULL || src == NULL)
		return (0);
	if (size == 0)
		return (ft_strlen(src));
	else if ((int)size < 0)
		return (ft_strlcpy_p(dest, src, ft_strlen(src) + 1));
	else
		return (ft_strlcpy_p(dest, src, size));
}
