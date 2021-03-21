/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpassos- <gpassos-@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 10:58:56 by gpassos-          #+#    #+#             */
/*   Updated: 2021/02/17 10:58:58 by gpassos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_max(int a, int b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

static void	ft_strlcat_tudo(char *dest, const char *src, size_t dl, size_t sl)
{
	size_t	i;

	i = 0;
	while (i < sl)
	{
		*((char *)dest + i + dl) = *((char *)src + i);
		i++;
	}
	*((char *)dest + i + dl) = '\0';
}

static void	ft_strlcat_part(char *dest, const char *src, size_t dl, size_t s)
{
	size_t	i;
	int		temp;

	temp = ft_max(((int)s - 1), 0);
	i = dl;
	while ((int)i < temp)
	{
		*((char *)dest + i) = *((char *)src + i - dl);
		i++;
	}
	*((char *)dest + i) = '\0';
}

size_t		ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	dest_l;
	size_t	src_l;

	dest_l = ft_strlen(dest);
	src_l = ft_strlen(src);
	if (dest_l >= size)
		return (src_l + size);
	if (size <= dest_l + src_l)
		ft_strlcat_part(dest, src, dest_l, size);
	else
		ft_strlcat_tudo(dest, src, dest_l, src_l);
	return (dest_l + src_l);
}
