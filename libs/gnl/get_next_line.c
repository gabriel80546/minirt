/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 14:06:33 by gpassos-          #+#    #+#             */
/*   Updated: 2021/03/07 18:40:49 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>


static int	ft_min(int a, int b)
{
	if (a > b)
		return (b);
	else
		return (a);
}

static char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*saida;
	size_t	contador;
	size_t	s_len;
	int		alocar;

	if (s == NULL)
		return ((char *)1);
	s_len = ft_strlen(s);
	alocar = ((start >= s_len) ? 1 : ft_min(s_len + 1, len + 1));
	saida = (char *)malloc(sizeof(char) * alocar);
	if (saida == NULL)
		return ((char *)2);
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

static int	get_next_util(char *vars[3], char *extra1)
{
	if (ft_strchr(extra1, '\n') == NULL)
	{
		vars[1] = ft_strjoin(vars[2], extra1);
		free(vars[2]);
		vars[2] = vars[1];
		return (1);
	}
	else
	{
		vars[1] = ft_strjoin(vars[2], vars[0]);
		free(vars[2]);
		vars[2] = vars[1];
		vars[1] = ft_substr(vars[2], 0, ft_strchr(vars[2], '\n') - vars[2]);
		free(vars[2]);
		vars[2] = vars[1];
		return (2);
	}
}

static int	get_fim(char *bf[3], int nums[3], char **line, char bu[])
{
	if (nums[1] > 0 && nums[1] <= BUFFER_SIZE)
	{
		nums[0] = 1;
		bf[0] = bu;
		if (get_next_util(bf, bu) == 2)
		{
			*line = bf[2];
			nums[1] = (ft_strlen(bu) - (ft_strchr(bu, '\n') - bu + 1));
			ft_memcpy(bu, (ft_strchr(bu, '\n') + 1), nums[1]);
			bu[nums[1]] = '\0';
			nums[2] = 1;
			return (1);
		}
	}
	else if (nums[1] == 0)
	{
		*line = (char *)malloc(sizeof(char) * (ft_strlen(bf[2]) + 1));
		ft_memset(*line, 0, (ft_strlen(bf[2]) + 1));
		ft_memcpy(*line, bf[2], ft_strlen(bf[2]));
		free(bf[2]);
		nums[2] = 0;
		return (0);
	}
	nums[2] = 2;
	return (2);
}

int			get_next_line(int fd, char **line)
{
	static char	bu[BUFFER_SIZE + 1];
	t_gnl		gnl;

	gnl.nums[0] = 0;
	if (fd < 0 || BUFFER_SIZE <= 0 || line == NULL)
		return (-1);
	gnl.bf[2] = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	ft_memset(gnl.bf[2], 0, ft_min(10, (BUFFER_SIZE + 1)));
	while (1)
	{
		if (bu[0] == '\0' || gnl.nums[0] == 1)
		{
			gnl.nums[1] = read(fd, bu, BUFFER_SIZE);
			if (gnl.nums[1] < 0 || gnl.nums[1] > BUFFER_SIZE)
			{
				free(gnl.bf[2]);
				return (-1);
			}
			bu[gnl.nums[1]] = '\0';
		}
		else
			gnl.nums[1] = BUFFER_SIZE - 1;
		if (get_fim(gnl.bf, gnl.nums, line, bu) != 2)
			return (gnl.nums[2]);
	}
}
