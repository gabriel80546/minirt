/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat_debug.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 09:47:40 by gabriel           #+#    #+#             */
/*   Updated: 2021/02/18 08:32:50 by gpassos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

size_t			ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	dest_l;
	size_t	src_l;
	int		j;
	// size_t	loop;
	// size_t	saida;


	dest_l = ft_strlen(dest);
	src_l = ft_strlen(src);

	// int x;
	// int at_most;
	// char *join;
	// char *jointwo;
	// int i;
	int temp;


	// join = (char *)malloc(sizeof(char) * (strlen(dest) + strlen(src)));
	// jointwo = (char *)malloc(sizeof(char) * (strlen(dest) + strlen(src)));
	// printf("dest = '%s'(%ld)\n", dest, strlen(dest));
	// printf("src = '%s'(%ld)\n", src, strlen(src));
	// printf("size = %d\n", size);

	// printf("\n---------------\n");

	// printf("saida seria a concatenação de '%s'(%ld) e '%s'(%ld)\n", dest, strlen(dest), src, strlen(src));
	// printf("que é '%s%s'(%ld)\n", dest, src, strlen(dest) + strlen(src));
	// printf("mas size(%ld) é menor ou igual a concatenacao(%ld)? %s\n", size, strlen(dest) + strlen(src),  (size <= (strlen(dest) + strlen(src))) ? "sim" : "nao" );
	if (size <= (strlen(dest) + strlen(src)))
	{
		// printf("merda :( entao não posso concatenar tudo\n");
		// sprintf(join, "%s%s", dest, src);

		temp = (size - 1);
		temp = (temp < 0) ? 0 : temp;
		// printf("mas o tamanho do (dest)(%ld) é maior que max((size - 1), 0)(%d)? %s\n", strlen(dest), temp, ((int)strlen(dest) > temp) ? "sim" : "nao");
		if((int)strlen(dest) > (int)temp)
		{
			// printf("entao não posso usar um pouco do src\n");
			// printf("vai ter que ser o mesmo que (dest) '%s'(%ld)\n", dest, strlen(dest));
			// printf("saida tipo 3 entao retorna s+s => %ld\n", strlen(src) + size);
			return (src_l + size);
		}
		else
		{
			// printf("entao posso usar um pouco do src totalizando max((size - 1), 0) => %d\n", temp);

			// i = 0;
			// while (i < temp)
			// {
			// 	*(jointwo + i) = *(join + i);
			// 	i++;
			// }
			// *(jointwo + i) = '\0';
			// jointwo = ft_substr(join, 0, (size - 1));



			j = (size - 1);
			// printf("j = %i\n", j);
			j = ((j > 0) ? j : 0);
			// printf("j = %i\n", j);

			i = dest_l;

			while ((int)i < j)
			{
				*((char *)dest + i) = *((char *)src + i - dest_l);
				i++;

			}

	// printf("fui ate aqui\n");
	// return (0);
			*((char *)dest + i) = '\0';



			// printf("que é '%s'%d\n", jointwo, strlen(jointwo));
			// printf("saida tipo 2 entao retorna d+s => %ld\n", dest_l + src_l);
			return (dest_l + src_l);
		}
		
	}
	else
	{

		// printf("legal (: então eu posso concatenar tudo\n");
		// printf("resultando em '%s%s'(%ld)\n", dest, src, strlen(dest) + strlen(src));
		// printf("saida tipo 1 entao retorna d+s => %ld\n", strlen(dest) + strlen(src));
		i = 0;
		while (i < src_l)
		{
			*((char *)dest + i + dest_l) = *((char *)src + i);
			i++;
		}
		*((char *)dest + i + dest_l) = '\0';

		return (dest_l + src_l);
	}

	// printf("---------------\n\n");


	// x = strlcat(dest, src, size);
	// printf("saida = %d\n", x);
	// printf("dest = '%s'(%ld)\n", dest, strlen(dest));
}

size_t			ft_strlcat_old(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	dest_s;
	size_t	src_s;
	char	atual;

	dest_s = ft_strlen(dest);
	src_s = ft_strlen(src);
	if (size < (dest_s + 1))
		return (size + src_s);
	i = 0;
	atual = *(src + i);
	while (atual != '\0' && (size > (dest_s + 2)) && ((i + dest_s + 1) < size))
	{
		if (i > (dest_s + 1) && (dest_s > 0))
			break ;
		*(dest + i + dest_s) = atual;
		i++;
		atual = *(src + i);
	}
	*(dest + i + dest_s) = '\0';
	return (dest_s + src_s);
}


size_t		ft_strlcat_older(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	dest_l;
	size_t	src_l;

	dest_l = ft_strlen(dest);
	src_l = ft_strlen(src);
	if (dest_l >= size)
		return (src_l + size);
	
	i = (size <= dest_l + src_l) ? dest_l : 0;
	if (size <= dest_l + src_l)
	{
		while ((int)i < ft_max(((int)size - 1), 0))
		{
			*((char *)dest + i) = *((char *)src + i - dest_l);
			i++;
		}
		*((char *)dest + i) = '\0';
	}
	else
	{
		while (i < src_l)
		{
			*((char *)dest + i + dest_l) = *((char *)src + i);
			i++;
		}
		*((char *)dest + i + dest_l) = '\0';
	}
	return (dest_l + src_l);
}

size_t		ft_strlcat_oldest(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	dest_l;
	size_t	src_l;

	dest_l = ft_strlen(dest);
	src_l = ft_strlen(src);
	if (dest_l >= size)
		return (src_l + size);
	i = (size <= dest_l + src_l) ? dest_l : 0;
	while (1)
	{
		if (size <= dest_l + src_l)
		{
			if(!((int)i < ft_max(((int)size - 1), 0)))
				break ;
			*((char *)dest + i) = *((char *)src + i - dest_l);
		}
		else
		{
			if(!(i < src_l))
				break ;
			*((char *)dest + i + dest_l) = *((char *)src + i - dest_l);
		}
		i++;
	}
	if (size <= dest_l + src_l)
		*((char *)dest + i) = '\0';
	else
		*((char *)dest + i + dest_l) = '\0';
	return (dest_l + src_l);
}
