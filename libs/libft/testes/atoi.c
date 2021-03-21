/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 11:58:41 by jtoty             #+#    #+#             */
/*   Updated: 2021/02/11 08:00:52 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "../libft.h"
#include <stdio.h>
#include <string.h>

static void		ft_print_result2(char c)
{
	write(1, &c, 1);
}

static void		ft_print_result(int n)
{
    printf("%d", n);
}

void            warp(const char *npbr)
{
    printf("npbr = '%s', size = %ld\n", npbr, strlen(npbr));
    ft_print_result(ft_atoi(npbr));
    printf("@\n");
}
int				 main(int argc, const char *argv[])
{

    int		arg;
	if (argc == 1)		return (0);

    // printf("i = %i\n", argc);
    arg = atoi(argv[argc - 1]);
	alarm(5);
	if (arg == 1)
		warp("0");
	else if (arg == 2)
		warp("546:5");
	else if (arg == 3)
		warp("-4886");
	else if (arg == 4)
		warp("+548");
	else if (arg == 5)
		warp("054854");
	else if (arg == 6)
		warp("000074");
	else if (arg == 7)
		warp("+-54");
	else if (arg == 8)
		warp("-+48");
	else if (arg == 9)
		warp("--47");
	else if (arg == 10)
		warp("++47");
	else if (arg == 11)
		warp("+47+5");
	else if (arg ==12)
		warp("-47-5");
	else if (arg == 13) {
		printf("\\e475\n");
		warp("\e475"); }
	else if (arg == 14) {
		printf("\\t\\n\\r\\v\\f  469 \\n\n");
		warp("\t\n\r\v\f  469 \n"); }
	else if (arg == 15)
		warp("-2147483648");
	else if (arg == 16)
		warp("2147483647");
	else if (arg == 17) {
		printf("\\t\\n\\r\\v\\fd469 \\n\n");
		warp("\t\n\r\v\fd469 \n"); }
	else if (arg == 18) {
		printf("\"\\n\\n\\n  -46\\b9 \\n5d6\"\n");
		warp("\n\n\n  -46\b9 \n5d6"); }
	else if (arg == 19)
		warp("");
	else if (arg == 20)
		warp("134987465416876517964135798744354135");
	else if (arg == 21)
		warp("-99999999999999999999999999");
	else if (arg == 22)
		warp("99999999999999999999999999");
	else if (arg == 23)
		warp("9223372036854775807");
	return (0);
}
