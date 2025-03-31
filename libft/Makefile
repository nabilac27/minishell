# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nchairun <nchairun@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/07 23:49:33 by nchairun          #+#    #+#              #
#    Updated: 2025/03/31 04:39:43 by nchairun         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libft.a
CC		= cc
CFLAGS	= -Wall -Wextra -Werror

AR		= ar rcs

SRCS	= $(shell find . -iname "*.c")
OBJS	= $(SRCS:./%.c=./build/%.o)

.SILENT:

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(NAME) $^

./build/%.o: ./%.c
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re