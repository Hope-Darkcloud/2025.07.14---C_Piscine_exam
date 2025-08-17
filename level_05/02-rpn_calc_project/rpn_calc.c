#include <stdio.h>
#include <unistd.h>
#include "stack.h"

/* Allowed functions: atoi, printf, write, malloc, free
   We implement our own simple parser; no strtok/ctype. */

static int	is_space(char c)
{
	return (c == ' ' || c == '\t' || c == '\n' || c == '\r' || c == '\v' || c == '\f');
}

static int	is_digit(char c)
{
	return (c >= '0' && c <= '9');
}

/* Parse an int starting at s[pos]. Accept optional leading + or -.
   On success, writes the parsed value to *out and returns the number
   of characters consumed (>0). On failure, returns 0. */
static int	parse_int_token(const char *s, int *out)
{
	int i = 0;
	int sign = 1;
	long acc = 0;
	if (s[i] == '+' || s[i] == '-')
	{
		if (s[i] == '-')
			sign = -1;
		/* Distinguish operator '+'/'-' from signed number: require a digit after the sign */
		if (!is_digit(s[i + 1]))
			return (0);
		i++;
	}
	if (!is_digit(s[i]))
		return (0);
	while (is_digit(s[i]))
	{
		acc = acc * 10 + (s[i] - '0');
		/* We skip strict overflow checking: problem statement guarantees operands fit in int. */
		i++;
	}
	*out = (int)(sign * acc);
	return (i);
}

/* Returns:
   1 if operator token parsed and *op set to one of + - * / %,
   0 if not an operator token,
  -1 on invalid (e.g., multi-char non-number).
   An operator token must be exactly one character and be followed by space or end. */
static int	parse_operator_token(const char *s, char *op)
{
	if (s[0] && (s[0] == '+' || s[0] == '-' || s[0] == '*' || s[0] == '/' || s[0] == '%'))
	{
		/* Disambiguate from signed numbers: a standalone operator must be a single-char token. */
		if (is_digit(s[1]))
			return (0);
		*op = s[0];
		return (1);
	}
	return (0);
}

static int	eval_rpn(const char *expr, int *result)
{
	t_stack st;
	int i = 0;
	int pushed_count = 0;
	stack_init(&st);

	/* Empty or only spaces -> error */
	while (expr[i] && is_space(expr[i]))
		i++;
	if (expr[i] == '\0')
	{
		write(1, "Error\n", 6);
		return (0);
	}

	while (expr[i])
	{
		while (expr[i] && is_space(expr[i]))
			i++;
		if (!expr[i])
			break;

		/* Try parse operator first (standalone one-char token) */
		char op = 0;
		int consumed = 0;
		int val = 0;
		int was_op = parse_operator_token(&expr[i], &op);
		if (was_op == 1)
		{
			consumed = 1;
			/* After operator, next char must be space or end */
			if (expr[i + consumed] && !is_space(expr[i + consumed]))
			{
				stack_clear(&st);
				return (0);
			}
			int b, a;
			if (!stack_pop(&st, &b) || !stack_pop(&st, &a))
			{
				stack_clear(&st);
				return (0);
			}
			long r = 0;
			if (op == '+') r = (long)a + (long)b;
			else if (op == '-') r = (long)a - (long)b;
			else if (op == '*') r = (long)a * (long)b;
			else if (op == '/')
			{
				if (b == 0) { stack_clear(&st); return (0); }
				r = a / b;
			}
			else if (op == '%')
			{
				if (b == 0) { stack_clear(&st); return (0); }
				r = a % b;
			}
			/* Push result back */
			if (!stack_push(&st, (int)r))
			{
				stack_clear(&st);
				return (0);
			}
		}
		else
		{
			/* Try parse number token */
			consumed = parse_int_token(&expr[i], &val);
			if (consumed <= 0)
			{
				stack_clear(&st);
				return (0);
			}
			if (!stack_push(&st, val))
			{
				stack_clear(&st);
				return (0);
			}
			pushed_count++;
		}
		i += consumed;
		/* After token, require end or space */
		if (expr[i] && !is_space(expr[i]))
		{
			stack_clear(&st);
			return (0);
		}
	}

	/* After processing, exactly one value must remain */
	int final;
	if (!stack_pop(&st, &final) || !stack_is_empty(&st))
	{
		stack_clear(&st);
		return (0);
	}
	stack_clear(&st);
	*result = final;
	return (1);
}

int	main(int argc, char **argv)
{
	int res;

	if (argc != 2)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	if (!eval_rpn(argv[1], &res))
	{
		write(1, "Error\n", 6);
		return (0);
	}
	printf("%d\n", res);
	return (0);
}