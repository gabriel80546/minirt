#include <stdio.h> //printf
#include <sys/types.h> //open
#include <sys/stat.h> //open
#include <fcntl.h> //open
#include <unistd.h> //close
#include <stdlib.h> //free

int            get_next_line(int fd, char **line);

int    main(int argc, char *argv[])
{
    char * linhai;
    linhai = NULL;
	char arquivo[50];
    int i,j;
	if (argc > 0)
	{
		sprintf(arquivo, "text%d", atoi(argv[0]));
	}
	else
	{
		sprintf(arquivo, "text1");
	}
    i = open(arquivo, O_RDONLY);
    j = 1;
    while (j >= 0)
    {
        j = get_next_line(i, &linhai);
        printf("%s-\n", linhai);
        free(linhai);
    }
    close(i);
    printf("*******************************************************************\n");
    i = open("text1",O_RDONLY);

    j = 1;
    while (j)
    {
        j = get_next_line(i, &linhai);
        printf("%s-\n", linhai);
        free(linhai);

    }
    close(i);
    printf("*******************************************************************\n");
    i = open("text2",O_RDONLY);

    j = 1;
    while (j)
    {
        j = get_next_line(i, &linhai);
        printf("%s-\n", linhai);
        free(linhai);

    }
    close(i);

    return (0);
}

