//i dont understand and i did it with ai

// ft_list.h
#ifndef FT_LIST_H
# define FT_LIST_H

typedef struct s_list
{
    struct s_list *next;
    void          *data;
} t_list;

#endif

// ft_list_size.c
#include "ft_list.h"

int	ft_list_size(t_list *begin_list)
{
	int count = 0;

	while (begin_list)
	{
		count++;
		begin_list = begin_list->next;
	}
	return (count);
}

// test.c (main fonksiyonuyla test)
#include <stdio.h>
#include <stdlib.h>
#include "ft_list.h"

t_list *new_node(void *data)
{
	t_list *node = malloc(sizeof(t_list));
	if (!node)
		return (NULL);
	node->data = data;
	node->next = NULL;
	return (node);
}

int main(void)
{
	t_list *a = new_node("Hello");
	t_list *b = new_node("World");
	t_list *c = new_node("42");

	// listeyi birbirine bağla
	a->next = b;
	b->next = c;

	printf("List size: %d\n", ft_list_size(a));     // 3 yazmalı
	printf("List size: %d\n", ft_list_size(NULL));  // 0 yazmalı

	// Bellek temizleme (zorunlu değil ama iyi alışkanlık)
	free(a);
	free(b);
	free(c);
}

