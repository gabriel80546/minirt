/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 14:06:33 by gpassos-          #+#    #+#             */
/*   Updated: 2021/02/26 10:45:00 by gabriel          ###   ########.fr       */
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

static int	ft_min(int a, int b)
{
	if (a > b)
		return (b);
	else
		return (a);
}

char		*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*saida;
	size_t	contador;
	size_t	s_len;
	int		alocar;

	if (s == NULL)
		return (NULL);
	s_len = ft_strlen(s);
	alocar = ((start >= s_len) ? 1 : ft_min(s_len + 1, len + 1));
	saida = (char *)malloc(sizeof(char) * alocar);
	if (saida == NULL)
		return (NULL);
	if (start > s_len)
	{
		*(saida + 0) = '\0';
		return (saida);
	}
	contador = start;
	while ((contador < (start + len)) && (contador < s_len))
	{
		*(saida + (contador - start)) = *((char *)s + contador);
		contador++;
	}
	*(saida + (contador - start)) = '\0';
	return (saida);
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

	if(debug == 1) { printf("220: --------------------\n"); }
	if(debug == 1) { printf("221: fd = %d\n", fd); }
	if(debug == 1) { printf("222: line = %p\n", line); }
	if(debug == 1) { printf("223: buffer = %p\n", buffer); }
	if(debug == 1) { printf("224: line_number = %d\n", line_number); }
	if(debug == 1) { printf("225: last_offset = %d\n", last_offset); }
	if(debug == 1) { printf("226: --------------------\n"); }

	if(line_number == 0)
		buffer = (char *)ft_calloc(sizeof(char), BUFFER_SIZE + 1);

	temp_line = (char *)ft_calloc(sizeof(char), BUFFER_SIZE + 1);
	size_temp_line = 0;

	while (1)
	{
		if (last_offset == 0)
		{
			read_saida = read(fd, buffer, BUFFER_SIZE);
			buffer[read_saida] = '\0';
			if (read_saida < 0 || read_saida > BUFFER_SIZE)
				return (-1);
		}


		if (last_offset != 0)
		{
			if(debug == 1) { printf("247: tinha coisa no buffer\n"); }
			// if(debug == 1) { printf("248: buffer = '%s'\n", buffer); }
			if(debug == 1) { printf("249: temp_line = '%s'\n", temp_line); }
			// if(debug == 1) { printf("250: buffer = '%s'\n", buffer); }
			if(debug == 1) { printf("251: buffer + last_offset = '%s'\n", buffer + last_offset); }
			if(debug == 1) { printf("252: tem dois '\\n' no buffer? %s\n", (ft_strchr(buffer + last_offset, '\n') == NULL) ? "nao" : "sim"); }
			// last_offset = 0;

			if (ft_strchr(buffer + last_offset, '\n') == NULL)
			{
				if(debug == 1) { printf("257: esse buffer nao tem dois '\\n'\n"); }
				temp_temp_line = ft_strjoin(temp_line, buffer + last_offset);
				free(temp_line);
				temp_line = temp_temp_line;
				size_temp_line = ft_strlen(temp_line);
				if(debug == 1) { printf("262: buffer + last_offset = '%s'\n", buffer + last_offset); }
				if(debug == 1) { printf("263: temp_line = '%s'\n", temp_line); }

				// temp_temp_line = ft_substr(temp_line, ft_strchr(temp_line, '\n') - temp_line + 1, BUFFER_SIZE - (ft_strchr(temp_line, '\n') - temp_line));
				temp_temp_line = ft_substr(temp_line, 0, BUFFER_SIZE - (ft_strchr(temp_line, '\n') - temp_line));
				free(temp_line);
				temp_line = temp_temp_line;
				size_temp_line = ft_strlen(temp_line);
				// if(debug == 1) { printf("262: buffer = '%s'\n", buffer); }
				if(debug == 1) { printf("271: temp_line = '%s'\n", temp_line); }
				last_offset = 0;
				// return (-1);
			}
			else
			{
				if(debug == 1) { printf("277: esse buffer tem dois '\\n'\n"); }
				temp_temp_line = ft_strjoin(temp_line, buffer);
				free(temp_line);
				temp_line = temp_temp_line;
				size_temp_line = ft_strlen(temp_line);
				if(debug == 1) { printf("282: buffer + last_offset = '%s'\n", buffer + last_offset); }
				if(debug == 1) { printf("283: temp_line = '%s'\n", temp_line); }
				if(debug == 1) { printf("284: last_offset = %d\n", last_offset); }
				if(debug == 1) { printf("285: ft_strchr(buffer + last_offset, '\\n') - buffer - last_offset = %ld\n", ft_strchr(buffer + last_offset, '\n') - buffer - last_offset); }

				temp_temp_line = ft_substr(temp_line, last_offset, ft_strchr(buffer + last_offset, '\n') - buffer - last_offset);
				free(temp_line);
				temp_line = temp_temp_line;
				size_temp_line = ft_strlen(temp_line);
				// if(debug == 1) { printf("262: buffer = '%s'\n", buffer); }
				if(debug == 1) { printf("292: temp_line = '%s'\n", temp_line); }
				if(debug == 1) { printf("293: last_offset = %d\n", last_offset); }
				last_offset += ft_strlen(temp_line) + 1;
				if(debug == 1) { printf("295: last_offset = %d\n", last_offset); }
				if(debug == 1) { printf("296: buffer + last_offset = '%s'\n", buffer + last_offset); }
				*line = temp_line;
				return (1);
			}
		}
		else if (read_saida == 0)
		{
			if(debug == 1) { printf("303: ultimo read feito\n"); }
			if(debug == 1) { printf("304: buffer = '%s'\n", buffer); }
			if(debug == 1) { printf("305: temp_line = '%s'\n", temp_line); }
			if(debug == 1) { printf("306: size_temp_line = %d\n", size_temp_line); }
			if(debug == 1) { printf("307: tem '\\n' no buffer? %s\n", (ft_strchr(buffer, '\n') != NULL) ? "sim" : "nao"); }

			*line = (char *)ft_calloc(sizeof(char), size_temp_line + 1);
			ft_memcpy(*line, temp_line, size_temp_line);
			free(temp_line);
			// *line = temp_line;
			free(buffer);
			line_number++;

			return (0);
		}
		else if (read_saida <= BUFFER_SIZE)
		{
			if(debug == 1) { printf("320: leitura normal\n"); }
			if(debug == 1) { printf("321: buffer = '%s'\n", buffer); }
			if(debug == 1) { printf("322: temp_line = '%s'\n", temp_line); }
			if(debug == 1) { printf("323: tem '\\n' no buffer? %s\n", (ft_strchr(buffer, '\n') != NULL) ? "sim" : "nao"); }

			if (ft_strchr(buffer, '\n') != NULL)
			{
				if(debug == 1) { printf("327: tem '\\n' nesse buffer\n"); }
				temp_temp_line = ft_strjoin(temp_line, buffer);
				free(temp_line);
				temp_line = temp_temp_line;
				size_temp_line = ft_strlen(temp_line);
				if(debug == 1) { printf("332: buffer = '%s'\n", buffer); }
				if(debug == 1) { printf("333: temp_line = '%s'\n", temp_line); }

				temp_temp_line = ft_substr(temp_line, 0, ft_strchr(temp_line, '\n') - temp_line);
				free(temp_line);
				temp_line = temp_temp_line;
				size_temp_line = ft_strlen(temp_line);
				*line = temp_line;
				if(debug == 1) { printf("340: buffer = '%s'\n", buffer); }
				if(debug == 1) { printf("341: temp_line = '%s'\n", temp_line); }
				if(debug == 1) { printf("342: last_offset = %d\n", last_offset); }

				last_offset += ft_strchr(buffer, '\n') - buffer + 1;
				if(debug == 1) { printf("345: last_offset = %d\n", last_offset); }
				line_number++;
				return (1);
			}
			else
			{
				if(debug == 1) { printf("351: nao tem '\\n' nesse buffer\n"); }
				temp_temp_line = ft_strjoin(temp_line, buffer);
				free(temp_line);
				temp_line = temp_temp_line;
				size_temp_line = ft_strlen(temp_line);
				if(debug == 1) { printf("356: buffer = '%s'\n", buffer); }
				if(debug == 1) { printf("357: temp_line = '%s'\n", temp_line); }
			}
		}
	}
	return (-1);
}
