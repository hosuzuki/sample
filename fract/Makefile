NAME = fractol
CC = gcc
FLAGS = -Wall -Werror -Wextra 
LIB = ./libft/libft.a
MLX = ./minilibx-linux/libmlx.a
LIBRARIES = -L/usr/X11R6/lib  -lmlx -lX11 -lXext -framework OpenGL -framework AppKit -L ./minilibx-linux/

#-L ./libft/ -L ./minilibx-linux/

SRC = ./srcs/mandel.c 

GREEN = \033[0;32m
RED = \033[0;31m
RESET = \033[0m
OBJ = $(SRC:.c=.o)
HEAD = -I ./includes
RM = rm -f

all : $(NAME)

$(NAME) : $(LIB) $(MLX) $(OBJ)
	$(CC) $(FLAGS) $(OBJ) $(LIBRARIES) $(LIB) $(MLX) -o $(NAME)
	@echo "$(NAME): $(GREEN)object files were created$(RESET)"
	@echo "$(NAME): $(GREEN)$(NAME) was created$(RESET)"

.c.o :
	$(CC) $(FLAGS) -c $< -o $(<:.c=.o) $(HEAD)

$(LIB) : 
	@echo "$(NAME): $(GREEN)Creating $(LIB)...$(RESET)"
	$(MAKE) -sC ./libft

$(MLX) :
	@echo "$(NAME): $(GREEN)Creating $(MLX)...$(RESET)"
	$(MAKE) -sC ./minilibx-linux 2>/dev/null

clean :
	$(MAKE) clean -sC ./libft
	$(RM) $(OBJ) $(BONUS_OBJ)
	@echo "$(NAME): $(GREEN)object files were deleted$(RESET)"

fclean : clean
	$(MAKE) fclean -sC ./libft
	$(MAKE) clean -sC ./minilibx-linux
	$(RM) $(NAME) $(BONUS_NAME)
	@echo "$(NAME): $(GREEN)$(NAME) was deleted$(RESET)"

re : fclean all

.PHONY: all clean fclean re
