/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpassos- <gpassos-@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 10:58:32 by gpassos-          #+#    #+#             */
/*   Updated: 2021/02/17 10:58:34 by gpassos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	int contador;

	if (s == NULL)
		return ;
	contador = 0;
	while (*(s + contador) != '\0')
	{
		ft_putchar_fd(*(s + contador), fd);
		contador++;
	}
}
