/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memcpy.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 14:19:02 by gabriel           #+#    #+#             */
/*   Updated: 2021/02/13 12:43:30 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include "../libft.h"

int	main(void)
{
	char	src[50];
	char	dest[50];

	strcpy(src, "Heloo!! como vai vc");
	strcpy(dest, "Heloooo!!");
	printf("Before memcpy dest = %s\n", dest);
	memcpy(dest, src, strlen(src) + 1);
	printf("After memcpy dest = %s\n", dest);
	strcpy(src, "Heloo!! como vai vc");
	strcpy(dest, "Heloooo!!");
	printf("Before ft_memcpy dest = %s\n", dest);
	ft_memcpy(dest, src, strlen(src) + 1);
	printf("After ft_memcpy dest = %s\n", dest);
	ft_memcpy(NULL, NULL, 3);
	// ft_memcpy((NULL), "segfaulter tu dois", 17);
	// ft_memcpy("            ", (NULL), 17);
	printf("saida = %p\n", memcpy(NULL, NULL, 3));
	printf("saida = %p\n", ft_memcpy(NULL, NULL, 3));
}
