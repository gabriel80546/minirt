/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_debug_version_two.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 14:06:33 by gpassos-          #+#    #+#             */
/*   Updated: 2021/02/27 12:31:25 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/resource.h>
// #include "libft/libft.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>


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


void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putstr_fd(char *s, int fd)
{
	int contador;

	if (s == NULL)
		return ;
	contador = 0;
	while (*(s + contador) != '\0')
	{
		ft_putchar_fd(*(s + contador), fd);
		contador++;
	}
}


int		get_next_line(int fd, char **line/* , int extra */)
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
	debug = 0;
	debug = 1;

	if (fd < 0 || BUFFER_SIZE <= 0 || line == NULL)
		return (-1);

	int fd1;
	char *string;

	// if(debug == 1) { string = (char *)malloc(sizeof(char) * 450); fd1 = open("/home/gabriel/Desktop/qd/projetos/gnl/saida", O_RDWR | O_APPEND);
	// sprintf(string, "line_number[%i]\n", line_number); ft_putstr_fd(string, fd1); }

	// if(debug == 1) { string = (char *)malloc(sizeof(char) * 450); fd1 = open("/home/gabriel/Desktop/qd/projetos/gnl/saida", O_RDWR | O_APPEND);
	// sprintf(string, "224: line_number = %d\n", line_number); ft_putstr_fd(string, fd1); }

	// close(fd1);

	if(debug == 1) { string = (char *)malloc(sizeof(char) * 450); fd1 = open("/home/gabriel/Desktop/qd/projetos/gnl/saida", O_RDWR | O_APPEND);
	sprintf(string, "220: --------------------\n"); ft_putstr_fd(string, fd1); free(string); }
	if(debug == 1) { string = (char *)malloc(sizeof(char) * 450); fd1 = open("/home/gabriel/Desktop/qd/projetos/gnl/saida", O_RDWR | O_APPEND);
	sprintf(string, "221: fd = %d\n", fd); ft_putstr_fd(string, fd1); free(string); }
	if(debug == 1) { string = (char *)malloc(sizeof(char) * 450); fd1 = open("/home/gabriel/Desktop/qd/projetos/gnl/saida", O_RDWR | O_APPEND);
	sprintf(string, "222: line = %p\n", line); ft_putstr_fd(string, fd1); free(string); }
	if(debug == 1) { string = (char *)malloc(sizeof(char) * 450); fd1 = open("/home/gabriel/Desktop/qd/projetos/gnl/saida", O_RDWR | O_APPEND);
	sprintf(string, "223: buffer = %p\n", buffer); ft_putstr_fd(string, fd1); free(string); }
	if(debug == 1) { string = (char *)malloc(sizeof(char) * 450); fd1 = open("/home/gabriel/Desktop/qd/projetos/gnl/saida", O_RDWR | O_APPEND);
	sprintf(string, "224: line_number = %d\n", line_number); ft_putstr_fd(string, fd1); free(string); }
	if(debug == 1) { string = (char *)malloc(sizeof(char) * 450); fd1 = open("/home/gabriel/Desktop/qd/projetos/gnl/saida", O_RDWR | O_APPEND);
	sprintf(string, "225: last_offset = %d\n", last_offset); ft_putstr_fd(string, fd1); free(string); }
	if(debug == 1) { string = (char *)malloc(sizeof(char) * 450); fd1 = open("/home/gabriel/Desktop/qd/projetos/gnl/saida", O_RDWR | O_APPEND);
	sprintf(string, "226: --------------------\n"); ft_putstr_fd(string, fd1); free(string); }

	if(line_number == 0)
		buffer = (char *)ft_calloc(sizeof(char), BUFFER_SIZE + 1);

	temp_line = (char *)ft_calloc(sizeof(char), BUFFER_SIZE + 1);
	size_temp_line = 0;
	
	while (1)
	{
		if (last_offset == 0)
		{
			read_saida = read(fd, buffer, BUFFER_SIZE);
			if (read_saida < 0 || read_saida > BUFFER_SIZE)
			{
				if(debug == 1) { string = (char *)malloc(sizeof(char) * 450); fd1 = open("/home/gabriel/Desktop/qd/projetos/gnl/saida", O_RDWR | O_APPEND);
				sprintf(string, "242: houve erro no read\n"); ft_putstr_fd(string, fd1); free(string); }
				if(debug == 1) { string = (char *)malloc(sizeof(char) * 450); fd1 = open("/home/gabriel/Desktop/qd/projetos/gnl/saida", O_RDWR | O_APPEND);
				sprintf(string, "243: read_saida = %d\n", read_saida); ft_putstr_fd(string, fd1); free(string); }
				free(temp_line);
				free(buffer);
				// *line = (char *)ft_calloc(sizeof(char), 1);
				line_number = 0;
				return (-1);
			}
			buffer[read_saida] = '\0';
		}


		if (last_offset != 0)
		{
			if(debug == 1) { string = (char *)malloc(sizeof(char) * 450); fd1 = open("/home/gabriel/Desktop/qd/projetos/gnl/saida", O_RDWR | O_APPEND);
			sprintf(string, "247: tinha coisa no buffer\n"); ft_putstr_fd(string, fd1); free(string); }
			// sprintf(string, "248: buffer = '%s'\n", buffer); }
			if(debug == 1) { string = (char *)malloc(sizeof(char) * 450); fd1 = open("/home/gabriel/Desktop/qd/projetos/gnl/saida", O_RDWR | O_APPEND);
			sprintf(string, "249: temp_line = '%s'\n", temp_line); ft_putstr_fd(string, fd1); free(string); }
			// sprintf(string, "250: buffer = '%s'\n", buffer); }
			if(debug == 1) { string = (char *)malloc(sizeof(char) * 450); fd1 = open("/home/gabriel/Desktop/qd/projetos/gnl/saida", O_RDWR | O_APPEND);
			sprintf(string, "251: buffer + last_offset = '%s'\n", buffer + last_offset); ft_putstr_fd(string, fd1); free(string); }
			if(debug == 1) { string = (char *)malloc(sizeof(char) * 450); fd1 = open("/home/gabriel/Desktop/qd/projetos/gnl/saida", O_RDWR | O_APPEND);
			sprintf(string, "252: tem mais de um '\\n' no buffer? %s\n", (ft_strchr(buffer + last_offset, '\n') == NULL) ? "nao" : "sim"); free(string); }
			// last_offset = 0;

			if (ft_strchr(buffer + last_offset, '\n') == NULL)
			{
				if(debug == 1) { string = (char *)malloc(sizeof(char) * 450); fd1 = open("/home/gabriel/Desktop/qd/projetos/gnl/saida", O_RDWR | O_APPEND);
				sprintf(string, "257: esse buffer nao tem dois '\\n'\n"); ft_putstr_fd(string, fd1); free(string); }
				temp_temp_line = ft_strjoin(temp_line, buffer + last_offset);
				free(temp_line);
				temp_line = temp_temp_line;
				// size_temp_line = ft_strlen(temp_line);
				if(debug == 1) { string = (char *)malloc(sizeof(char) * 450); fd1 = open("/home/gabriel/Desktop/qd/projetos/gnl/saida", O_RDWR | O_APPEND);
				sprintf(string, "262: buffer + last_offset = '%s'\n", buffer + last_offset); ft_putstr_fd(string, fd1); free(string); }
				if(debug == 1) { string = (char *)malloc(sizeof(char) * 450); fd1 = open("/home/gabriel/Desktop/qd/projetos/gnl/saida", O_RDWR | O_APPEND);
				sprintf(string, "263: temp_line = '%s'\n", temp_line); ft_putstr_fd(string, fd1); free(string); }


				if(debug == 1) { string = (char *)malloc(sizeof(char) * 450); fd1 = open("/home/gabriel/Desktop/qd/projetos/gnl/saida", O_RDWR | O_APPEND);
				sprintf(string, "263: temp_line = %p\n", temp_line); ft_putstr_fd(string, fd1); free(string); }
				if(debug == 1) { string = (char *)malloc(sizeof(char) * 450); fd1 = open("/home/gabriel/Desktop/qd/projetos/gnl/saida", O_RDWR | O_APPEND);
				sprintf(string, "264: BUFFER_SIZE - (ft_strchr(temp_line, '\\n') - temp_line = %ld\n", BUFFER_SIZE - (ft_strchr(temp_line, '\n') - temp_line)); ft_putstr_fd(string, fd1); free(string); }
				// temp_temp_line = ft_substr(temp_line, ft_strchr(temp_line, '\n') - temp_line + 1, BUFFER_SIZE - (ft_strchr(temp_line, '\n') - temp_line));
				temp_temp_line = ft_substr(temp_line, 0, (ft_strchr(temp_line, '\n') - temp_line));
				free(temp_line);
				temp_line = temp_temp_line;
				// size_temp_line = ft_strlen(temp_line);
				// sprintf(string, "262: buffer = '%s'\n", buffer); }
				if(debug == 1) { string = (char *)malloc(sizeof(char) * 450); fd1 = open("/home/gabriel/Desktop/qd/projetos/gnl/saida", O_RDWR | O_APPEND);
				sprintf(string, "271: temp_line = '%s'\n", temp_line); ft_putstr_fd(string, fd1); free(string); }
				last_offset = 0;
				// return (-1);
			}
			else
			{
				if(debug == 1) { string = (char *)malloc(sizeof(char) * 450); fd1 = open("/home/gabriel/Desktop/qd/projetos/gnl/saida", O_RDWR | O_APPEND);
				sprintf(string, "277: esse buffer tem dois '\\n'\n"); ft_putstr_fd(string, fd1); free(string); }
				temp_temp_line = ft_strjoin(temp_line, buffer);
				free(temp_line);
				temp_line = temp_temp_line;
				// size_temp_line = ft_strlen(temp_line);
				if(debug == 1) { string = (char *)malloc(sizeof(char) * 450); fd1 = open("/home/gabriel/Desktop/qd/projetos/gnl/saida", O_RDWR | O_APPEND);
				sprintf(string, "282: buffer + last_offset = '%s'\n", buffer + last_offset); ft_putstr_fd(string, fd1); free(string); }
				if(debug == 1) { string = (char *)malloc(sizeof(char) * 450); fd1 = open("/home/gabriel/Desktop/qd/projetos/gnl/saida", O_RDWR | O_APPEND);
				sprintf(string, "283: temp_line = '%s'\n", temp_line); ft_putstr_fd(string, fd1); free(string); }
				if(debug == 1) { string = (char *)malloc(sizeof(char) * 450); fd1 = open("/home/gabriel/Desktop/qd/projetos/gnl/saida", O_RDWR | O_APPEND);
				sprintf(string, "284: last_offset = %d\n", last_offset); ft_putstr_fd(string, fd1); free(string); }
				if(debug == 1) { string = (char *)malloc(sizeof(char) * 450); fd1 = open("/home/gabriel/Desktop/qd/projetos/gnl/saida", O_RDWR | O_APPEND);
				sprintf(string, "285: ft_strchr(buffer + last_offset, '\\n') - buffer - last_offset = %ld\n", ft_strchr(buffer + last_offset, '\n') - buffer - last_offset); ft_putstr_fd(string, fd1); free(string); }

				temp_temp_line = ft_substr(temp_line, last_offset, ft_strchr(buffer + last_offset, '\n') - buffer - last_offset);
				free(temp_line);
				temp_line = temp_temp_line;
				// size_temp_line = ft_strlen(temp_line);
				// sprintf(string, "262: buffer = '%s'\n", buffer); }
				if(debug == 1) { string = (char *)malloc(sizeof(char) * 450); fd1 = open("/home/gabriel/Desktop/qd/projetos/gnl/saida", O_RDWR | O_APPEND);
				sprintf(string, "292: temp_line = '%s'\n", temp_line); ft_putstr_fd(string, fd1); free(string); }
				if(debug == 1) { string = (char *)malloc(sizeof(char) * 450); fd1 = open("/home/gabriel/Desktop/qd/projetos/gnl/saida", O_RDWR | O_APPEND);
				sprintf(string, "293: last_offset = %d\n", last_offset); ft_putstr_fd(string, fd1); free(string); }
				last_offset += ft_strlen(temp_line) + 1;
				if(debug == 1) { string = (char *)malloc(sizeof(char) * 450); fd1 = open("/home/gabriel/Desktop/qd/projetos/gnl/saida", O_RDWR | O_APPEND);
				sprintf(string, "295: last_offset = %d\n", last_offset); ft_putstr_fd(string, fd1); free(string); }
				if(debug == 1) { string = (char *)malloc(sizeof(char) * 450); fd1 = open("/home/gabriel/Desktop/qd/projetos/gnl/saida", O_RDWR | O_APPEND);
				sprintf(string, "296: buffer + last_offset = '%s'\n", buffer + last_offset); ft_putstr_fd(string, fd1); free(string); }
				*line = temp_line;
				return (1);
			}
		}
		else if (read_saida == 0)
		{
			if(debug == 1) { string = (char *)malloc(sizeof(char) * 450); fd1 = open("/home/gabriel/Desktop/qd/projetos/gnl/saida", O_RDWR | O_APPEND);
			sprintf(string, "303: ultimo read feito\n"); ft_putstr_fd(string, fd1); free(string); }
			if(debug == 1) { string = (char *)malloc(sizeof(char) * 450); fd1 = open("/home/gabriel/Desktop/qd/projetos/gnl/saida", O_RDWR | O_APPEND);
			sprintf(string, "304: buffer = '%s'\n", buffer); ft_putstr_fd(string, fd1); free(string); }
			if(debug == 1) { string = (char *)malloc(sizeof(char) * 450); fd1 = open("/home/gabriel/Desktop/qd/projetos/gnl/saida", O_RDWR | O_APPEND);
			sprintf(string, "305: temp_line = '%s'\n", temp_line); ft_putstr_fd(string, fd1); free(string); }
			if(debug == 1) { string = (char *)malloc(sizeof(char) * 450); fd1 = open("/home/gabriel/Desktop/qd/projetos/gnl/saida", O_RDWR | O_APPEND);
			sprintf(string, "306: size_temp_line = %d\n", size_temp_line); ft_putstr_fd(string, fd1); free(string); }
			if(debug == 1) { string = (char *)malloc(sizeof(char) * 450); fd1 = open("/home/gabriel/Desktop/qd/projetos/gnl/saida", O_RDWR | O_APPEND);
			sprintf(string, "307: tem '\\n' no buffer? %s\n", (ft_strchr(buffer, '\n') != NULL) ? "sim" : "nao"); ft_putstr_fd(string, fd1); free(string); }

			size_temp_line = ft_strlen(temp_line);
			*line = (char *)ft_calloc(sizeof(char), size_temp_line + 1);
			ft_memcpy(*line, temp_line, size_temp_line);
			free(temp_line);
			// *line = temp_line;
			free(buffer);
			line_number = 0;

			return (0);
		}
		else if (read_saida <= BUFFER_SIZE)
		{
			if(debug == 1) { string = (char *)malloc(sizeof(char) * 450); fd1 = open("/home/gabriel/Desktop/qd/projetos/gnl/saida", O_RDWR | O_APPEND);
			sprintf(string, "320: leitura normal\n"); ft_putstr_fd(string, fd1); free(string); }
			if(debug == 1) { string = (char *)malloc(sizeof(char) * 450); fd1 = open("/home/gabriel/Desktop/qd/projetos/gnl/saida", O_RDWR | O_APPEND);
			sprintf(string, "321: buffer = '%s'\n", buffer); ft_putstr_fd(string, fd1); free(string); }
			if(debug == 1) { string = (char *)malloc(sizeof(char) * 450); fd1 = open("/home/gabriel/Desktop/qd/projetos/gnl/saida", O_RDWR | O_APPEND);
			sprintf(string, "322: temp_line = '%s'\n", temp_line); ft_putstr_fd(string, fd1); free(string); }
			if(debug == 1) { string = (char *)malloc(sizeof(char) * 450); fd1 = open("/home/gabriel/Desktop/qd/projetos/gnl/saida", O_RDWR | O_APPEND);
			sprintf(string, "323: tem '\\n' no buffer? %s\n", (ft_strchr(buffer, '\n') != NULL) ? "sim" : "nao"); ft_putstr_fd(string, fd1); free(string); }

			if (ft_strchr(buffer, '\n') != NULL)
			{
				if(debug == 1) { string = (char *)malloc(sizeof(char) * 450); fd1 = open("/home/gabriel/Desktop/qd/projetos/gnl/saida", O_RDWR | O_APPEND);
				sprintf(string, "327: tem '\\n' nesse buffer\n"); ft_putstr_fd(string, fd1); free(string); }
				temp_temp_line = ft_strjoin(temp_line, buffer);
				free(temp_line);
				temp_line = temp_temp_line;
				// size_temp_line = ft_strlen(temp_line);
				if(debug == 1) { string = (char *)malloc(sizeof(char) * 450); fd1 = open("/home/gabriel/Desktop/qd/projetos/gnl/saida", O_RDWR | O_APPEND);
				sprintf(string, "332: buffer = '%s'\n", buffer); ft_putstr_fd(string, fd1); free(string); }
				if(debug == 1) { string = (char *)malloc(sizeof(char) * 450); fd1 = open("/home/gabriel/Desktop/qd/projetos/gnl/saida", O_RDWR | O_APPEND);
				sprintf(string, "333: temp_line = '%s'\n", temp_line); ft_putstr_fd(string, fd1); free(string); }

				temp_temp_line = ft_substr(temp_line, 0, ft_strchr(temp_line, '\n') - temp_line);
				free(temp_line);
				temp_line = temp_temp_line;
				// size_temp_line = ft_strlen(temp_line);
				*line = temp_line;
				if(debug == 1) { string = (char *)malloc(sizeof(char) * 450); fd1 = open("/home/gabriel/Desktop/qd/projetos/gnl/saida", O_RDWR | O_APPEND);
				sprintf(string, "340: buffer = '%s'\n", buffer); ft_putstr_fd(string, fd1); free(string); }
				if(debug == 1) { string = (char *)malloc(sizeof(char) * 450); fd1 = open("/home/gabriel/Desktop/qd/projetos/gnl/saida", O_RDWR | O_APPEND);
				sprintf(string, "341: temp_line = '%s'\n", temp_line); ft_putstr_fd(string, fd1); free(string); }
				if(debug == 1) { string = (char *)malloc(sizeof(char) * 450); fd1 = open("/home/gabriel/Desktop/qd/projetos/gnl/saida", O_RDWR | O_APPEND);
				sprintf(string, "342: last_offset = %d\n", last_offset); ft_putstr_fd(string, fd1); free(string); }

				last_offset += ft_strchr(buffer, '\n') - buffer + 1;
				if(debug == 1) { string = (char *)malloc(sizeof(char) * 450); fd1 = open("/home/gabriel/Desktop/qd/projetos/gnl/saida", O_RDWR | O_APPEND);
				sprintf(string, "345: last_offset = %d\n", last_offset); ft_putstr_fd(string, fd1); free(string); }
				line_number++;
				return (1);
			}
			else
			{
				if(debug == 1) { string = (char *)malloc(sizeof(char) * 450); fd1 = open("/home/gabriel/Desktop/qd/projetos/gnl/saida", O_RDWR | O_APPEND);
				sprintf(string, "351: nao tem '\\n' nesse buffer\n"); ft_putstr_fd(string, fd1); free(string); }
				temp_temp_line = ft_strjoin(temp_line, buffer);
				free(temp_line);
				temp_line = temp_temp_line;
				// size_temp_line = ft_strlen(temp_line);
				if(debug == 1) { string = (char *)malloc(sizeof(char) * 450); fd1 = open("/home/gabriel/Desktop/qd/projetos/gnl/saida", O_RDWR | O_APPEND);
				sprintf(string, "356: buffer = '%s'\n", buffer); ft_putstr_fd(string, fd1); free(string); }
				if(debug == 1) { string = (char *)malloc(sizeof(char) * 450); fd1 = open("/home/gabriel/Desktop/qd/projetos/gnl/saida", O_RDWR | O_APPEND);
				sprintf(string, "357: temp_line = '%s'\n", temp_line); ft_putstr_fd(string, fd1); free(string); }
			}
		}
	}
	return (-1);
}
