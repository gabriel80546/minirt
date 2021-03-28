
#include "list.h"

void	list_add(t_list *lista, void *conteudo)
{
	t_list	*last;

	while(lista != NULL)
	{
		last = lista;
		lista = lista->next;
	}
	lista = (t_list *)malloc(sizeof(t_list));
	lista->prev = last;
	lista->data = conteudo;
	lista->next = NULL;
	last->next = lista;
}
