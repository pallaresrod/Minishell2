##
## EPITECH PROJECT, 2025
## Makefile
## File description:
## makefile minishell
##

SRC		=	src/minishell.c \
			src/command_manager.c \
			src/aux_command.c \
			src/env_manager.c \
			src/aux_env.c \
			src/path.c \
			src/builtins/builtins.c \
			src/builtins/builtin_cmd.c \
			src/builtins/builtin_env.c \
			src/aux_array.c \
			src/helper_array.c \
			src/semicolon.c \
			src/redirections.c

OBJ		=	$(SRC:.c=.o)

NAME 	=	mysh

all:	$(NAME)

$(NAME):	$(OBJ)
	make -C ./lib/my
	gcc $(SRC) -o $(NAME) -L./lib/my -lmy -g3
	make clean
	echo -e "\033[0;35m\nMakefile of $(NAME) compiled successfully.\033[0m"

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re:	fclean all
