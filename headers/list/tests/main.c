
#include "list.h"
#include <stdio.h>
// #include <stdlib.h>

int main()
{
	t_list *lista;
	t_list *temp_list;
	int		conteudo[5];
	conteudo[0] = 42;
	conteudo[1] = 56;
	lista = list_init(&conteudo[0]);
	list_add(lista, &conteudo[1]);
	while (lista != NULL)
	{
		printf("51: prev = %p\n", lista->prev);
		printf("52: data = %p\n", lista->data);
		printf("53: next = %p\n", lista->next);
		printf("54: loop, item = %d\n\n", *((int *)lista->data));
		temp_list = lista;
		lista = lista->next;
	}
	clear_list(temp_list);
	return (0);
}