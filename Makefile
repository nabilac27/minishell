# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nchairun <nchairun@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/31 04:29:14 by nchairun          #+#    #+#              #
#    Updated: 2025/04/01 06:51:52 by nchairun         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:=	minishell

LIBFT_DIR	:= ./include/libft
LIBFT_OBJS	:= $(shell find ./include/libft/build -iname "*.o")
LIBFT 		:= $(LIBFT_DIR)/libft.a

CC			:=	cc
CFLAGS		:=	-Wextra -Wall -Werror

SRCS		:=	$(shell find ./src -iname "*.c")
OBJS		:=	$(SRCS:./src/%.c=./build/%.o)

.SILENT:

all: $(NAME)

$(NAME): $(OBJS)
	make -C $(LIBFT_DIR)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT) -lreadline

./build/%.o: ./src/%.c
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)
	[ -d $(LIBFT_DIR)/build/libft ] && rm -f $(LIBFT_DIR)/build/libft/*.o || true
    
fclean: clean
	rm -f $(NAME)
	rm -f $(LIBFT)
	rm -f $(LIBFT_OBJS)

re: fclean all
