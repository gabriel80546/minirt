#include "list.h"

void	clear_list(t_list *lista)
{
	t_list	*last;

	lista = first_item(lista);
	while (lista != NULL)
	{
		last = lista;
		lista = lista->next;
		free(last);
	}
}
