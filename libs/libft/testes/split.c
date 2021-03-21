/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/07 13:16:42 by gabriel           #+#    #+#             */
/*   Updated: 2021/02/16 14:08:50 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "../libft.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include <ctype.h>


void	main_one(void);
void	main_two(void);
void	main_three(void);
void	main_four(void);
void	main_five(void);
void	main_six(void);
void	main_seven(void);
void	main_eight(void);
void	main_nine(void);
void	main_ten(void);

int		main_eleven(void);

int		main_doze(int arg);

int		test_three(int arg);

static void			ft_print_result(char const *s)
{
	// int		len;

	printf("%s", s);
	// len = 0;
	// while (s[len])
	// 	len++;
	// write(1, s, len);
}

static void			ft_print_tabstr(char **tabstr)
{
	int		i;

	i = 0;
	while (tabstr[i] != NULL)
	{
		// printf("tabstr[%i] = %p;\t'%s'(%ld)$\n", i, tabstr[i], tabstr[i], strlen(tabstr[i]));
		printf("tabstr[%i] '%s'$\n", i, tabstr[i]);
		// write(1, tabstr[i], 2);
		// write(1, "\n", 1);
		free(tabstr[i]);
		i++;
	}
	// free(tabstr);
	printf("FIM\n");
}

static void			check_split(char *s, char c)
{
	char	**tabstr;

	printf("s = \"%s\"(%ld)\n", s, strlen(s));
	printf("c = '%c'\n", c);

	printf("\n------------ ft_split(s, c) BEGIN\n");

	tabstr = ft_split(s, c);

	printf("------------ ft_split(s, c) END\n\n");

	// printf("tabstr = %p\n", tabstr);
	if (!tabstr)
		printf("NULL\n");
	else
		ft_print_tabstr(tabstr);

}

int					main_two_old(void)
{
	char *s = "      split       this for   me  !       ";

	char **result = ft_split(s, ' ');

	printf("result = %p\n", result);
	printf("*result = %p\n", *result);
	printf("*(result + 1) = %p\n", *(result + 1));
	printf("result = %p;\t!result = %d\n", result, !result);
	if (!result) {
		printf("TEST_SUCCESS\n");
		return (0); }
	printf("TEST_FAILED\n");
	return (1);
}

int		print_split(char **strings)
{
	int i;

	i = 0;
	while (*(strings + i) != NULL)
	{
		printf("strings[%i] = %s\n", i, *(strings + i));
		i++;
	}
	return (0);
}


int					main(int argc, const char *argv[])
{
	int		arg;

	alarm(5);
	if (argc == 1)
		return (0);
	if ((arg = atoi(argv[1])) == 1)
		check_split("          ", ' ');
	else if (arg == 2)
		check_split("lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed non risus. Suspendisse", ' ');
	else if (arg == 3)
		check_split("   lorem   ipsum dolor     sit amet, consectetur   adipiscing elit. Sed non risus. Suspendisse   ", ' ');
	else if (arg == 4)
		check_split("lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed non risus. Suspendisse lectus tortor, dignissim sit amet, adipiscing nec, ultricies sed, dolor. Cras elementum ultricies diam. Maecenas ligula massa, varius a, semper congue, euismod non, mi.", 'i');
	else if (arg == 5)
		check_split("lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed non risus. Suspendisse lectus tortor, dignissim sit amet, adipiscing nec, ultricies sed, dolor. Cras elementum ultricies diam. Maecenas ligula massa, varius a, semper congue, euismod non, mi.", 'z');
	else if (arg == 11)
		main_one();
	else if (arg == 12)
		main_two();
	else if (arg == 13)
		main_three();
	else if (arg == 14)
		main_four();
	else if (arg == 15)
		main_five();
	else if (arg == 16)
		main_six();
	else if (arg == 17)
		main_seven();
	else if (arg == 18)
		main_eight();
	else if (arg == 19)
		main_nine();
	else if (arg == 20)
		main_ten();
	else if (arg == 21)
		print_split(ft_split("teste split", ' '));
	else if (arg == 22)
		main_eleven();
	else if (arg >= 30 && arg <= 40)
		main_doze(arg - 30);
	else if (arg == 50)
		check_split("gabriel passos  duarte  gois", ' ');
	else if (arg == 51)
		check_split("gabriel passos", ' ');
	else if (arg == 52)
		check_split("gabriel passos ", ' ');
	else if (arg == 53)
		check_split("g ", ' ');
	else if (arg == 54)
		check_split(" ", ' ');
	else if (arg == 55)
		check_split("   ", ' ');
	else if (arg == 56)
		check_split("", ' ');
	else if (arg == 57)
		check_split("gabriel passos  duarte  gois", 'g');
	else if (arg == 58)
		check_split("lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed non risus. Suspendisse", ' ');
	else if (arg >= 60 && arg <= 70)
		test_three(arg - 60);
	else if (arg == 71)
		check_split("                  olol", ' ');
	else if (arg == 72)
		check_split("split  ||this|for|me|||||!|", '|');
	return (0);
}

int		sair(const char *string)
{
	puts(string);
	return 1;
}

void	split_cmp_array(char ** expected, char ** got)
{
	for (; *expected; expected++, got++)
	{
		if (*got == NULL || strcmp(*expected, *got))
		{
			// SET_DIFF(*expected, *got);
			sair("TEST_FAILED\n");
		}
	}

	sair("TEST_SUCCESS\n");
}

void	main_one(void)
{
	char *string = "      split       this for   me  !       ";
	char **expected = ((char*[6]){"split", "this", "for", "me", "!", ((void*)0)});
	char **result = ft_split(string, ' ');

	split_cmp_array(expected, result);
}

void	main_two(void)
{
	char **expected = ((char*[1]){((void*)0)});
	char *string = "                  ";
	char **result = ft_split(string, ' ');

	split_cmp_array(expected, result);
}

void	main_three(void)
{
	// char **expected = ((char*[1]){((void*)0)}); // eu acho
	char **expected = ((char*[2]){"olol", ((void*)0)}); // eu acho2
	char *s = "                  olol";
	char **result = ft_split(s, ' ');

	split_cmp_array(expected, result);
}

void	main_four(void)
{
	// char **expected = ((char*[1]){((void*)0)}); // eu acho
	char **expected = ((char*[2]){"olol", ((void*)0)}); // eu acho2
	char *s = "olol                     ";
	char **result = ft_split(s, ' ');

	split_cmp_array(expected, result);
}

void	main_five(void)
{
	char **expected = ((char*[1]){((void*)0)}); // eu acho
	char *s = "";
	char **result = ft_split(s, '\65');

	split_cmp_array(expected, result);
}

void	main_six(void)
{
	// char **expected = ((char*[1]){((void*)0)}); // eu acho
	char **expected = ((char*[10]){"0", "0", "0", "0", "0", "0", "0", "0", "0", ((void*)0)}); // eu acho2
	char *s = "0 0 0 0 0 0 0 0 0";
	char **result = ft_split(s, ' ');

	split_cmp_array(expected, result);
}


void	main_seven(void)
{
	// char **expected = ((char*[1]){((void*)0)}); // eu acho
	char **expected = ((char*[6]){"split  ", "this", "for", "me", "!", ((void*)0)}); // eu acho2
	char *s = "split  ||this|for|me|||||!|";
	int i = 0;
	char **result = ft_split(s, '|');

	while (result[i])
	{
		if (strcmp(result[i], *expected))
		{
			sair("TEST_FAILED\n");
		}
		free(result[i]);
		i++;
		expected++;
	}
	free(result);
	sair("TEST_SUCCESS\n");
}

void	main_eight(void)
{
	char *s = "      split       this for   me  !       ";

	char **result = ft_split(s, ' ');
	if (!result)
		sair("TEST_SUCCESS\n");
	sair("TEST_FAILED\n");
}

void	main_nine(void)
{
	char **expected = ((char*[6]){"split", "this", "for", "me", "!", ((void*)0)});
	char *s = "      split       this for   me  !       ";

	char **result = ft_split(s, ' ');
	while (*result)
	{
		if (strcmp(*result, *expected))
		{
			sair("TEST_FAILED\n");
		}
		result++;
		expected++;
	}
	sair("TEST_SUCCESS\n");
}

void	main_ten(void)
{
	char **expected = ft_split(((void*)0), ' ');

	if (!expected)
		sair("TEST_SUCCESS\n");
	sair("TEST_FAILED\n");
}


int main_eleven(void)
{

	char **strings;

	strings = ft_split("If money can't buy happyness", 'y');
	while (*strings)
		printf("%s\n", *strings++);
	printf("----------\n");
	strings = ft_split("If money can't buy happyness", 'e');
	while (*strings)
		printf("%s\n", *strings++);
	printf("----------\n");

	strings = ft_split("If money can't buy happyness", '3');
	while (*strings)
		printf("%s\n", *strings++);
	printf("----------\n");

	strings = ft_split("If money can't buy happyness", '\0');
	while (*strings)
		printf("%s\n", *strings++);
	printf("----------\n");

	strings = ft_split("          ", ' ');
	while (*strings)
		printf("%s\n", *strings++);
	printf("----------\n");

	strings = ft_split("lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed non risus. Suspendisse", ' ');
	while (*strings)
		printf("%s\n", *strings++);
	printf("----------\n");

	strings = ft_split("   lorem   ipsum dolor     sit amet, consectetur   adipiscing elit. Sed non risus. Suspendisse   ", ' ');
	while (*strings)
		printf("%s\n", *strings++);
	printf("----------\n");

	strings = ft_split("lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed non risus. Suspendisse lectus tortor, dignissim sit amet, adipiscing nec, ultricies sed, dolor. Cras elementum ultricies diam. Maecenas ligula massa, varius a, semper congue, euismod non, mi.", 'i');
	while (*strings)
		printf("%s\n", *strings++);
	printf("----------\n");

	strings = ft_split("lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed non risus. Suspendisse lectus tortor, dignissim sit amet, adipiscing nec, ultricies sed, dolor. Cras elementum ultricies diam. Maecenas ligula massa, varius a, semper congue, euismod non, mi.", 'z');
	while (*strings)
		printf("%s\n", *strings++);
	printf("----------\nFIM\n");
	return (0);
}


int             main_doze(int arg)
{
	char	**tabstr;
	int		i;
	// int             arg;

	alarm(5);
	// if (argc == 1)
	//         return (0);
	i = 0;
	if (arg == 1)
	{
		if (!(tabstr = ft_split("          ", ' ')))
			ft_print_result("NULL");
		else
		{
			while (tabstr[i] != NULL)
			{
				ft_print_result(tabstr[i]);
				write(1, "\n", 1);
				i++;
			}
		}
	}
	else if (arg == 2)
	{
		if (!(tabstr = ft_split("lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed non risus. Suspendisse", ' ')))
			ft_print_result("NULL");
		else
		{
			while (tabstr[i] != NULL)
			{
				ft_print_result(tabstr[i]);
				write(1, "\n", 1);
				i++;
			}
		}
	}
	else if (arg == 3)
	{
		if (!(tabstr = ft_split("   lorem   ipsum dolor     sit amet, consectetur   adipiscing elit. Sed non risus. Suspendisse   ", ' ')))
			ft_print_result("NULL");
		else
		{
			while (tabstr[i] != NULL)
			{
				ft_print_result(tabstr[i]);
				write(1, "\n", 1);
				i++;
			}
		}
	}
	else if (arg == 4)
	{
		if (!(tabstr = ft_split("lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed non risus. Suspendisse lectus tortor, dignissim sit amet, adipiscing nec, ultricies sed, dolor. Cras elementum ultricies diam. Maecenas ligula massa, varius a, semper congue, euismod non, mi.", 'i')))
			ft_print_result("NULL");
		else
		{
			while (tabstr[i] != NULL)
			{
				ft_print_result(tabstr[i]);
				write(1, "\n", 1);
				i++;
			}
		}
	}
	else if (arg == 5)
	{
		if (!(tabstr = ft_split("lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed non risus. Suspendisse lectus tortor, dignissim sit amet, adipiscing nec, ultricies sed, dolor. Cras elementum ultricies diam. Maecenas ligula massa, varius a, semper congue, euismod non, mi.", 'z')))
			ft_print_result("NULL");
		else
		{
			while (tabstr[i] != NULL)
			{
				ft_print_result(tabstr[i]);
				write(1, "\n", 1);
				i++;
			}
		}
	}
	else if (arg == 6)
	{
		if (!(tabstr = ft_split("", 'z')))
			ft_print_result("NULL");
		else
			if (!tabstr[0])
				ft_print_result("ok\n");
	}
	return (0);
}

int		test_three(int arg)
{
	char	**tabstr;
	int		i;

	// alarm(5);
	i = 0;
	if (arg == 1)
	{
		if (!(tabstr = ft_split("          ", ' ')))
			ft_print_result("NULL");
		else
		{
			while (tabstr[i] != NULL)
			{
				ft_print_result(tabstr[i]);
				printf("\n");
				i++;
			}
		}
	}
	else if (arg == 2)
	{
		if (!(tabstr = ft_split("lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed non risus. Suspendisse", ' ')))
			ft_print_result("NULL");
		else
		{
			while (tabstr[i] != NULL)
			{
				ft_print_result(tabstr[i]);
				printf("\n");
				i++;
			}
		}
	}
	else if (arg == 3)
	{
		if (!(tabstr = ft_split("   lorem   ipsum dolor     sit amet, consectetur   adipiscing elit. Sed non risus. Suspendisse   ", ' ')))
			ft_print_result("NULL");
		else
		{
			while (tabstr[i] != NULL)
			{
				ft_print_result(tabstr[i]);
				printf("\n");
				i++;
			}
		}
	}
	else if (arg == 4)
	{
		if (!(tabstr = ft_split("lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed non risus. Suspendisse lectus tortor, dignissim sit amet, adipiscing nec, ultricies sed, dolor. Cras elementum ultricies diam. Maecenas ligula massa, varius a, semper congue, euismod non, mi.", 'i')))
			ft_print_result("NULL");
		else
		{
			while (tabstr[i] != NULL)
			{
				ft_print_result(tabstr[i]);
				printf("\n");
				i++;
			}
		}
	}
	else if (arg == 5)
	{
		if (!(tabstr = ft_split("lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed non risus. Suspendisse lectus tortor, dignissim sit amet, adipiscing nec, ultricies sed, dolor. Cras elementum ultricies diam. Maecenas ligula massa, varius a, semper congue, euismod non, mi.", 'z')))
			ft_print_result("NULL");
		else
		{
			while (tabstr[i] != NULL)
			{
				ft_print_result(tabstr[i]);
				printf("\n");
				i++;
			}
		}
	}
	else if (arg == 6)
	{
		if (!(tabstr = ft_split("", 'z')))
			ft_print_result("NULL");
		else
			if (!tabstr[0])
				ft_print_result("ok\n");
	}
	return (0);
}