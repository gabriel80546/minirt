/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 14:06:33 by gpassos-          #+#    #+#             */
/*   Updated: 2021/02/25 22:08:51 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/resource.h>
// #include "libft/libft.h"

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 32
#endif

size_t	ft_strlen(const char *s)
{
	int	contador;

	if (s == NULL)
		return (0);
	contador = 0;
	while (*(s + contador) != '\0')
		contador++;
	return (contador);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*saida;
	int		contador;
	int		next;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	saida = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (saida == NULL)
		return (NULL);
	next = 0;
	contador = 0;
	while (*((char *)s1 + contador) != '\0')
	{
		*(saida + contador) = *((char *)s1 + contador);
		contador++;
	}
	while (*((char *)s2 + next) != '\0')
	{
		*(saida + contador) = *((char *)s2 + next);
		next++;
		contador++;
	}
	*(saida + contador) = '\0';
	return (saida);
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

void	*ft_calloc(size_t nmemb, size_t size)
{
	void *saida;

	saida = malloc(nmemb * size);
	if (saida == NULL)
		return (NULL);
	ft_memset(saida, 0, nmemb * size);
	return (saida);
}

void	*ft_calloco(size_t nmemb, size_t size)
{
	return ft_calloc(nmemb, size);
}
void	*ft_calloca(size_t nmemb, size_t size)
{
	return ft_calloc(nmemb, size);
}

char	*join_and_free(void)
{
	return (NULL);
}

void	print_nstring(char *str, int n)
{
	int i;
	
	i = 0;
	while (i < n)
	{
		// printf("%c[%d]", str[i], str[i]);
		printf("%c", str[i]);
		i++;
	}
	return ;
}


char	*ft_strdup(const char *s)
{
	char	*saida;
	int		i;

	i = 0;
	saida = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (saida == NULL)
		return (NULL);
	while (*((char *)s + i) != '\0')
	{
		*(saida + i) = *((char *)s + i);
		i++;
	}
	*(saida + i) = '\0';
	return (saida);
}

int		get_next_line(int fd, char **line)
{
	static char	*buffer;
	static int	line_number = 0;
	static int	last_offset = 0;
	char		*temp_temp_line;
	char		*temp_line;
	int			size_temp_line;
	int			read_saida;
	// int			i;
	// int			j;

	int			debug;
	debug = 1;
	debug = 0;


	if(debug == 1) { printf("179: --------------------\n"); }
	if(debug == 1) { printf("180: fd = %d\n", fd); }
	if(debug == 1) { printf("181: line = %p\n", line); }
	if(debug == 1) { printf("182: buffer = %p\n", buffer); }
	if(debug == 1) { printf("183: line_number = %d\n", line_number); }
	if(debug == 1) { printf("184: last_offset = %d\n", last_offset); }
	if(debug == 1) { printf("185: --------------------\n"); }


	if(line_number == 0)
		buffer = (char *)ft_calloc(sizeof(char), BUFFER_SIZE + 1);

	temp_line = (char *)ft_calloco(sizeof(char), BUFFER_SIZE + 1);
	size_temp_line = 0;
	temp_line[BUFFER_SIZE] = '\0';


	while (1)
	{
		if (last_offset == 0)
		{
			read_saida = read(fd, buffer, BUFFER_SIZE);
			buffer[read_saida] = '\0';
		}

		if(debug == 1) { printf("208: foi lido %d\n", read_saida); }
		if(debug == 1) { printf("209: buffer = '"); print_nstring(buffer, read_saida); printf("'\n"); }

		if (last_offset != 0)
		{
			if(debug == 1) { printf("213: tem coisa no buffer\n"); }
			if(debug == 1) { printf("214: buffer + last_offset = '"); print_nstring(buffer + last_offset, BUFFER_SIZE - last_offset); printf("'\n"); }
			if(debug == 1) { printf("215: last_offset = %d; BUFFER_SIZE = %d; BUFFER_SIZE - last_offset = %d\n", last_offset, BUFFER_SIZE, BUFFER_SIZE - last_offset); }
			if(debug == 1) { printf("216: temp_line = '"); print_nstring(temp_line, size_temp_line); printf("'\n"); }
			if(debug == 1) { printf("217: temp_temp_line = '"); print_nstring(temp_temp_line, size_temp_line - read_saida); printf("'\n"); }
			if(debug == 1) { printf("218: size_temp_line = %d\n", size_temp_line); }


			if (ft_strchr(buffer + last_offset, '\n') != NULL)
			{
				if(debug == 1) { printf("223: TEM DOIS '\\n' NO BUFFER\n"); }
				// ft_memcpy(temp_line, temp_temp_line, size_temp_line - (ft_strchr(buffer, '\n') - buffer));




				if(debug == 1) { printf("229: temp_line = '"); print_nstring(temp_line, size_temp_line); printf("'\n"); }
				if(debug == 1) { printf("230: buffer = '"); print_nstring(buffer, BUFFER_SIZE); printf("'\n"); }
				if(debug == 1) { printf("231: buffer + last_offset= '%s'\n", buffer + last_offset); }
				if(debug == 1) { printf("232: ft_strchr(buffer, '\\n') - buffer = %ld\n", ft_strchr(buffer + last_offset, '\n') - buffer); }
				if(debug == 1) { printf("233: size_temp_line = %d\n", size_temp_line); }



				temp_temp_line = (char *)ft_calloc(sizeof(char), size_temp_line + 1);
				temp_temp_line[size_temp_line] = '\0';
				ft_memcpy(temp_temp_line, temp_line, size_temp_line);
				free(temp_line);
				if(debug == 1) { printf("241: temp_line = '"); print_nstring(temp_line, size_temp_line); printf("'\n"); }
				if(debug == 1) { printf("242: temp_temp_line = '"); print_nstring(temp_temp_line, size_temp_line - read_saida); printf("'\n"); }


				size_temp_line += (ft_strchr(buffer + last_offset, '\n') - ft_strchr(buffer, '\n'));
				temp_line = (char *)ft_calloc(sizeof(char), size_temp_line);
				temp_line[size_temp_line] = '\0';
				if(debug == 1) { printf("248: temp_line = '"); print_nstring(temp_line, size_temp_line); printf("'\n"); }
				if(debug == 1) { printf("249: temp_temp_line = '"); print_nstring(temp_temp_line, size_temp_line); printf("'\n"); }
				if(debug == 1) { printf("250: size_temp_line = %d\n", size_temp_line); }

				ft_memcpy(temp_line, temp_temp_line, size_temp_line - (ft_strchr(buffer + last_offset, '\n') - ft_strchr(buffer, '\n')));
				ft_memcpy(temp_line + size_temp_line + 1 - (ft_strchr(buffer + last_offset, '\n') - ft_strchr(buffer, '\n')), buffer + last_offset, (ft_strchr(buffer + last_offset, '\n') - ft_strchr(buffer, '\n')));
				free(temp_temp_line);
				if(debug == 1) { printf("255: temp_line = '"); print_nstring(temp_line, size_temp_line); printf("'\n"); }
				if(debug == 1) { printf("256: size_temp_line = %d\n", size_temp_line); }

				*line = (char *)ft_calloc(sizeof(char), size_temp_line + 1);
				ft_memcpy(*line, temp_line + 1, size_temp_line - 1);
				free(temp_line);
				line_number++;
				if(debug == 1) { printf("256: last_offset = %d; BUFFER_SIZE = %d; BUFFER_SIZE - last_offset = %d\n", last_offset, BUFFER_SIZE, BUFFER_SIZE - last_offset); }
				last_offset = (ft_strchr(buffer + last_offset, '\n') - buffer) + 1;
				if(debug == 1) { printf("258: last_offset = %d; BUFFER_SIZE = %d; BUFFER_SIZE - last_offset = %d\n", last_offset, BUFFER_SIZE, BUFFER_SIZE - last_offset); }
				if(debug == 1) { printf("259: buffer + last_offset= '%s'\n", buffer + last_offset); }
				if(debug == 1) { printf("266: *line = '"); print_nstring(*line, size_temp_line); printf("'\n"); }
				return (1);
				// return (0);
				// temp_temp_line = (char *)ft_calloc(sizeof(char), size_temp_line + (ft_strchr(buffer + last_offset, '\n') - buffer) + 1);
				// temp_temp_line[size_temp_line + (ft_strchr(buffer + last_offset, '\n') - buffer)] = '\0';
				// ft_memcpy(temp_temp_line, temp_line, size_temp_line);
				// free(temp_line);
				// size_temp_line += (ft_strchr(buffer + last_offset, '\n') - buffer);
				// temp_line = (char *)ft_calloc(sizeof(char), (size_temp_line + (ft_strchr(buffer, '\n') - buffer) + 1));
				// temp_line[size_temp_line + (ft_strchr(buffer + last_offset, '\n') - buffer)] = '\0';
				// if(debug == 1) { printf("242: temp_line = '"); print_nstring(temp_line, size_temp_line); printf("'\n"); }
				// if(debug == 1) { printf("243: temp_temp_line = '"); print_nstring(temp_temp_line, size_temp_line); printf("'\n"); }
				// if(debug == 1) { printf("244: size_temp_line = %d\n", size_temp_line); }
				// ft_memcpy(temp_line, temp_temp_line, size_temp_line - (ft_strchr(buffer + last_offset, '\n') - buffer));
				// ft_memcpy(temp_line + size_temp_line - (ft_strchr(buffer + last_offset, '\n') - buffer), buffer, (ft_strchr(buffer, '\n') - buffer));
				// free(temp_temp_line);
				// if(debug == 1) { printf("248: temp_line = '"); print_nstring(temp_line, size_temp_line); printf("'\n"); }
				// if(debug == 1) { printf("249: size_temp_line = %d\n", size_temp_line); }
				// *line = (char *)ft_calloc(sizeof(char), size_temp_line + 1);
				// ft_memcpy(*line, temp_line, size_temp_line);
				// free(temp_line);
				// line_number++;
				// return (-1);
				// last_offset = (ft_strchr(buffer + last_offset, '\n') - buffer) + 1;

				// if(debug == 1) { printf("247: entre1 last_offset = %d\n", last_offset); }
				// last_offset = ft_strchr(buffer + last_offset, '\n') - buffer + 1;
				// if(debug == 1) { printf("247: entre2 last_offset = %d\n", last_offset); }
				// *line = (char *)ft_calloc(sizeof(char), 2);
				// *(*line + 0) = '\0';
				// return (1);
			}
			else
			{
				temp_temp_line = (char *)ft_calloc(sizeof(char), BUFFER_SIZE - last_offset + 1);
				temp_temp_line[BUFFER_SIZE - last_offset] = '\0';
				ft_memcpy(temp_temp_line, temp_line, size_temp_line);
				free(temp_line);
				size_temp_line += BUFFER_SIZE - last_offset;
				temp_line = (char *)ft_calloc(sizeof(char), size_temp_line + BUFFER_SIZE - last_offset + 1);
				temp_line[size_temp_line + BUFFER_SIZE - last_offset] = '\0';

				if(debug == 1) { printf("276: temp_line = '"); print_nstring(temp_line, size_temp_line); printf("'\n"); }
				if(debug == 1) { printf("277: temp_temp_line = '"); print_nstring(temp_temp_line, size_temp_line - read_saida); printf("'\n"); }
				if(debug == 1) { printf("278: size_temp_line = %d\n", size_temp_line); }

				if(debug == 1) { printf("280: size_temp_line - BUFFER_SIZE - last_offset = %d\n", size_temp_line - (BUFFER_SIZE - last_offset)); }

				if(debug == 1) { printf("282: foi ate aqui\n"); }
				ft_memcpy(temp_line, temp_temp_line, size_temp_line - (BUFFER_SIZE - last_offset));
				if(debug == 1) { printf("284: foi ate aqui\n"); }
				ft_memcpy(temp_line + size_temp_line - (BUFFER_SIZE - last_offset), buffer + last_offset, BUFFER_SIZE - last_offset);
				if(debug == 1) { printf("286: foi ate aqui\n"); }
				free(temp_temp_line);

				if(debug == 1) { printf("289: temp_line = '"); print_nstring(temp_line, size_temp_line); printf("'\n"); }
				// if(debug == 1) { printf("233: temp_temp_line = '"); print_nstring(temp_temp_line, size_temp_line - read_saida); printf("'\n"); }
				if(debug == 1) { printf("291: size_temp_line = %d\n", size_temp_line); }

				if(debug == 1) { printf("293: buffer = '"); print_nstring(buffer, BUFFER_SIZE); printf("'\n"); }
				if(debug == 1) { printf("294: TEM DOIS '\\n' NO BUFFER ?????? %s\n", (ft_strchr(buffer + last_offset, '\n') != NULL) ? "SIM" : "NAO"); }
				if(debug == 1) { printf("295: antigo last_offset = %d\n", last_offset); }
				last_offset = 0;
			}
		}
		else if (read_saida == 0)
		{
			if(debug == 1) { printf("301: ultimo\n"); }
			*line = (char *)ft_calloca(sizeof(char), size_temp_line + 1);
			ft_memcpy(*line, temp_line, size_temp_line);
			free(temp_line);
			// *line = temp_line;
			free(buffer);
			line_number++;
			return (-1);
		}
		else if (read_saida <= BUFFER_SIZE)
		{
			if(debug == 1) { printf("312: houve uma leitura normal\n"); }
			if(debug == 1) { printf("313: buffer = '"); print_nstring(buffer, read_saida); printf("'\n"); }
			if(debug == 1) { printf("314: temp_line = '"); print_nstring(temp_line, read_saida); printf("'\n"); }
			if(debug == 1) { printf("315: size_temp_line = %d\n", size_temp_line); }

			if(debug == 1) { printf("317: tem '\\n' no buffer? %s\n", (ft_strchr(buffer, '\n') != NULL) ? "sim" : "nao"); }
			if (ft_strchr(buffer, '\n') == NULL)
			{
				if(debug == 1) { printf("320: nao tem '\\n' no buffer\n"); }
				if(debug == 1) { printf("321: apenas copie esse buffer em temp_line e leia denovo\n"); }

				temp_temp_line = (char *)ft_calloc(sizeof(char), size_temp_line + 1);
				temp_temp_line[size_temp_line] = '\0';
				ft_memcpy(temp_temp_line, temp_line, size_temp_line);
				free(temp_line);
				size_temp_line += read_saida;
				temp_line = (char *)ft_calloc(sizeof(char), size_temp_line + 1);
				temp_line[size_temp_line] = '\0';
				if(debug == 1) { printf("278: temp_line = '"); print_nstring(temp_line, size_temp_line); printf("'\n"); }
				if(debug == 1) { printf("279: temp_temp_line = '"); print_nstring(temp_temp_line, size_temp_line - read_saida); printf("'\n"); }
				if(debug == 1) { printf("280: size_temp_line = %d\n", size_temp_line); }
				ft_memcpy(temp_line, temp_temp_line, size_temp_line - read_saida);
				ft_memcpy(temp_line + size_temp_line - read_saida, buffer, read_saida);
				free(temp_temp_line);
				if(debug == 1) { printf("284: temp_line = '"); print_nstring(temp_line, size_temp_line); printf("'\n"); }
				if(debug == 1) { printf("285: size_temp_line = %d\n", size_temp_line); }
			}
			else
			{
				if(debug == 1) { printf("289: tem '\\n' no buffer\n"); }
				// free(temp_line);

				if(debug == 1) { printf("292: temp_line = '"); print_nstring(temp_line, size_temp_line); printf("'\n"); }
				if(debug == 1) { printf("293: buffer = '"); print_nstring(buffer, BUFFER_SIZE); printf("'\n"); }
				if(debug == 1) { printf("294: ft_strchr(buffer, '\\n') - buffer = %ld\n", ft_strchr(buffer, '\n') - buffer); }
				if(debug == 1) { printf("295: size_temp_line = %d\n", size_temp_line); }


				temp_temp_line = (char *)ft_calloc(sizeof(char), size_temp_line + (ft_strchr(buffer, '\n') - buffer) + 1);
				temp_temp_line[size_temp_line + (ft_strchr(buffer, '\n') - buffer)] = '\0';
				ft_memcpy(temp_temp_line, temp_line, size_temp_line);
				free(temp_line);
				size_temp_line += (ft_strchr(buffer, '\n') - buffer);
				temp_line = (char *)ft_calloc(sizeof(char), (size_temp_line + (ft_strchr(buffer, '\n') - buffer) + 1));
				temp_line[size_temp_line + (ft_strchr(buffer, '\n') - buffer)] = '\0';
				if(debug == 1) { printf("305: temp_line = '"); print_nstring(temp_line, size_temp_line); printf("'\n"); }
				if(debug == 1) { printf("306: temp_temp_line = '"); print_nstring(temp_temp_line, size_temp_line); printf("'\n"); }
				if(debug == 1) { printf("307: size_temp_line = %d\n", size_temp_line); }
				ft_memcpy(temp_line, temp_temp_line, size_temp_line - (ft_strchr(buffer, '\n') - buffer));
				ft_memcpy(temp_line + size_temp_line - (ft_strchr(buffer, '\n') - buffer), buffer, (ft_strchr(buffer, '\n') - buffer));
				free(temp_temp_line);
				if(debug == 1) { printf("311: temp_line = '"); print_nstring(temp_line, size_temp_line); printf("'\n"); }
				if(debug == 1) { printf("312: size_temp_line = %d\n", size_temp_line); }
				*line = (char *)ft_calloc(sizeof(char), size_temp_line + 1);
				ft_memcpy(*line, temp_line, size_temp_line);
				free(temp_line);
				line_number++;
				last_offset = (ft_strchr(buffer, '\n') - buffer) + 1;
				return (1);
			}
		}
	}
	return (-1);
}
