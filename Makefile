CC = cc

CFLAGS = -Wall -Wextra -Werror -g -fsanitize=address

NAME = so_long

MLX_FLAGS = -L/usr/local/lib -lmlx -lXext -lX11 -lm -lbsd

BONUS_DIR = bonus

SRCS = so_long.c \
	draw_map.c \
	read_map.c \
	ft_putchar_fd.c \
	ft_putstr_fd.c \
	movemont.c \
	set_parametr.c\
	ft_putnbr_fd.c \
	ft_split.c \
	get_next_line.c \
	get_next_line_utils.c \
	parcing.c \
	flood_map.c \
	win_exit.c \
	ft_strncmp.c \
	ft_strrchr.c \
	ft_check_ber.c

SRCS_BONNUS = $(BONUS_DIR)/so_long_bonus.c\
 $(BONUS_DIR)/draw_map.c \
 $(BONUS_DIR)/read_map.c \
 $(BONUS_DIR)/ft_putchar_fd.c \
 $(BONUS_DIR)/ft_putstr_fd.c \
 $(BONUS_DIR)/ft_itoa.c \
 $(BONUS_DIR)/movemont.c \
 $(BONUS_DIR)/set_parametr.c\
 $(BONUS_DIR)/ft_split.c \
 $(BONUS_DIR)/get_next_line.c \
 $(BONUS_DIR)/get_next_line_utils.c \
 $(BONUS_DIR)/parcing.c \
 $(BONUS_DIR)/flood_map.c \
 $(BONUS_DIR)/enemy_touch.c \
 $(BONUS_DIR)/move_enemy.c \
 $(BONUS_DIR)/count_move_e.c \
 $(BONUS_DIR)/check_map.c \

OBJECTS = $(SRCS:.c=.o)

OBJECTS_BONNUS = $(SRCS_BONNUS:.c=.o)

RM = rm -f

all: $(NAME)

$(NAME): $(OBJECTS) so_long.h
	$(CC) $(CFLAGS) $(OBJECTS) -o $@ $(MLX_FLAGS)	

bonus: $(OBJECTS_BONNUS) $(BONUS_DIR)/so_long_bonus.h
	$(CC) $(CFLAGS) $(OBJECTS_BONNUS) -o $(NAME) $(MLX_FLAGS)

clean:
	$(RM) $(OBJECTS) $(OBJECTS_BONNUS)

fclean:	clean
	$(RM) $(NAME)

re:	fclean $(NAME)

