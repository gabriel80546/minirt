/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memset.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 11:12:29 by gabriel           #+#    #+#             */
/*   Updated: 2021/02/03 07:12:17 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include "../libft.h"

int	main(void)
{
	char	str[50];
	int		numero;

	strcpy(str, "This is string.h library function");
	puts(str);
	memset(str, '$', 7);
	puts(str);
	strcpy(str, "This is string.h library function");
	puts(str);
	ft_memset(str, '$', 7);
	puts(str);
	return (0);
}
