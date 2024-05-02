# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: machouba <machouba@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/04 12:16:13 by machouba          #+#    #+#              #
#    Updated: 2024/01/19 16:39:30 by machouba         ###   ########.fr        #
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

SOURCES = \
	so_long.c \
	end_game.c \
	init_map.c \

	
OBJECTS	= $(SOURCES:.c=.o)

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