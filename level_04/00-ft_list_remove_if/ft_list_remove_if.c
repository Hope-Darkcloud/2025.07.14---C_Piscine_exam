#include <stdlib.h>
#include "ft_list.h"

void ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
{
    t_list *current;
    t_list *tmp;

    while (*begin_list && cmp((*begin_list)->data, data_ref) == 0)
    {
        tmp = *begin_list;
        *begin_list = (*begin_list)->next;
        free(tmp);
    }
    current = *begin_list;
    while (current && current->next)
    {
        if (cmp(current->next->data, data_ref) == 0)
        {
            tmp = current->next;
            current->next = tmp->next;
            free(tmp);
        }
        else
            current = current->next;
    }
}

