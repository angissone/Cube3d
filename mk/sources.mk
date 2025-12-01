# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    sources.mk                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ybouroga <ybouroga@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/27 15:02:12 by ybouroga          #+#    #+#              #
#    Updated: 2025/12/01 13:11:43 by ybouroga         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS_COMMON = \
  $(SRC_DIR)/main.c \
  $(SRC_DIR)/libft/ft_atod.c \
  $(SRC_DIR)/libft/ft_atoi.c \
  $(SRC_DIR)/libft/ft_bzero.c \
  $(SRC_DIR)/libft/ft_calloc.c \
  $(SRC_DIR)/libft/ft_isalnum.c \
  $(SRC_DIR)/libft/ft_isalpha.c \
  $(SRC_DIR)/libft/ft_isascii.c \
  $(SRC_DIR)/libft/ft_isdigit.c \
  $(SRC_DIR)/libft/ft_isprint.c \
  $(SRC_DIR)/libft/ft_itoa.c\
  $(SRC_DIR)/libft/ft_lstadd_back_bonus.c \
  $(SRC_DIR)/libft/ft_lstadd_front_bonus.c \
  $(SRC_DIR)/libft/ft_lstclear_bonus.c \
  $(SRC_DIR)/libft/ft_lstdelone_bonus.c \
  $(SRC_DIR)/libft/ft_lstiter_bonus.c \
  $(SRC_DIR)/libft/ft_lstlast_bonus.c \
  $(SRC_DIR)/libft/ft_lstmap_bonus.c \
  $(SRC_DIR)/libft/ft_lstnew_bonus.c \
  $(SRC_DIR)/libft/ft_lstsize_bonus.c \
  $(SRC_DIR)/libft/ft_memchr.c \
  $(SRC_DIR)/libft/ft_memcmp.c \
  $(SRC_DIR)/libft/ft_memcpy.c \
  $(SRC_DIR)/libft/ft_memmove.c \
  $(SRC_DIR)/libft/ft_memset.c \
  $(SRC_DIR)/libft/ft_putchar_fd.c \
  $(SRC_DIR)/libft/ft_putendl_fd.c \
  $(SRC_DIR)/libft/ft_putnbr_fd.c \
  $(SRC_DIR)/libft/ft_putstr_fd.c \
  $(SRC_DIR)/libft/ft_split.c \
  $(SRC_DIR)/libft/ft_strchr.c \
  $(SRC_DIR)/libft/ft_strdup.c \
  $(SRC_DIR)/libft/ft_striteri.c \
  $(SRC_DIR)/libft/ft_strjoin.c \
  $(SRC_DIR)/libft/ft_strlcat.c \
  $(SRC_DIR)/libft/ft_strlcpy.c \
  $(SRC_DIR)/libft/ft_strlen.c \
  $(SRC_DIR)/libft/ft_strmapi.c \
  $(SRC_DIR)/libft/ft_strncmp.c \
  $(SRC_DIR)/libft/ft_strnstr.c \
  $(SRC_DIR)/libft/ft_strrchr.c \
  $(SRC_DIR)/libft/ft_strtrim.c \
  $(SRC_DIR)/libft/ft_substr.c \
  $(SRC_DIR)/libft/ft_tolower.c \
  $(SRC_DIR)/libft/ft_toupper.c \
  $(SRC_DIR)/draw/cub_draw_clear.c \
  $(SRC_DIR)/draw/cub_putpixel.c \
  $(SRC_DIR)/draw/cub_draw_window.c \
  $(SRC_DIR)/clean_mem/cub_exit.c \
  $(SRC_DIR)/hook/cub_hook.c \
  $(SRC_DIR)/clean_mem/cub_memory.c \
  $(SRC_DIR)/init/cub_init.c \
  $(SRC_DIR)/libft/ft_strcmp.c \
  $(SRC_DIR)/math/cub_mat4.c \
  $(SRC_DIR)/scene/cub_ray.c \
  $(SRC_DIR)/math/cub_vec3.c \
  $(SRC_DIR)/scene/cub_camera.c \
  $(SRC_DIR)/draw/cub_render.c \
  $(SRC_DIR)/debug/cub_debug.c \
  $(SRC_DIR)/math/cub_hit_record.c \
  $(SRC_DIR)/math/cub_convert.c \
  $(SRC_DIR)/math/cub_random.c \
  $(SRC_DIR)/get_next_line/get_next_line.c \
  $(SRC_DIR)/get_next_line/get_next_line_utils.c \
  $(SRC_DIR)/hook/cub_hook_key.c \
  $(SRC_DIR)/init/cub_init_texture.c \
  $(SRC_DIR)/parsing/parsing_main/parsing.c \
  $(SRC_DIR)/parsing/parsing_main/parsing_loop.c \
  $(SRC_DIR)/parsing/divers/exit.c \
  $(SRC_DIR)/parsing/divers/divers.c \
  $(SRC_DIR)/parsing/divers/gnl.c \
  $(SRC_DIR)/parsing/divers/gnl_2.c \
  $(SRC_DIR)/parsing/verif_information_cub/verif_line.c \
  $(SRC_DIR)/parsing/verif_information_cub/verif_color/take_info_color.c \
  $(SRC_DIR)/parsing/verif_information_cub/verif_color/take_info_color_utils.c \
  $(SRC_DIR)/parsing/verif_information_cub/verif_file/take_info_file.c \
  $(SRC_DIR)/parsing/verif_information_cub/verif_map/check_map.c \
  $(SRC_DIR)/parsing/verif_information_cub/verif_map/list_chaine.c \
  $(SRC_DIR)/parsing/tableau_map/divers_map.c \
  $(SRC_DIR)/parsing/tableau_map/map_tableau.c \
  $(SRC_DIR)/parsing/tableau_map/floot_file_map.c \
  $(SRC_DIR)/parsing/tableau_map/floot_file_2.c \

SRCS_NO_BONUS = \
  $(SRC_DIR)/hook/cub_hook_mouse.c \
  $(SRC_DIR)/math/cub_collision_mur.c \

SRCS_BONUS = \
  $(SRC_DIR)/hook/cub_hook_mouse_bonus.c \
  $(SRC_DIR)/math/cub_collision_mur_bonus.c \
