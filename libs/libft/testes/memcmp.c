/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memcmp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 08:50:50 by gabriel           #+#    #+#             */
/*   Updated: 2021/02/04 11:18:24 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include "../libft.h"

int	main(void)
{
	char	str1[15];
	char	str2[15];
	int		ret;

	memcpy(str1, "abcdeg", 6);
	memcpy(str2, "ABCDEF", 6);
	ret = memcmp(str1, str2, 5);
	if (ret > 0)
		printf("str2 is less than str1\n");
	else if (ret < 0)
		printf("str1 is less than str2\n");
	else
		printf("str1 is equal to str2\n");
	ret = ft_memcmp(str1, str2, 5);
	if (ret > 0)
		printf("str2 is less than str1\n");
	else if (ret < 0)
		printf("str1 is less than str2\n");
	else
		printf("str1 is equal to str2\n");
	return (0);
}
