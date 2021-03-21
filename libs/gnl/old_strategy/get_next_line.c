/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 14:06:33 by gpassos-          #+#    #+#             */
/*   Updated: 2021/02/25 14:36:52 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../get_next_line.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/resource.h>
// #include "libft/libft.h"

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 32
#endif

// int printf (const char * fmt, ...)
// {
// 	if (fmt[0] == 7)
// 		return (1);
// 	else
// 		return (0);
// }

size_t	ft_strlen(const char *s)
{
	int	contador;

	contador = 0;
	while (*(s + contador) != '\0')
		contador++;
	return (contador);
}

static size_t	safe_strlen(const char *s)
{
	return (s == NULL) ? 0 : ft_strlen(s);
}

char	*ft_strchr(const char *s, int c)
{
	char	*saida;

	saida = (char *)s;
	while (*(saida) != (char)c && *(saida) != '\0')
	{
		saida++;
	}
	if (*(saida) == (char)c)
		return (saida);
	else
		return (NULL);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	contador;

	if (dest == NULL && src == NULL)
		return (NULL);
	contador = 0;
	while (contador < n)
	{
		*((char *)dest + contador) = *((char *)src + contador);
		contador++;
	}
	return (dest);
}


void	*ft_memset(void *s, int c, size_t n)
{
	size_t	contador;

	contador = 0;
	while (contador < n)
	{
		*((unsigned char *)s + contador) = (unsigned char)c;
		contador++;
	}
	return (s);
}



int				get_next_line(int fd, char **line)
{
	// static char	buffer[BUFFER_SIZE + 1];
	static char	*buffer;
	static int	line_number = 0;
	static int	last_offset = 0;
	// char		buftemporario[BUFFER_SIZE + 1];
	char		*buftemporario;
	char		*temp_line;
	int			i;
	int			j;
	int			vazio;
	int			tinha;
	int			read_saida;

	int debug = 0;
	debug = 1;
	debug = 0;

	vazio = 0;
	tinha = 0;

	if(BUFFER_SIZE <= 0 || fd < 0 || line == NULL || fd > RLIMIT_NOFILE)
	{
		if(debug == 1) { printf("118: BUFFER_SIZE = %i, fd = %i, line = %p\n", BUFFER_SIZE, fd, line); }
		if(debug == 1) { printf("119: retorno -1\n"); }
		return (-1);
	}

	if(debug == 1) { printf("123: antes do malloc\n"); }
	// *(line + line_number) = (char *)malloc(sizeof(char) * 10000);
	if (BUFFER_SIZE > 10000)
		temp_line = (char *)malloc(sizeof(char) * BUFFER_SIZE);
	else
		temp_line = (char *)malloc(sizeof(char) * 10000);
	if (temp_line == NULL)
		return (-1);

	buftemporario = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buftemporario == NULL)
		return (-1);
	ft_memset(buftemporario, '\0', BUFFER_SIZE + 1);
	if (line_number == 0)
	{
		buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (buffer == NULL)
			return (-1);
		ft_memset(buffer, '\0', BUFFER_SIZE + 1);
	}


	if(debug == 1) { printf("142: bora porra, pega a linha %i\n", line_number); }
	// if (line_number == 0)
	// 	ft_memset(buffer, vazio, BUFFER_SIZE + 1);
	if(debug == 1) { printf("145: last_offset = %i\n", last_offset); }

	i = 0;
	while (i < BUFFER_SIZE)
	{
		if (buffer[i] != vazio)
		{
			if(debug == 1) { printf("152: buffer[%i] tem lixo = %i  \t'%c'\n", i, buffer[i], buffer[i]); }
			tinha = 1;
		}
		else
		{
			// if(debug == 1) { printf("157: buffer[%i] = %i\t'%c'\n", i, buffer[i], buffer[i]); }
		}
		i++;
	}




	i = 0;
	j = 0;
	while (1)
	{
		if(debug == 1) { printf("166: i já está = %i\n", i); }
		if(debug == 1) { printf("167: tinha algo no buffer? %s\n", (tinha) ? "sim" : "nao"); }
		if (tinha == 0)
		{
			if(debug == 1) { printf("170: entao vou usar o read\n"); }
			read_saida = read(fd, buffer, BUFFER_SIZE);
			buffer[BUFFER_SIZE] = '\0';
		}
		else
		{
			if(debug == 1) { printf("176: entao não vou usar o read\n"); }
			read_saida = BUFFER_SIZE + 1;
		}
		tinha = 0;

		if(read_saida < 0 || read_saida > BUFFER_SIZE + 1)
			return (-1);

		if(debug == 1) { printf("184: read nem leu nada? %s\n", (read_saida == 0) ? "sim" : "nao"); }
		if (read_saida == 0)
		{
			if(debug == 1) { printf("187: então ja acabou\n"); }
			j = 0;
			while (j < BUFFER_SIZE)
			{
				// if(debug == 1) { printf("191: buffer[%i] = '%c' =\t%d\n", j, buffer[j], buffer[j]); }
				j++;
			}
			*(temp_line + i) = '\0';
			if(debug == 1) { printf("195: temp_line = '%s'(%ld)\n", temp_line, safe_strlen(temp_line)); }
			if(debug == 1) { printf("196: i = %i; j = %i; i + j = %i\n", i, j, i + j); }
			line_number++;
			if(debug == 1) { printf("198: retorno 0\n"); }
			*line = temp_line;
			return (0);
		}

		if(debug == 1) { printf("203: read leu tudo? %s\n", (read_saida == BUFFER_SIZE) ? "sim" : "nao"); }
		if (read_saida == BUFFER_SIZE)
		{
			if(debug == 1) { printf("205: então EOF está longe\n"); }

			if(debug == 1) { printf("208: tem '\\n' nesse buffer? %s\n", (ft_strchr(buffer, '\n') != NULL) ? "sim" : "nao"); }
			if (ft_strchr(buffer, '\n') != NULL)
			{
				if(debug == 1) { printf("211: tem quebra de linha nessa porra\n"); }
				if(debug == 1) { printf("212: buffer = '%s'(%ld)\n", buffer, safe_strlen(buffer)); }
				if(debug == 1) { printf("213: vou ter que escrever só parte\n"); }
				j = 0;
				while (j < BUFFER_SIZE)
				{
					if (buffer[j] == '\n')
						break ;
					*(temp_line + j + i) = buffer[j];
					buffer[j] = 0;
					j++;
				}
				last_offset = j + 1;
				if(debug == 1) { printf("224: last offset é %i\n", j); }
				if(debug == 1) { printf("225: last offset é %i\n", last_offset); }
				if(debug == 1) { printf("226: buffer[last_offset] = %i\n", buffer[last_offset]); }
				if(debug == 1) { printf("227: buffer[last_offset] = '%c'\n", buffer[last_offset]); }
				*(temp_line + j + i) = '\0';
				buffer[j] = 0;
				line_number++;
				if(debug == 1) { printf("231: retorno 1\n"); }
				*line = temp_line;
				return (1);
			}
			else
			{
				if(debug == 1) { printf("237: não tem quebra de linha nessa disgraça\n"); }
				if(debug == 1) { printf("238: buffer = '%s'(%ld); i = %d\n", buffer, safe_strlen(buffer), i); }
				j = 0;
				while (j < BUFFER_SIZE)
				{
					*(temp_line + j + i) = buffer[j];
					buffer[j] = 0;
					j++;
				}
				i += j;
			}
		}
		else if (read_saida == (BUFFER_SIZE + 1))
		{
			if(debug == 1) { printf("251: na verdade nem teve read. já tinha coisa nesse buffer\n"); }



			ft_memcpy(buftemporario, buffer, BUFFER_SIZE + 1);
			j = 0;
			while (j < BUFFER_SIZE)
			{
				if (buffer[j] == 0)
					buftemporario[j] = ' ';
				else
					buftemporario[j] = buffer[j];
				j++;
			}
			buftemporario[j] = '\0';
			if(debug == 1) { printf("266: buftemporario = '%%s'(%ld)\n", /*buftemporario,*/ safe_strlen(buftemporario)); }

			if(debug == 1) { printf("268: tem '\\n' nesse buffer? %s\n", (ft_strchr(buftemporario, '\n') != NULL) ? "sim" : "nao"); }

			if (ft_strchr(buftemporario, '\n') != NULL)
			{
				if(debug == 1) { printf("272: tem um '\\n' nesse buffer\n"); }
				if(debug == 1) { printf("273: TODO: e agora ????????????\n"); }

				j = last_offset;
				while (1)
				{
					if(debug == 1) { printf("278: deu merda buscando '\\n' kkkkkk %i %d '%c'\n", j, buffer[j], buffer[j]); }
					if (buffer[j] == '\n')
						break ;
					*(temp_line + (j - last_offset)) = buffer[j];
					buffer[j] = 0;
					j++;
				}
				*(temp_line + (j - last_offset)) = '\0';
				buffer[j] = '\0';
				last_offset = j + 1;
				line_number++;
				if(debug == 1) { printf("289: retorno 1\n"); }
				*line = temp_line;
				return (1);
			}
			else
			{
				if(debug == 1) { printf("295: não tem um '\\n' nesse buffer\n"); }
				if(debug == 1) { printf("296: entao vou colocar esse finalzinho no inicio da linha\n"); }
				j = last_offset;
				while (j < BUFFER_SIZE)
				{
					if (buffer[j] == 0)
						break ;
					*(temp_line + (j - last_offset)) = buffer[j];
					buffer[j] = 0;
					j++;
				}
				if(debug == 1) { printf("304: i = %i, j = %i, last_offset = %i\n", i, j, last_offset); }
				i += j - last_offset;
			}
		}
		else
		{
			if(debug == 1) { printf("310: então EOF está proximo\n"); }
			if(debug == 1) { printf("311: read só leu %i\n", read_saida); }
			if(debug == 1) { printf("312: buffer = '%s'(%ld)\n", buffer, safe_strlen(buffer)); }

			if(debug == 1) { printf("314: tem '\\n' nesse buffer? %s\n", (ft_strchr(buffer, '\n') != NULL) ? "sim" : "nao"); }
			if (ft_strchr(buffer, '\n') != NULL)
			{
				if(debug == 1) { printf("317: TODO: estamos proximo do EOF, e ainda tem '\\n' nesse caraio\n"); }
				j = 0;
				while (j < BUFFER_SIZE)
				{
					if (buffer[j] == '\n')
						break ;
					*(temp_line + j + i) = buffer[j];
					buffer[j] = 0;
					j++;
				}
				last_offset = j + 1;
				if(debug == 1) { printf("328: last offset é %i\n", j); }
				if(debug == 1) { printf("329: last offset é %i\n", last_offset); }
				if(debug == 1) { printf("330: buffer[last_offset] = %i\n", buffer[last_offset]); }
				if(debug == 1) { printf("331: buffer[last_offset] = '%c'\n", buffer[last_offset]); }
				*(temp_line + j + i) = '\0';
				buffer[j] = 0;
				line_number++;
				if(debug == 1) { printf("335: retorno 1\n"); }
				*line = temp_line;
				return (1);

			}
			else
			{
				if(debug == 1) { printf("342: ufa estamos proximo do EOF, e não tem '\\n' nessa merda\n"); }
				if(debug == 1) { printf("343: é só colocar tudo no temp_line e ja era\n"); }
				if(debug == 1) { printf("344: j = %i, i = %i, read_saida = %i\n", j, i, read_saida); }
				j = 0;
				while (j < read_saida)
				{
					*(temp_line + j + i) = buffer[j];
					buffer[j] = 0;
					j++;
				}
				if(debug == 1) { printf("352: i = %i; j = %i; i + j = %i\n", i, j, i + j); }
				*(temp_line + j + i) = '\0';
				line_number++;
				if(debug == 1) { printf("355: retorno 0\n"); }
				*line = temp_line;
				return (0);
			}
		}
	}
	if(debug == 1) { printf("361: retorno -1\n"); }
	return (-1);
}
