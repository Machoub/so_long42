# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: machouba <machouba@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/04 12:16:13 by machouba          #+#    #+#              #
#    Updated: 2024/05/06 17:43:54 by machouba         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	so_long
LIBFT_PATH	=	./libft
LIBFT	=	$(LIBFT_PATH)/libft.a
CC = cc
CFLAGS	=	-Wall -Wextra -Werror -I$(LIBFT) 		
XFLAGS	=	-Lmlx_linux -Imlx_linux -lX11 -lXext -lm -lz -Ofast
MLX_PATH	=	minilibx-linux
LIB_MLX	=	$(MLX_PATH)/libmlx.a
RM	=	rm -f
AR	=	ar -rcs

SOURCES = ./sources/

MAP = $(addprefix map/, correct_map.c init_map.c map_utils.c parsing_map.c path_utils.c path_valid.c)
DISPLAY = $(addprefix aff/, display_utils.c display.c render_map.c)
MOUV = $(addprefix mouv/, move_down.c move_up.c move_left.c move_right.c move_utils.c)
GAME = $(addprefix $(SOURCES), $(MAP) $(DISPLAY) $(MOUV) so_long.c end_game.c)

SRC = $(GAME)	
OBJECTS	= $(SRC:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJECTS)
	$(MAKE) -C $(MLX_PATH)
	$(MAKE) -C $(LIBFT_PATH)
	cp $(LIB_MLX) $(NAME)
	cp $(LIBFT) $(NAME)
	@$(CC) $(CFLAGS) $(OBJECTS) $(LIB_MLX) $(XFLAGS) $(LIBFT) -o $(NAME)

clean:
	$(MAKE) clean -C $(LIBFT_PATH)
	$(MAKE) clean -C $(MLX_PATH)
	$(RM) $(OBJECTS)

fclean:	clean
	$(MAKE) fclean -C $(LIBFT_PATH)
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re