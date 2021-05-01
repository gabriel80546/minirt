#include "check.h"

void	check(bool condition)
{
	static int	index = 1;

	if (condition)
		printf(" %i: \033[32mOK\033[0m", index);
	else
		printf(" %i: \033[31mKO\033[0m", index);
	index++;
}
