##
## EPITECH PROJECT, 2024
## Task01 Makefild library
## File description:
## This file complies and creates the libmy.a
##

SRC	=	my_putchar.c \
		my_putstr.c \
		my_strlen.c \
		my_strdup.c \
		my_strcat.c \
		my_strcpy.c \
		my_strncmp.c \
		init_malloc.c \
		my_strtok.c \
		free_array.c \
		my_getnbr.c \
		my_strcmp.c \
		my_strchr.c \
		my_isspace.c \
		my_realloc.c

OBJ	=	$(SRC:.c=.o)

NAME	=	libmy.a

all: $(NAME) clean

$(NAME): $(OBJ)
	gcc -c $(SRC) -I../../include
	ar rc $(NAME) $(OBJ)

clean:
	rm -f *.o
