# ************ CONFIG ************

NAME    := parsing

CC      := cc
CFLAGS  := -Wall -Wextra -Werror -g
INCLUDES := -Isrc -I.

# Tous tes fichiers .c
SRCS := \
	src/parsing.c \
	divers/exit.c \
	divers/gnl.c \
	verif_information_cub/verif_line.c \
	verif_information_cub/verif_file/take_info_file.c \
	verif_information_cub/verif_color/take_info_color.c \
	verif_information_cub/verif_map/check_map.c \
	verif_information_cub/verif_map/list_chaine.c \
	verif_information_cub/verif_map/take_info_map.c \
	tableau_map/divers_map.c \
	tableau_map/map_tableau.c

# Les .o correspondants (même dossier que le .c)
OBJS := $(SRCS:.c=.o)

HEADERS := src/parsing.h

# ************ RULES ************

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
