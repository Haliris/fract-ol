# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jteissie <jteissie@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/28 10:56:18 by jteissie          #+#    #+#              #
#    Updated: 2024/07/04 15:49:16 by jteissie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

CCFLAGS = -Wall -Werror -Wextra -g3 -MMD

NAME = fractol

SRC_FILES = main.c \
			utils.c \
			init.c \
			events.c \
			palettes.c \
			interpolate_color.c \
			palette_utils.c \
			mandelbrot.c \
			julia.c \
			burning_ship.c

INCLUDE = 	-I include/ \
			-I minilibx-linux \
			-I libft/

LIBFT_DIR = libft/

LIBFT_LINK = -L $(LIBFT_DIR) -lft

MLX_DIR = minilibx-linux/

MLX_LINK = -L $(MLX_DIR) -lmlx -lXext -lX11 -lXext -lm -lz -Ofast

OBJ_DIR = obj/

vpath %.c src

OBJ_FILES = $(patsubst %.c, $(OBJ_DIR)%.o, $(SRC_FILES))
DEPS = $(OBJ_FILES:$(OBJ_DIR)%.o=%.d)

all : minilibx-linux $(NAME)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR) $(addprefix $(OBJ_DIR), $(sort $(dir $(SRC_FILES))))

$(OBJ_DIR)%.o: %.c | $(OBJ_DIR)
	mkdir -p $(dir $@)
	$(CC) $(CCFLAGS) -c $< $(INCLUDE) -o $@

$(NAME): $(OBJ_FILES)
	make -C $(LIBFT_DIR) all
	make -C $(MLX_DIR) all
	$(CC) $(CCFLAGS) $(OBJ_FILES) $(LIBFT_LINK) $(MLX_LINK) -o $(NAME)

minilibx-linux :
	git clone git@github.com:42Paris/minilibx-linux.git $@

clean :
	make -C $(LIBFT_DIR) clean
	make -C $(MLX_DIR) clean
	rm -rf $(OBJ_DIR)

fclean : clean
	rm -rf $(LIBFT_DIR)libft.a
	rm -rf $(MLX_DIR)
	rm -rf $(NAME)

re : fclean clean all

.PHONY : all clean fclean re bonus
-include $(DEPS)
