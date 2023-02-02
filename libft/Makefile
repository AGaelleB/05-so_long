# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abonnefo <abonnefo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/09 12:06:57 by abonnefo          #+#    #+#              #
#    Updated: 2023/01/31 15:46:55 by abonnefo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror

SRC = ft_split.c \
	ft_strdup.c \
	ft_strlen.c \

OBJS = $(SRC:.c=.o)

AR = ar rcs

RM = rm -f

%.o:%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)



all : $(NAME)

clean : 
	$(RM) $(OBJS) 

fclean : clean 
	$(RM) $(NAME)

re : fclean all

so:
	$(CC) -nostartfiles -fPIC $(CFLAGS) $(SRC)
	gcc -nostartfiles -shared -o libft.so $(OBJS)

.PHONY: all clean fclean re