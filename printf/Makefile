# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marvin <marvin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/15 19:32:33 by hfuki             #+#    #+#              #
#    Updated: 2025/07/21 18:33:06 by marvin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Werror -Wextra
SRCS = ft_printf.c printf_handle1.c printf_handle2.c printf_utils.c
OBJS = $(SRCS:.c=.o)

LIBFT_DIR = ../libft
LIBFT = $(LIBFT_DIR)/libft.a

all : $(NAME)

$(NAME) : $(OBJS)
	make -C $(LIBFT_DIR)
	cp $(LIBFT) $(NAME)
	ar rcs $(NAME) $(OBJS)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	rm -f $(OBJS)
	make clean -C $(LIBFT_DIR)

fclean : clean
	rm -f $(NAME)
	make fclean -C $(LIBFT_DIR)

re : fclean all

.PHONY : all clean fclean re
