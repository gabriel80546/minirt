/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bzero.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 11:12:29 by gabriel           #+#    #+#             */
/*   Updated: 2021/02/02 16:51:58 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include "../libft.h"
#include "bzero.h"

int		main(void)
{
	char	str[50];
	int		contador;

	strcpy(str, "This is string.h library function");
	contador = 0;
	while (contador < 50)
	{
		printf("%c", (*(str + contador)));
		contador++;
	}
	putchar('\n');
	main_two();
}

void	main_two(void)
{
	char	str[50];
	int		contador;

	ft_bzero(str, 50);
	strcpy(str, "This is string.h library function");
	contador = 0;
	while (contador < 50)
	{
		printf("%c", (*(str + contador)));
		contador++;
	}
	putchar('\n');
	ft_bzero(str, 7);
	contador = 0;
	while (contador < 50)
	{
		printf("%c", (*(str + contador)));
		contador++;
	}
	putchar('\n');
	puts(str);
}
