# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: manelcarvalho <manelcarvalho@student.42    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/29 14:01:22 by mcarvalh          #+#    #+#              #
#    Updated: 2025/01/16 20:17:48 by manelcarval      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol
CC = cc
CFLAGS = -Wall -Wextra -Werror -g

# ASAN_LIB = -fsanitize=address

SRC_DIR = src
OBJ_DIR = obj
INC_DIR = includes

SRC_FILES = $(wildcard $(SRC_DIR)/*.c)
OBJ_FILES = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRC_FILES))

LIBFT_PATH = includes/libft
LIBFT = $(LIBFT_PATH)/libft.a

MLX_PATH = includes/MLX42
MLX = $(MLX_PATH)/build/libmlx42.a

all: $(NAME)

$(NAME): $(OBJ_FILES) $(LIBFT) $(MLX)
	@$(CC) $(FLAGS) -o $@ $^ -L$(MLX_PATH)/build -L$(LIBFT_PATH) -L/opt/homebrew/Cellar/glfw/3.4/lib -lmlx42 -lglfw -framework Cocoa -framework OpenGL -framework IOKit -mmacosx-version-min=15.2
# -lmlx42 -lglfw -ldl -lm -lpthread

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) -I$(INC_DIR) -I$(MLX_PATH) -I$(LIBFT_PATH) -c -o $@ $<

$(LIBFT):
	@$(MAKE) -C $(LIBFT_PATH)

$(MLX):
	@$(MAKE) -C $(MLX_PATH)

clean:
	rm -r $(OBJ_DIR)

fclean: clean
	rm $(NAME)
	$(MAKE) -C $(LIBFT_PATH) fclean


re: fclean all

.PHONY: all clean fclean re


# GREEN = \033[0;32m
# RED = \033[0;31m
# RESET = \033[0m

# CC = cc
# CFLAGS = -Wall -Werror -Wextra
# LIBFT_PATH = include/libft
# MLX_PATH = include/minilibx

# SRC_DIR = src
# OBJ_DIR = obj
# INCLUDE_DIR = include

# SRC_FILES = $(wildcard $(SRC_DIR)/*.c)
# OBJ_FILES = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRC_FILES))

# LIBFT = $(LIBFT_PATH)/libft.a
# MLX = $(MLX_PATH)/libmlx.a

# NAME = fractol

# all: $(NAME)

# $(NAME): $(OBJ_FILES) $(LIBFT) $(MLX)
# 	@$(CC) $(CFLAGS) -o $@ $^ -L$(LIBFT_PATH) -lft -L$(MLX_PATH) -lmlx -framework OpenGL -framework AppKit
# 	@echo "$(NAME): $(GREEN)object files were created$(RESET)"
# 	@echo "$(NAME): $(GREEN)$(NAME) was created$(RESET)"

# $(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
# 	@mkdir -p $(OBJ_DIR)
# 	@$(CC) $(CFLAGS) -I$(INCLUDE_DIR) -I$(LIBFT_PATH) -I$(MLX_PATH) -c -o $@ $<
# 	@echo "$(NAME): $(GREEN)$(OBJ_DIR) was created$(RESET)"

# $(LIBFT):
# 	@$(MAKE) -C $(LIBFT_PATH)
# 	@echo "$(NAME): $(GREEN)$(LIBFT) was created$(RESET)"

# $(MLX):
# 	@$(MAKE) -C $(MLX_PATH)
# 	@echo "$(NAME): $(GREEN)$(MLX) was created$(RESET)"

# clean:
# 	@$(MAKE) -C $(LIBFT_PATH) clean
# 	@$(MAKE) -C $(MLX_PATH) clean
# 	@rm -r $(OBJ_DIR)
# 	@echo "$(NAME): $(RED)$(OBJ_DIR) was deleted$(RESET)"
# 	@echo "$(NAME): $(RED)object files were deleted$(RESET)"


# fclean: clean
# 	@$(MAKE) -C $(LIBFT_PATH) fclean
# 	@echo "$(NAME): $(RED)$(LIBFT) was deleted$(RESET)"
# 	@rm $(NAME)
# 	@echo "$(NAME): $(RED)$(NAME) was deleted$(RESET)"

# re: fclean all

# .PHONY: all clean fclean re