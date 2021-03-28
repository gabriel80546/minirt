
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

#endif