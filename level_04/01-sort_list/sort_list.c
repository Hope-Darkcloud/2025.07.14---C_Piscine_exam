#include "list.h"

t_list *sort_list(t_list* lst, int (*cmp)(int, int))
{
    int tmp;
    t_list *i;
    t_list *j;

    if (!lst)
        return NULL;

    i = lst;
    while (i)
    {
        j = i->next;
        while (j)
        {
            if (!cmp(i->data, j->data))
            {
                tmp = i->data;
                i->data = j->data;
                j->data = tmp;
            }
            j = j->next;
        }
        i = i->next;
    }
    return lst;
}

