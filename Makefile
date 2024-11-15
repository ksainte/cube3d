# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ks19 <ks19@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/12 13:51:16 by ks19              #+#    #+#              #
#    Updated: 2024/11/15 12:10:36 by ks19             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc -g
CFLAGS = -Wall -Wextra -Werror
SRCS = src/main.c
LIBFT_PATH = Libft
MLX_PATH = mlx
LIBFT_ARCHIVE = $(LIBFT_PATH)/libft.a
MLX_ARCHIVE = $(MLX_PATH)/libmlx.a
EXEC_NAME = cube3d
OBJS = $(notdir $(SRCS:.c=.o))
FLAGS = -L Libft -lft -L mlx -lmlx -lm -lbsd -lX11 -lXext 

all: $(MLX_LIB) $(EXEC_NAME)
 
$(EXEC_NAME): $(OBJS) $(LIBFT_ARCHIVE) $(MLX_ARCHIVE)
	$(CC) $(CFLAGS) -o $(EXEC_NAME) $(OBJS) $(FLAGS)
 
$(MLX_ARCHIVE):
	$(MAKE) -C $(MLX_PATH)
	
$(LIBFT_ARCHIVE):
	$(MAKE) -C $(LIBFT_PATH)

%.o: src/%.c
	$(CC) $(CFLAGS) -Imlx -c $< -o $@

clean:
	$(MAKE) -C $(MLX_PATH) clean
	$(MAKE) -C $(LIBFT_PATH) clean
	rm -f $(OBJS)

fclean: clean
	$(MAKE) -C $(LIBFT_PATH) fclean
	rm -f $(EXEC_NAME)

re: fclean all

.PHONY: all
