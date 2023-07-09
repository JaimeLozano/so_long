# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jlozano- <jlozano-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/28 22:28:45 by jlozano-          #+#    #+#              #
#    Updated: 2023/07/07 02:05:36 by jlozano-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= so_long
SRC		= src/main.c \
			src/game.c
OBJ		= $(SRC:c=o)
CC		= cc
CFLAGS	= -Wall -Werror -Wextra
RM		= rm -f

# minilibx
MLX_INC		= -I /usr/local/lib
MLX_LIB		= -L /usr/local/include

# ft_printf
FT_PRINTF_NAME	= ft_printf.a
FT_PRINTF_DIR	= ft_printf
FT_PRINTF		= $(addprefix $(FT_PRINTF_DIR)/, $(FT_PRINTF_NAME))

# get_next_line
GNL_NAME	= get_next_line.a
GNL_DIR	= get_next_line
GNL		= $(addprefix $(GNL_DIR)/, $(GNL_NAME))

# so_long
SO_LONG_INC_DIR = inc
SO_LONG_INC_NAME = main.h
SO_LONG_INC	= $(addprefix $(SO_LONG_INC_DIR)/, $(SO_LONG_INC_NAME))

all: $(NAME)

$(NAME): $(OBJ)
	make -C $(FT_PRINTF_DIR)
	make -C $(GNL_DIR)
	$(CC) $(OBJ) $(GNL) $(FT_PRINTF) $(MLX_INC) $(MLX_LIB) -lmlx -framework OpenGL -framework AppKit -o $(NAME)

clean:
	$(RM) $(OBJ)
	make clean -sC $(FT_PRINTF_DIR)
	make clean -sC $(GNL_DIR)

fclean: clean
	$(RM) $(NAME)
	make fclean -sC $(FT_PRINTF_DIR)
	make fclean -sC $(GNL_DIR)

re: fclean all

.PHONY: clean all fclean re