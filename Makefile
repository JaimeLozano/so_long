# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jlozano- <jlozano-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/28 22:28:45 by jlozano-          #+#    #+#              #
#    Updated: 2023/09/08 18:33:30 by jlozano-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= so_long
SRC		= src/main.c			\
			src/game.c			\
			src/map.c			\
			src/hooks.c			\
			src/map_validate.c	\
			src/map_validate_utils.c
OBJ		= $(SRC:.c=.o)
CC		= gcc
CFLAGS	= -Wall -Werror -Wextra -c
#CFLAGS	= -Wall -Werror -Wextra -c -fsanitize=address -g3
RM		= rm -f

# minilibx
LIBMLX_DIR	= /usr/local/include
LIBMLX		= /usr/local/lib/libmlx.a
# LIBMLX_NAME = libmlx.a
# LIBMLX_DIR = mlx
# LIBMLX = $(addprefix $(LIBMLX_DIR)/, $(LIBMLX_NAME))
# MLX_CFLAGS = " -Wno-deprecated-declarations"

# frameworks
FMWK =  -framework OpenGL -framework AppKit 
#FMWK = -lXext -lX11

# libft
LIBFT_DIR	= ft_printf/libft 

# ft_printf
FT_PRINTF_NAME	= ft_printf.a
FT_PRINTF_DIR	= ft_printf
FT_PRINTF		= $(addprefix $(FT_PRINTF_DIR)/, $(FT_PRINTF_NAME))

# get_next_line
GNL_NAME	= get_next_line.a
GNL_DIR		= get_next_line
GNL			= $(addprefix $(GNL_DIR)/, $(GNL_NAME))

# so_long
SO_LONG_INC_DIR		= inc
SO_LONG_INC_NAME	= main.h			\
						game.h			\
						map.h			\
						define.h		\
						structures.h
SO_LONG_INC = $(addprefix $(SO_LONG_INC_DIR)/, $(SO_LONG_INC_NAME))

HEAD_DIR = -I$(LIBMLX_DIR) -I$(LIBFT_DIR) -I$(FT_PRINTF_DIR) -I$(GNL_DIR) -I$(SO_LONG_INC_DIR)

%.o: %.c $(SO_LONG_INC)
	$(CC) $(CFLAGS) $< $(HEAD_DIR) -o $@ 

all: $(NAME)

$(NAME): $(OBJ)
#	make -C $(LIBMLX_DIR)  CFLAGS+=$(MLX_CFLAGS)
	make -C $(FT_PRINTF_DIR)
	make -C $(GNL_DIR)
	$(CC) $(OBJ) -I$(SO_LONG_INC_DIR) $(GNL) $(FT_PRINTF) $(LIBMLX) $(FMWK) -o $(NAME)
#	$(CC) -fsanitize=address -g3 $(OBJ) -I$(SO_LONG_INC_DIR) $(GNL) $(FT_PRINTF) $(LIBMLX) $(FMWK) -o $(NAME)

clean:
	$(RM) $(OBJ)
#	make clean -sC $(LIBMLX_DIR)
	make clean -sC $(FT_PRINTF_DIR)
	make clean -sC $(GNL_DIR)

fclean: clean
	$(RM) $(NAME)
#	make clean -sC $(LIBMLX_DIR)
	make fclean -sC $(FT_PRINTF_DIR)
	make fclean -sC $(GNL_DIR)
re: fclean all

.PHONY: clean all fclean re
