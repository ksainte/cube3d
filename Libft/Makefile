# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ks19 <ks19@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/07 11:24:49 by ksainte           #+#    #+#              #
#    Updated: 2024/11/14 11:43:32 by ks19             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
GCC = gcc -c -Wall -Wextra -Werror -g

SRCS =	ft_strlcat.c ft_isalpha.c ft_isdigit.c ft_strncmp.c ft_isalnum.c \
		ft_memset.c ft_bzero.c ft_memmove.c ft_memcpy.c ft_strlen.c ft_strlcpy.c \
		ft_toupper.c ft_tolower.c ft_strrchr.c ft_strchr.c ft_memchr.c ft_memcmp.c \
		ft_strnstr.c ft_atoi.c ft_isprint.c ft_isascii.c ft_strdup.c ft_calloc.c \
		ft_substr.c ft_strjoin.c ft_split.c ft_itoa.c ft_strtrim.c ft_strmapi.c ft_striteri.c \
		ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_printf.c ft_utils.c get_next_line.c get_next_line_utils.c


SRCS_BONUS = ft_lstnew.c ft_lstadd_front.c ft_lstadd_back.c ft_lstsize.c ft_lstlast.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c *ft_lstmap.c

OBJS = $(SRCS:.c=.o)
OBJS_BONUS = $(SRCS_BONUS:.c=.o)

all: $(NAME)

$(NAME):
	$(GCC) $(SRCS) -I .
	ar rc $(NAME) $(OBJS)

bonus: $(NAME)
	@$(GCC) $(SRCS_BONUS) -I .
	@ar rc $(NAME) $(OBJS_BONUS)

clean:
	/bin/rm -f $(OBJS)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re