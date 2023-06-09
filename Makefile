NAME = cub3D

CC = gcc
CFLAGS = -Wall -Werror -Wextra -g -fsanitize=address
#CFLAGS = -Wall -Werror -Wextra -g -fsanitize=leak

#MLX_MACOS
MLX_INC = -Imlx
MLX_FLAGS = -lmlx -Lmlx -framework OpenGL -framework AppKit

#MLX_LINUX
#MLX_INC_LINUX = -I/usr/include -Imlx_linux -03
#MLX_FLAGS_LINUX = -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz 

#libft
LIBFT = libft/libft.a
LIBFT_FLAGS = -Llibft

INC = -Iinc -Ilibft -Ilibft/libft -Imlx

SRCS_DIR = srcs/
SRCS = cub3d.c \
		chkfilenamemap.c \
		fileerrhand.c \
		storfile2tlist.c \
		initmstr.c \
		stormapinfo.c \
		walk_utils.c \
		walk.c \
		crossTire.c \
		hitWall.c \
		hook.c \
		draw.c \
		draw_tire.c \
		minimap_utils.c \
		minimap.c \
		raycast.c \
		texture.c \
		clear.c \

OBJS_DIR = objs/
OBJS = $(addprefix $(OBJS_DIR), $(SRCS:.c=.o))

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	@make -C ./mlx
	$(CC) $(CFLAGS) $^ $(LIBFT_FLAGS) $(MLX_FLAGS) -o $@
	#$(CC) $(CFLAGS) $^ $(LIBFT_FLAGS) $(MLX_FLAGS_LINUX) -o $@

$(OBJS_DIR)%.o: $(SRCS_DIR)%.c
	mkdir -p $(OBJS_DIR)
	$(CC) $(CFLAGS) $(MLX_INC) $(INC) -c $< -o $@ 
	#$(CC) $(CFLAGS) $(MLX_INC_LINUX) $(INC) -c $< -o $@ 

#libft:
$(LIBFT):
	@make -C ./libft

norminette:
	norminette -R CheckForbiddenSourceHeader inc/*.h srcs/*.c

clean:
	@make fclean -C ./libft
	@make clean -C ./mlx
	rm -rf *.dSYM *.o $(OBJS_DIR) $(NAME)

fclean: clean

re: fclean all libft

.PHONY: clean fclean re norminette libft
