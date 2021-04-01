
#include "list.h"
#include <stdio.h>

int main()
{
	t_list *lista;
	t_list *temp_list;
	t_list *save_to_delete;
	int		conteudo[5];

	conteudo[0] = 42;
	conteudo[1] = 56;
	conteudo[2] = 99;
	// conteudo[3] = 88;
	// conteudo[8] = 777;
	lista = list_init(&conteudo[0]);
	printf("\n");
	printf("84: main =>\n");
	printf("\n");
	list_add(lista, &conteudo[1]);
	list_add(lista, &conteudo[2]);
	// list_add(lista, &conteudo[3]);
	while (lista != NULL)
	{
		printf("91: lista = %p\n", lista);
		printf("92: prev  = %p\n", lista->prev);
		printf("93: data  = %p\n", lista->data);
		printf("94: next  = %p\n", lista->next);
		printf("95: lista = %p\n", lista);
		printf("96: loop, item = %d\n\n", *((int *)lista->data));
		temp_list = lista;
		lista = lista->next;
	}

	// printf("##@#@@###@@@#@#@@#@#@###@#@#@###@#@#@@#@#@@#@#@@@#@#@#@##@\n");
	// printf("##@#@#@@@###@ agora de traz para frente @#@#@@####@@@##@#@\n");
	// printf("@@###@@@#@@#@#@@@@####@@#@@@@#@#@##@@#@###@@#@#@#@#@####@#\n");
	// printf("\n");

	// save_to_delete = NULL;
	// lista = last_item(temp_list);
	// while (lista != NULL)
	// {
	// 	printf("47: lista = %p\n", lista);
	// 	printf("26: prev  = %p\n", lista->prev);
	// 	printf("27: data  = %p\n", lista->data);
	// 	printf("28: next  = %p\n", lista->next);
	// 	printf("47: lista = %p\n", lista);
	// 	printf("29: loop, item = %d\n\n", *((int *)lista->data));
	// 	if (*((int *)lista->data) == 99)
	// 		save_to_delete = lista;

	// 	temp_list = lista;
	// 	lista = lista->prev;
	// }

	printf("##@#@@###@@@#@#@@#@#@###@#@#@###@#@#@@#@#@@#@#@@@#@#@#@##@\n");
	printf("##@#@#@@@###@#@# agora normal denovo #@#@#@#@@####@@@##@#@\n");
	printf("@@###@@@#@@#@#@@@@####@@#@@@@#@#@##@@#@###@@#@#@#@#@####@#\n");
	printf("\n");
	
	save_to_delete = NULL;
	lista = first_item(temp_list);
	while (lista != NULL)
	{
		printf("132: lista = %p\n", lista);
		printf("133: prev  = %p\n", lista->prev);
		printf("134: data  = %p\n", lista->data);
		printf("135: next  = %p\n", lista->next);
		printf("136: lista = %p\n", lista);
		printf("137: loop, item = %d\n\n", *((int *)lista->data));
		if (*((int *)lista->data) == 99)
			save_to_delete = lista;
		temp_list = lista;
		lista = lista->next;
	}


	printf("##@#@@###@@@#@#@@#@#@###@#@#@###@#@#@@#@#@@#@#@@@#@#@#@##@\n");
	printf("##@#@#@@@###@##@ item para ser deletado @#@#@@####@@@##@#@\n");
	printf("@@###@@@#@@#@#@@@@####@@#@@@@#@#@##@@#@###@@#@#@#@#@####@#\n");
	printf("\n");
	if (save_to_delete != NULL)
	{
		printf("149: lista = %p\n", save_to_delete);
		printf("150: prev  = %p\n", save_to_delete->prev);
		printf("151: data  = %p\n", save_to_delete->data);
		printf("152: next  = %p\n", save_to_delete->next);
		printf("153: lista = %p\n", save_to_delete);
		printf("154: del, item = %d\n\n", *((int *)save_to_delete->data));
		temp_list = list_delone(save_to_delete);
	}

	printf("##@#@@###@@@#@#@@#@#@###@#@#@###@#@#@@#@#@@#@#@@@#@#@#@##@\n");
	printf("##@#@#@@@###@#@# agora normal denovo #@#@#@#@@####@@@##@#@\n");
	printf("@@###@@@#@@#@#@@@@####@@#@@@@#@#@##@@#@###@@#@#@#@#@####@#\n");
	printf("\n");
	
	// printf("temp_list = %p\n", temp_list);
	// printf("lista     = %p\n", lista);
	lista = first_item(temp_list);
	// printf("temp_list = %p\n", temp_list);
	// printf("lista     = %p\n", lista);
	while (lista != NULL)
	{
		printf("169: lista = %p\n", lista);
		printf("170: prev  = %p\n", lista->prev);
		printf("171: data  = %p\n", lista->data);
		printf("172: next  = %p\n", lista->next);
		printf("173: lista = %p\n", lista);
		printf("174: loop, item = %d\n\n", *((int *)lista->data));
		temp_list = lista;
		lista = lista->next;
	}
	clear_list(temp_list);
	return (0);
}