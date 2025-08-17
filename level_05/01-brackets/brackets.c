#include <unistd.h>

int is_opening(char c)
{
    return (c == '(' || c == '[' || c == '{');
}

int is_closing(char c)
{
    return (c == ')' || c == ']' || c == '}');
}

int matches(char open, char close)
{
    return ((open == '(' && close == ')') ||
            (open == '[' && close == ']') ||
            (open == '{' && close == '}'));
}

int check_brackets(char *str)
{
    char stack[4096]; // basit bir stack
    int top = -1;

    while (*str)
    {
        if (is_opening(*str))
            stack[++top] = *str;
        else if (is_closing(*str))
        {
            if (top == -1 || !matches(stack[top], *str))
                return (0); // Error
            top--;
        }
        str++;
    }
    return (top == -1); // stack boşsa OK
}

int main(int ac, char **av)
{
    int i;

    if (ac < 2)
    {
        write(1, "\n", 1);
        return (0);
    }
    i = 1;
    while (i < ac)
    {
        if (check_brackets(av[i]))
            write(1, "OK\n", 3);
        else
            write(1, "Error\n", 6);
        i++;
    }
    return (0);
}

