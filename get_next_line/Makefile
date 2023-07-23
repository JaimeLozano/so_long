# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jlozano- <jlozano-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/06 22:47:27 by jlozano-          #+#    #+#              #
#    Updated: 2023/07/07 02:17:43 by jlozano-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= get_next_line.a
SRC		= get_next_line.c get_next_line_utils.c

OBJ		= $(SRC:c=o)
CC		= cc
CFLAGS	= -Wall -Werror -Wextra
AR		= ar -rc
RM		= rm -f

all : $(NAME)

$(NAME): $(OBJ)
	$(AR) $(NAME) $(OBJ)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus