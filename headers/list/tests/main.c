
#include "list.h"
#include <stdio.h>

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
		printf("16: prev = %p\n", lista->prev);
		printf("17: data = %p\n", lista->data);
		printf("18: next = %p\n", lista->next);
		printf("19: loop, item = %d\n\n", *((int *)lista->data));
		temp_list = lista;
		lista = lista->next;
	}
	lista = last_item(temp_list);
	while (lista != NULL)
	{
		printf("26: prev = %p\n", lista->prev);
		printf("27: data = %p\n", lista->data);
		printf("28: next = %p\n", lista->next);
		printf("29: loop, item = %d\n\n", *((int *)lista->data));
		temp_list = lista;
		lista = lista->prev;
	}
	clear_list(temp_list);
	return (0);
}