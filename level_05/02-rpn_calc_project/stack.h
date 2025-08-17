#ifndef STACK_H
#define STACK_H

#include <stdlib.h>

typedef struct	s_node
{
	int				value;
	struct s_node	*next;
}				t_node;

typedef struct s_stack
{
	t_node *top;
}				t_stack;

/* Stack API (only uses malloc/free under the hood) */
void	stack_init(t_stack *st);
int		stack_is_empty(t_stack *st);
int		stack_push(t_stack *st, int v);
int		stack_pop(t_stack *st, int *out);
void	stack_clear(t_stack *st);

#endif /* STACK_H */