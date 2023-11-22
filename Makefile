##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## Makefile of Setting Up
##

SRC = main.c\
      my_putchar.c\
      my_putstr.c\
      my_get_number.c\
      bootstrap.c\
      bsq.c

OBJ = $(SRC:.c=.o)

NAME = setting_up

all: $(NAME)

$(NAME): $(OBJ)
	gcc -o $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re
