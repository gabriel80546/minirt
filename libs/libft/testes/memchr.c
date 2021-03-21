/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memchr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 08:01:49 by gabriel           #+#    #+#             */
/*   Updated: 2021/02/04 10:50:23 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../libft.h"

int	main(void)
{
	const char	str[] = "test_string";
	const char	ch = '_';
	char		*ret_one;
	char		*ret_two;

	printf("test string is \"%s\"\n", str);
	ret_one = memchr(str, ch, strlen(str));
	printf("String after '%c' is \"%s\"\n", ch, ret_one);
	printf("test string is \"%s\"\n", str);
	ret_two = ft_memchr(str, ch, strlen(str));
	printf("String after '%c' is \"%s\"\n", ch, ret_two);


	void	*mem;
	void	*copia;

	mem = (void *)malloc(30);
	copia = mem;

	printf("%s\n", (mem == 0) ? "(NULL)" : (char *)mem);
	if(mem != copia) { mem = copia; }
	memset(mem, 'j', 30);
	mem = memchr("bonjour", 'b', 4);
	printf("%s\n", (mem == 0) ? "(NULL)" : (char *)mem);
	if(mem != copia) { mem = copia; }
	memset(mem, 'j', 30);
	mem = memchr("bonjour", 'o', 7);
	printf("%s\n", (mem == 0) ? "(NULL)" : (char *)mem);
	if(mem != copia) { mem = copia; }
	memset(mem, 'j', 30);
	mem = memchr("bonjourno", 'n', 2);
	printf("%s\n", (mem == 0) ? "(NULL)" : (char *)mem);
	if(mem != copia) { mem = copia; }
	memset(mem, 'j', 30);
	mem = memchr("bonjour", 'j', 6);
	printf("%s\n", (mem == 0) ? "(NULL)" : (char *)mem);
	if(mem != copia) { mem = copia; }
	memset(mem, 'j', 30);
	mem = memchr("bonjour", 's', 7);
	printf("%s\n", (mem == 0) ? "(NULL)" : (char *)mem);
	if(mem != copia) { mem = copia; }
	memset(mem, 'j', 30);



	printf("$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n");
	printf("$@##@#@#@##@#@#@#@#@#@#@###@@@#@#@#@#@#@#@#@#@#@#@$\n");
	printf("$#@#@#@#@#@#@#@#@#@#@#@ Parte 2 @#@#@#@#@#@#@#@#@#$\n");
	printf("$#@@@#@#@#@@@@##@#@#@#@#@##@@@@#@#@#@#@@@@#@#@@@@#$\n");
	printf("$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n");

	// printf("%s\n", (mem == 0) ? "(NULL)" : (char *)mem);
	if(mem != copia) { mem = copia; }
	memset(mem, 'j', 30);
	mem = ft_memchr("bonjour", 'b', 4);
	printf("%s\n", (mem == 0) ? "(NULL)" : (char *)mem);
	if(mem != copia) { mem = copia; }
	memset(mem, 'j', 30);
	mem = ft_memchr("bonjour", 'o', 7);
	printf("%s\n", (mem == 0) ? "(NULL)" : (char *)mem);
	if(mem != copia) { mem = copia; }
	memset(mem, 'j', 30);
	mem = ft_memchr("bonjourno", 'n', 2);
	printf("%s\n", (mem == 0) ? "(NULL)" : (char *)mem);
	if(mem != copia) { mem = copia; }
	memset(mem, 'j', 30);
	mem = ft_memchr("bonjour", 'j', 6);
	printf("%s\n", (mem == 0) ? "(NULL)" : (char *)mem);
	if(mem != copia) { mem = copia; }
	memset(mem, 'j', 30);
	mem = ft_memchr("bonjour", 's', 7);
	printf("%s\n", (mem == 0) ? "(NULL)" : (char *)mem);
	if(mem != copia) { mem = copia; }
	memset(mem, 'j', 30);

	return (0);
}

// printf("antes tava assim => (%s)\n", (mem == 0) ? "(NULL)" : (char *)mem);
