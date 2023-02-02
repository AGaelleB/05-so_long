# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abonnefo <abonnefo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/16 10:23:59 by abonnefo          #+#    #+#              #
#    Updated: 2023/01/30 17:36:16 by abonnefo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC = gcc

CFLAGS = -Wall -Wextra #-Werror -g3

SRCS = srcs/so_long.c \
	srcs/check_items.c \
	srcs/check_lines_map.c \
	srcs/check_map.c \
	srcs/check_path.c \
	srcs/put_in_tab.c \
	srcs/put_in_window.c \
	srcs/utils.c \
	srcs/key_press.c \
	srcs/move_perso.c \
	srcs/close_window.c \
	libft/GNL/get_next_line.c \
	libft/GNL/get_next_line_utils.c \
	libft/ft_printf/ft_printf.c \
	libft/ft_printf/ft_print_%.c \
	libft/ft_printf/ft_print_c.c \
	libft/ft_printf/ft_print_d.c \
	libft/ft_printf/ft_print_p.c \
	libft/ft_printf/ft_print_s.c \
	libft/ft_printf/ft_print_u.c \
	libft/ft_printf/ft_print_x.c \
	libft/ft_split.c \
	libft/ft_strdup.c \
	libft/ft_strlen.c \

OBJS = $(SRCS:.c=.o)

AR = ar rcs

RM = rm -f

%.o: %.c
	@$(CC) $(CFLAGS) -Iminilibx-Imlx -O3 -c $< -o $@
	@echo "\033[5;36m-gcc *.c in progress\033[0m"


$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -Lminilibx -lmlx -Lminilibx -lXext -lX11 -lm -lz -o $(NAME)
	@echo "\033[1;32m[Make : 'so_long' is done]\033[0m"

all : $(NAME)

clean :
	@$(RM) $(OBJS)
	@echo "\033[1;33m[.o] Object files removed\033[0m"

fclean : clean
	@$(RM) $(NAME)
	@echo "\033[1;33m[.a] Binary file removed\033[0m"


re : fclean all

.PHONY: all clean fclean re