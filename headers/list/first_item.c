
#include "list.h"

t_list	*first_item(t_list *lista)
{
	t_list *temp_list;

	while (lista != NULL)
	{
		temp_list = lista;
		lista = lista->prev;
	}
	return (temp_list);
}
