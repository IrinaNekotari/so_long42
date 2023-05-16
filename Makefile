# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nmascrie <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/14 12:35:47 by nmascrie          #+#    #+#              #
#    Updated: 2023/04/14 12:35:49 by nmascrie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= so_long

CC		= clang
FLAG		= -Wall -Wextra -Werror

LIBFT_PATH	= ./libft/

LIBFT_FILE	= libft.a
MLX_FILE	= libmlx.a

LIBFT_LIB	= $(addprefix $(LIBFT_PATH), $(LIBFT_FILE))
MLX_FLAG	= -lX11 -lXext
MLX_PATH	= ./minilibx-linux/
MLX_LIB	= $(addprefix $(MLX_PATH), $(MLX_FILE))
MLX_EX		= $(MLX_LIB) $(MLX_FLAG)

C_FILE		= main.c coins.c movement.c metrics.c images.c rect.c pos.c memory.c render_char.c render_backgrounds.c mouse_handler.c end_handler.c map_reader.c map_checker.c check_paths.c recur.c

SRC_DIR	= ./src/
INC_DIR	= ./includes/

SRC		= $(addprefix $(SRC_DIR),$(C_FILE))
OBJ		= $(SRC:.c=.o)

.c.o:
	$(CC) $(FLAG) -c $< -o $@

all: $(NAME)

lib:
	@echo "\033[0;33m\Compilation de la libft ...\n"
	@make -C $(LIBFT_PATH)
	@echo "\033[1;32mLibft compilee.\n"

mlx:
	@echo "\033[0;33m\nCompilation de la minilibx ...\n"
	@make -sC $(MLX_PATH)
	@echo "\033[1;32mMinilibx compilee.\n"

$(NAME): lib mlx $(OBJ)
	@echo "\033[0;33m\nCompilation du programme ...\n"
	$(CC) $(OBJ) $(LIBFT_LIB) $(MLX_EX) -o $(NAME)
	@echo "\033[1;32m./so_long compilee\n"

clean:
	@echo "\033[0;31mSuppression de la minilibx ...\n"
	@make clean -sC $(MLX_PATH)
	@echo "\033[0;31mSuppression de la libft ...\n"
	@make clean -sC $(LIBFT_PATH)
	@echo "\033[1;Termine\n"
	@echo "\033[0;31mSuppression des fichiers so_long ...\n"
	@rm -f $(OBJ)
	@echo "\033[1;32mOkay :)\n"

fclean: clean
	@echo "\033[0;31mSuppression de l'executable ..."
	@rm -f $(NAME)
	@make fclean -C $(LIBFT_PATH)
	@echo "\033[1;32mOkay :)\n"

re: fclean all

.PHONY: all clean fclean re
