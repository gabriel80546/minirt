
#include "list.h"

void	clear_list(t_list *lista)
{
	t_list *last;

	while (lista != NULL)
	{
		last = lista;
		lista = lista->prev;
	}
	lista = last;
	while (lista != NULL)
	{
		last = lista;
		lista = lista->next;
		free(last);
	}
}
