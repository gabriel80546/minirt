
#include "list.h"

t_list	*last_item(t_list *lista)
{
	t_list *temp_list;

	if (lista == NULL)
		return NULL;
	while (lista != NULL)
	{
		temp_list = lista;
		lista = lista->next;
	}
	return (temp_list);
}
