############################## varaibles section #######################

#Mandatory source files names.

BONUS_DIR = bonus

SRCS                    =	mandatory/cub.c \
							mandatory/srcs/set_parametr.c \
							mandatory/srcs/ft_free_resorses.c \
							mandatory/srcs/ft_read_map.c \
							mandatory/srcs/help_func.c \
							mandatory/srcs/help_func2.c \
							mandatory/rander/ft_texters.c \
							mandatory/rander/render_wall.c \
							mandatory/rander/ray_casting.c \
							mandatory/rander/start_game.c \
							mandatory/rander/casting_utils.c \
							mandatory/rander/render_wall_utils.c \
							mandatory/parsing/ft_srcs.c \
							mandatory/parsing/ft_srcs2.c \
							mandatory/parsing/ft_check_borders.c \
							mandatory/parsing/ft_disperse_map.c \
							mandatory/parsing/ft_pars_map.c \
							mandatory/parsing/ft_pars_colors.c \
							mandatory/parsing/ft_pars_texters.c\
#Mandatory object files name.

OBJS                    = $(SRCS:%.c=%.o)

#bonus source files names.

SRCS_BONUS                    =	$(BONUS_DIR)/cub_bonus.c \
							$(BONUS_DIR)/srcs_bonus/set_parametr.c \
							$(BONUS_DIR)/srcs_bonus/ft_free_resorses.c \
							$(BONUS_DIR)/srcs_bonus/ft_read_map.c \
							$(BONUS_DIR)/srcs_bonus/help_func.c \
							$(BONUS_DIR)/srcs_bonus/help_func2.c \
							$(BONUS_DIR)/rander_bonus/ft_sprites.c \
							$(BONUS_DIR)/rander_bonus/doors.c \
							$(BONUS_DIR)/rander_bonus/ft_load_door.c \
							$(BONUS_DIR)/rander_bonus/ft_minimap.c \
							$(BONUS_DIR)/rander_bonus/render_wall.c \
							$(BONUS_DIR)/rander_bonus/ray_casting.c \
							$(BONUS_DIR)/rander_bonus/start_game.c \
							$(BONUS_DIR)/rander_bonus/ft_texters.c \
							$(BONUS_DIR)/rander_bonus/casting_utils.c \
							$(BONUS_DIR)/rander_bonus/render_wall_utils.c \
							$(BONUS_DIR)/parsing_bonus/ft_check_borders.c \
							$(BONUS_DIR)/parsing_bonus/ft_srcs.c \
							$(BONUS_DIR)/parsing_bonus/ft_srcs2.c \
							$(BONUS_DIR)/parsing_bonus/ft_disperse_map.c \
							$(BONUS_DIR)/parsing_bonus/ft_pars_map.c \
							$(BONUS_DIR)/parsing_bonus/ft_pars_colors.c \
							$(BONUS_DIR)/parsing_bonus/ft_pars_texters.c\
#bonus object files name.

OBJS_BONUS                    = $(SRCS_BONUS:%.c=%.o)

MLX_DIR 		= ./MLX42
MLX_BUILD_DIR 	= $(MLX_DIR)/build
MLX_LIB			= $(MLX_BUILD_DIR)/libmlx42.a

MLX_FLAGS 				= -L$(MLX_BUILD_DIR) -lmlx42 -Iinclude -lglfw -L"/Users/$(USER)/.brew/opt/glfw/lib/" -lm
FLAGS                   = -Wall -Wextra -Werror
NAME                    = cub3D
NAME_BONUS              = cub3D_bonus

LIBFT                   = ./libft/libft.a

LIBFT_H                 = ./libft/libft.h

LIBFT_SRCS              = 	./libft/ft_isalpha.c ./libft/ft_isdigit.c\
							./libft/ft_isalnum.c ./libft/ft_isascii.c\
							./libft/ft_isprint.c ./libft/ft_strlen.c \
							./libft/ft_memset.c ./libft/ft_bzero.c\
							./libft/ft_memcpy.c ./libft/ft_memmove.c\
							./libft/ft_strlcpy.c ./libft/ft_strlcat.c\
							./libft/ft_toupper.c ./libft/ft_tolower.c\
							./libft/ft_strchr.c ./libft/ft_strrchr.c\
							./libft/ft_strncmp.c ./libft/ft_memchr.c\
							./libft/ft_memcmp.c ./libft/ft_strnstr.c\
							./libft/ft_atoi.c ./libft/ft_calloc.c\
							./libft/ft_strdup.c ./libft/ft_substr.c\
							./libft/ft_strjoin.c ./libft/ft_strtrim.c\
							./libft/ft_split.c ./libft/ft_itoa.c\
							./libft/ft_strmapi.c ./libft/ft_striteri.c\
							./libft/ft_putchar_fd.c ./libft/ft_putstr_fd.c\
							./libft/ft_putendl_fd.c ./libft/ft_putnbr_fd.c\
							./libft/ft_lstnew.c ./libft/ft_lstadd_front.c \
							./libft/ft_lstsize.c ./libft/ft_lstlast.c\
							./libft/ft_lstadd_back.c ./libft/ft_lstdelone.c \
							./libft/ft_lstclear.c ./libft/ft_lstiter.c\
							./libft/ft_lstmap.c ./libft/get_next_line.c\
							./libft/ft_strllen.c ./libft/ft_strchar.c \
							./libft/ft_strcmp.c

#######################################################################

############################ Rules Section ############################


%.o: %.c mandatory/cub.h
	cc $(FLAGS) -c -o $@ $<

$(NAME)                 : $(OBJS) mandatory/cub.h $(LIBFT_H) $(MLX_LIB) $(LIBFT)
	cc  $(FLAGS) $(LIBFT) $(OBJS) -o $(NAME) $(MLX_FLAGS)

bonus : $(NAME_BONUS)
all                     : $(NAME)


$(NAME_BONUS): $(OBJS_BONUS) $(BONUS_DIR)/cub_bonus.h $(LIBFT_H) $(MLX_LIB) $(LIBFT)
	cc $(FLAGS) $(LIBFT) $(OBJS_BONUS) -o $(NAME_BONUS) $(MLX_FLAGS)

$(MLX_LIB):
	rm -rf $(MLX_BUILD_DIR)
	cd $(MLX_DIR) && cmake -B build && cmake --build build -j4

$(LIBFT)                : $(LIBFT_SRCS) $(LIBFT_H)
	make -C ./libft


clean                   :
	rm -f *.o
	rm -f */*.o
	rm -f */*/*.o
	make clean -C ./libft

fclean                  : clean
	rm -f $(NAME)
	rm -f $(NAME_BONUS)
	rm -rf $(MLX_BUILD_DIR)
	rm -f $(MLX_LIB)
	make fclean -C ./libft

re                      : fclean all

.PHONY                  : clean