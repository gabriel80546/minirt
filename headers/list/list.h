
#ifndef LIST_H
# define LIST_H

# include <stdlib.h>

typedef struct		s_list
{
    struct s_list	*next;
    void			*data;
    struct s_list	*prev;
}					t_list;

t_list	*list_init(void	*conteudo);
void	list_add(t_list *lista, void *conteudo);
void	clear_list(t_list *lista);
void	clear_list_all(t_list *lista);
t_list	*first_item(t_list *lista);
t_list	*last_item(t_list *lista);
t_list	*list_delone(t_list *lista);
t_list	*list_delone_free(t_list *lista);

#endif