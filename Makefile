NAME		= fractol

CC			= cc
INC			= ./
CFLAGS		= -g -Wall -Wextra -Werror -I./
RM			= rm -f
OBJ_PATH 	= ./obj/

SRC		= fractol.c \
	  

OBJ	= $(SRC:.c=.o)
OBJ_FILES = $(addprefix $(OBJ_PATH), $(OBJ))

all: $(OBJ_FILES) $(NAME)

$(OBJ_PATH)%.o: %.c
	mkdir -p $(dir $@)
	$(CC) -g $(CFLAGS) -I $(INC) -c $< -o $@

$(OBJ_FILES): $(SRC)	

$(NAME):	$(OBJ_FILES)
	$(CC) -g $(CFLAGS) -I $(INC) $(OBJ_FILES) -o $(NAME)

clean:
	@$(RM) $(OBJ) $(OBJ_FILES)
	@rm -rf $(OBJ_PATH)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re

#-fsanitize=address -fsanitize=undefined -fno-sanitize-recover=all -fsanitize=float-divide-by-zero -fsanitize=float-cast-overflow -fno-sanitize=null -fno-sanitize=alignment