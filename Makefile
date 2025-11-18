# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ybouroga <ybouroga@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/14 12:46:13 by ybouroga          #+#    #+#              #
#    Updated: 2025/11/18 19:08:57 by ybouroga         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MAKE_FLAGS += --no-print-directory

NAME = cub3D

EXE = ./$(NAME)

SRC_DIR = src
INC_DIR = includes
OBJ_DIR = obj
MLX_DIR = minilibx-linux
LIB_MLX = libmlx.a

CC = cc

RM = rm -rf

MLX_FLAGS = -L$(MLX_DIR) -lmlx_Linux -lXext -lX11 -lm

C_FLAGS		= -Wall -Wextra -Werror \
  -MMD -MP \
  -I$(INC_DIR) \
  -I$(MLX_DIR) \

DBG_FLAGS	= -g
ASAN_FLAGS   = -g -O0 -fsanitize=address,undefined -fno-omit-frame-pointer

include mk/sources.mk
include mk/includes.mk

OBJS = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

MLX_LIB = $(MLX_DIR)/$(LIB_MLX)

all: $(NAME)

$(NAME): $(OBJS) $(MLX_LIB)
	$(CC) $(C_FLAGS) $(OBJS) $(MLX_FLAGS) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(C_FLAGS) -c $< -o $@

$(MLX_LIB):
	$(MAKE) -C $(MLX_DIR)

clean:
	$(RM) $(OBJ_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean $(NAME)

include mk/targets.mk

-include $(OBJS:.o=.d)

