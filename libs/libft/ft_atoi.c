/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpassos- <gpassos-@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 10:56:25 by gpassos-          #+#    #+#             */
/*   Updated: 2021/02/17 10:56:28 by gpassos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_atoi_backend(int y, int sinal, char backend[40])
{
	int dez;
	int contador;
	int saida;

	if (y == 0)
		return (0);
	contador = ft_strlen(backend);
	dez = 1;
	saida = 0;
	while (contador > 0)
	{
		if (dez > 1000000000 && sinal == 1)
			return (-1);
		else if (dez > 1000000000 && sinal == -1)
			return (0);
		saida += dez * (backend[contador - 1] - '0');
		dez *= 10;
		contador--;
	}
	return (sinal * saida);
}

static int	ft_atoi_pone(const char *nptr, int *i, int *a, int *b)
{
	if (*(nptr + *i) >= '0' && *(nptr + *i) <= '9')
	{
		*a = 1;
		*i -= 1;
	}
	else if (*(nptr + *i) == '+')
		*a = 1;
	else if (*(nptr + *i) == '-')
	{
		*b = -1;
		*a = 1;
	}
	else if (ft_strchr("\t\n\r\v\f ", *(nptr + *i)) == 0)
		return (-1);
	return (0);
}

static int	ft_atoi_ptwo(const char *nptr, int *contador, int *y, char *backend)
{
	if (*y > 30)
		return (-1);
	else if (*(nptr + *contador) >= '0' && *(nptr + *contador) <= '9')
	{
		backend[*y] = *((char *)nptr + *contador);
		*y += 1;
	}
	else
		return (-1);
	return (0);
}

static void	ft_atoi_init(int *y, int *estado, int *contador, int *sinal)
{
	*y = 0;
	*estado = 0;
	*contador = 0;
	*sinal = 1;
}

int			ft_atoi(const char *nptr)
{
	int			contador;
	int			y;
	char		backend[40];
	int			estado;
	int			sinal;

	ft_memset(backend, '\0', 40);
	ft_atoi_init(&y, &estado, &contador, &sinal);
	while (*(nptr + contador) != '\0')
	{
		if (estado == 0)
		{
			if (ft_atoi_pone(nptr, &contador, &estado, &sinal) == -1)
				break ;
		}
		else if (estado == 1)
		{
			if (ft_atoi_ptwo(nptr, &contador, &y, backend) == -1)
				break ;
		}
		contador++;
	}
	return (ft_atoi_backend(y, sinal, backend));
}
