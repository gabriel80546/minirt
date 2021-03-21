/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpassos- <gpassos-@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 10:59:22 by gpassos-          #+#    #+#             */
/*   Updated: 2021/02/17 10:59:23 by gpassos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*saida;
	char	*last_find;

	last_find = NULL;
	saida = (char *)s;
	while (*(saida) != '\0')
	{
		if (*(saida) == (char)c)
			last_find = saida;
		saida++;
	}
	if (last_find == NULL && c == 0)
		return (saida);
	else if (last_find == NULL)
		return (NULL);
	else if (*(last_find) == (char)c)
		return (last_find);
	else
		return (NULL);
}
