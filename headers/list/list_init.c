
#include "list.h"

t_list	*list_init(void	*conteudo)
{
	t_list *saida;

	if (conteudo == NULL)
		return (NULL);
	saida = (t_list *)malloc(sizeof(t_list));
	saida->prev = NULL;
	saida->data = conteudo;
	saida->next = NULL;
	return (saida);
}
