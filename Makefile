NAME        = fractol
FRAMEWORKS  = -framework OpenGL -framework AppKit
INC         = -I ./include/ -I$(MLX_PATH)
CFLAGS      = -g -Wall -Wextra -Werror $(INC)
RM          = rm -f
OBJ_PATH    = ./obj/
MLX         = ./minilibx_opengl_20191021/libmlx.a
MLX_PATH    = ./minilibx_opengl_20191021/

SRC = fractol.c \
      init.c \
      julia.c \
      mandelbrot.c \
      tricorn.c \
      img01.c \
      img02.c \
      operations01.c \
      operations02.c \
      utils.c \

OBJ = $(SRC:.c=.o)
OBJ_FILES = $(addprefix $(OBJ_PATH), $(OBJ))

all: $(MLX) $(NAME)

$(OBJ_PATH)%.o: %.c
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ_FILES) $(MLX)
	$(CC) $(FRAMEWORKS) $(OBJ_FILES) -o $(NAME) $(MLX) 

clean:
	@$(RM) $(OBJ) $(OBJ_FILES)
	@rm -rf $(OBJ_PATH)

fclean: clean
	@$(RM) -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
