# Simple Makefile for the RPN calculator
NAME = rpn_calc
SRC  = rpn_calc.c stack.c
OBJ  = $(SRC:.c=.o)
CC   = cc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re