#include "list.h"

void	list_add(t_list *lista, void *conteudo)
{
	t_list	*last;

	last = NULL;
	while (lista != NULL)
	{
		last = lista;
		lista = lista->next;
	}
	lista = (t_list *)malloc(sizeof(t_list));
	if (lista == NULL)
		return ;
	lista->prev = last;
	lista->data = conteudo;
	lista->next = NULL;
	if (last == NULL)
		return ;
	last->next = lista;
}
