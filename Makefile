# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ceccentr <ceccentr@42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/06/10 17:01:50 by ceccentr          #+#    #+#              #
#    Updated: 2020/08/14 11:10:14 by ceccentr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


SRCS = config.c clear_buf.c ft_parse_map.c ft_color.c ft_map.c \
gnl/get_next_line.c gnl/get_next_line_utils.c main.c ft_exit.c \
ft_parse_position.c ft_new_elem.c ft_puck_rgb.c my_mlx_pixel_put.c \
my_mlx_pixel_take.c ft_render.c ft_search_texture_id.c ft_key.c \
ft_check_wall.c ft_sprite.c ft_ceilling.c ft_floor.c ft_load_picture.c \
ft_check_wh.c ft_sort.c ft_screenshot.c ft_shoot.c
RAY = ft_ray.c
BONUS_SRCS = bonus/ft_minimap_bonus.c bonus/ft_health_bonus.c \
bonus/ft_hand_bonus.c bonus/ft_ray_bonus.c

NAME = Cub3D
NAME_BONUS = Cub3D_BONUS

GCC_FLAG = -Wall -Werror -Wextra
CC = gcc $(GCC_FLAG)
LIBS = -Lmlx/ -lmlx -Llibft/ -lft -framework OpenGL -framework Appkit

HEADER = cub3d.h
HEADER_BONUS = bonus/cub3d_bonus.h

OBJS = $(SRCS:.c=.o)
OBJ_RAY = $(RAY:.c=.o)
BONUS_OBJS = $(BONUS_SRCS:.c=.o)

all: lib_ft minilibx $(NAME)
bonus: all $(NAME_BONUS)

lib_ft:
	make -C libft/
	
minilibx:
	make -C mlx/

$(OBJS): %.o: %.c $(HEADER)
	$(CC) -c $< -o $@ -g

$(OBJ_RAY): %.o: %.c $(HEADER)
	$(CC) -c $< -o $@ -g

$(NAME): $(OBJS) $(OBJ_RAY)
	$(CC) -o $@ $^ $(LIBS)

$(BONUS_OBJS): %.o: %.c $(HEADER_BONUS)
	$(CC) -c $< -o $@ -g

$(NAME_BONUS): $(OBJS) $(BONUS_OBJS)
	$(CC) -o $@ $^ $(LIBS)

clean:
	rm -f $(OBJS)
	rm -f $(OBJ_RAY)
	rm -f $(BONUS_OBJS)
	make -C libft/ clean
	make -C mlx/ clean

fclean: clean
	rm -f $(NAME)
	rm -f $(NAME_BONUS)
	make -C libft/ fclean
	make -C mlx/ clean

re: fclean all