/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isalnum.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 12:54:28 by gabriel           #+#    #+#             */
/*   Updated: 2021/02/08 13:38:56 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "../libft.h"

int main(void)
{
	int i;

    printf("TEST ENTER\n");
	i = -1;
	while (i < 530)
	{
		// if((i > 255) && (isalnum(i) != 0))
			printf("c(%i) = '%c'; ft_isalnum? = %i; isalnum? = %i\n", i, (char)i, ft_isalnum(i), isalnum(i));
			// printf("(%i == i) || ", (i));
		if (!!isalnum(i) != !!isalnum(i)) {
			printf("TEST_FAILED"); return (0); }
		i++;
    }
    printf("TEST_SUCCESS");

	return (0);
}