#include "list.h"
#include <stdio.h>
#include <stdlib.h>

int cycle_detector(const t_list *list)
{
    const t_list *slow;
    const t_list *fast;

    slow = list;
    fast = list;
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
            return (1);
    }
    return (0);
}
#include "list.h"
#include <stdio.h>
#include <stdlib.h>

int cycle_detector(const t_list *list);

int main(void)
{
    t_list *a = malloc(sizeof(t_list));
    t_list *b = malloc(sizeof(t_list));
    t_list *c = malloc(sizeof(t_list));

    a->data = 1; b->data = 2; c->data = 3;

    // cycle oui
    a->next = b; b->next = c; c->next = NULL;
    printf("cycle ? %d\n", cycle_detector(a)); // 0

    // cycle non
    c->next = a;
    printf("cycle ? %d\n", cycle_detector(a)); // 1


    return 0;
}

