# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ybouroga <ybouroga@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/14 12:46:13 by ybouroga          #+#    #+#              #
#    Updated: 2025/11/25 18:39:11 by ybouroga         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MAKE_FLAGS += --no-print-directory

NAME = cub3D
NAME_BONUS = cub3D_bonus

EXE = ./$(NAME)
EXE_BONUS = ./$(NAME_BONUS)

SRC_DIR = src
INC_DIR = includes
OBJ_DIR = obj
MLX_DIR = minilibx-linux
LIB_MLX = libmlx.a

CC = cc
RM = rm -rf

MLX_FLAGS = -L$(MLX_DIR) -lmlx_Linux -lXext -lX11 -lm

C_FLAGS	= -Wall -Wextra -Werror \
          -MMD -MP \
          -I$(INC_DIR) \
          -I$(MLX_DIR)

DBG_FLAGS	= -g
ASAN_FLAGS   = -g -O0 -fsanitize=address,undefined -fno-omit-frame-pointer

include mk/sources.mk
include mk/includes.mk

SRCS_NO_BONUS := $(SRCS_COMMON) $(SRCS_NO_BONUS)
OBJS_NO_BONUS := $(SRCS_NO_BONUS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

SRCS_BONUS_MODE := $(SRCS_COMMON) $(SRCS_BONUS)
OBJS_BONUS := $(SRCS_BONUS_MODE:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

all: $(NAME)
bonus: $(NAME_BONUS)

$(NAME): $(OBJS_NO_BONUS) $(MLX_LIB)
	$(CC) $(C_FLAGS) $^ $(MLX_FLAGS) -o $@

$(NAME_BONUS): $(OBJS_BONUS) $(MLX_LIB)
	$(CC) $(C_FLAGS) -DBONUS_MODE $^ $(MLX_FLAGS) -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(C_FLAGS) -c $< -o $@

$(MLX_LIB):
	$(MAKE) -C $(MLX_DIR)

clean:
	$(RM) $(OBJ_DIR)

fclean: clean
	$(RM) $(NAME) $(NAME_BONUS)

re: fclean all

include mk/targets.mk

-include $(OBJS_NO_BONUS:.o=.d)
-include $(OBJS_BONUS:.o=.d)


