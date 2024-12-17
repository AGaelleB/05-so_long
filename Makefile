# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abonnefo <abonnefo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/16 10:23:59 by abonnefo          #+#    #+#              #
#    Updated: 2024/12/17 14:06:32 by abonnefo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

# Chemins vers les sous-dossiers
LIBFT_DIR = ./libft
PRINTF_DIR = $(LIBFT_DIR)/ft_printf
GNL_DIR = $(LIBFT_DIR)/GNL
MLX_DIR = ./includes/minilibx-linux

# Bibliothèques
LIBFT = $(LIBFT_DIR)/libft.a
PRINTF = $(PRINTF_DIR)/libftprintf.a
GNL = $(GNL_DIR)/libftGNL.a
MLX = $(MLX_DIR)/libmlx.a

# Fichiers sources et objets
SRC_DIR = ./srcs
OBJ_DIR = ./obj
SRC = $(wildcard $(SRC_DIR)/*.c)
OBJ = $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/srcs/%.o)

# Création des sous-dossiers pour les objets
OBJ_SUBDIRS = $(sort $(dir $(OBJ)))

# Flags de compilation
CC = gcc
CFLAGS = -Wall -Wextra -Werror -I ./includes -I $(MLX_DIR)

# Flags pour le linkage
LDFLAGS = -L $(LIBFT_DIR) -lft -L $(PRINTF_DIR) -lftprintf -L $(GNL_DIR) -lftGNL -L $(MLX_DIR) -lmlx -lXext -lX11 -lm

# Règles
all: $(NAME)

$(NAME): $(LIBFT) $(PRINTF) $(GNL) $(MLX) $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(LDFLAGS) -o $(NAME)
	@echo "✅ $(NAME) compiled successfully."

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(PRINTF):
	$(MAKE) -C $(PRINTF_DIR)

$(GNL):
	$(MAKE) -C $(GNL_DIR)

$(MLX):
	$(MAKE) -C $(MLX_DIR)

# Création des fichiers .o dans les sous-dossiers appropriés
$(OBJ_DIR)/%.o: %.c | $(OBJ_SUBDIRS)
	$(CC) $(CFLAGS) -c $< -o $@

# Création des sous-dossiers d'objets si non existants
$(OBJ_SUBDIRS):
	mkdir -p $@

clean:
	$(MAKE) clean -C $(LIBFT_DIR)
	$(MAKE) clean -C $(PRINTF_DIR)
	$(MAKE) clean -C $(GNL_DIR)
	$(MAKE) clean -C $(MLX_DIR)
	rm -rf $(OBJ_DIR)
	@echo "🧹 Object files cleaned."

fclean: clean
	$(MAKE) fclean -C $(LIBFT_DIR)
	$(MAKE) fclean -C $(PRINTF_DIR)
	$(MAKE) fclean -C $(GNL_DIR)
	rm -f $(NAME)
	@echo "🗑️  Full cleanup completed."

re: fclean all

.PHONY: all clean fclean re
