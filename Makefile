NAME		= fractol

CC			= cc
INC			= -I ./include/ -I$(MLX_PATH)
CFLAGS		= -g -Wall -Wextra -Werror $(INC)
RM			= rm -f
OBJ_PATH 	= ./obj/
MLX			= -L$(MLX_PATH) -lmlx -lXext -lX11 -lm -lbsd
MLX_PATH	= ./include/minilibx-linux/

SRC		= fractol.c \
		init.c \
		julia.c \
		mandelbrot.c \
		tricorn.c \
		img01.c \
		img02.c \
		operations01.c \
		operations02.c \
		utils.c \

OBJ	= $(SRC:.c=.o)
OBJ_FILES = $(addprefix $(OBJ_PATH), $(OBJ))

all: $(NAME)

$(OBJ_PATH)%.o: %.c
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

$(OBJ_FILES): $(SRC)	

$(NAME): $(OBJ_FILES)
	$(CC) $(OBJ_FILES) -o $(NAME) $(MLX)

clean:
	@$(RM) $(OBJ) $(OBJ_FILES)
	@rm -rf $(OBJ_PATH)

fclean: clean
	@$(RM) -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

#-framework OpenGL -framework AppKit ----- for Apple
#-fsanitize=address -fsanitize=undefined -fno-sanitize-recover=all -fsanitize=float-divide-by-zero -fsanitize=float-cast-overflow -fno-sanitize=null -fno-sanitize=alignment