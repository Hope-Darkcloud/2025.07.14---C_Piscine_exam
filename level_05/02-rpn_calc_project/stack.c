#include "stack.h"

void	stack_init(t_stack *st)
{
	st->top = NULL;
}

int	stack_is_empty(t_stack *st)
{
	return (st->top == NULL);
}

int	stack_push(t_stack *st, int v)
{
	t_node *n = (t_node *)malloc(sizeof(t_node));
	if (!n)
		return (0);
	n->value = v;
	n->next = st->top;
	st->top = n;
	return (1);
}

int	stack_pop(t_stack *st, int *out)
{
	t_node *n;

	if (st->top == NULL)
		return (0);
	n = st->top;
	if (out)
		*out = n->value;
	st->top = n->next;
	free(n);
	return (1);
}

void	stack_clear(t_stack *st)
{
	int tmp;
	while (stack_pop(st, &tmp))
		;
}