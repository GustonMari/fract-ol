CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRC = colors.c \
			ft_gustave.c \
			ft_julia.c \
			ft_key.c \
			ft_mandelbrot.c \
			ft_zoom.c \
			main.c
OBJ = $(SRC:.c=.o)
NAME= fractol

all: server
	@echo "\\n\033[32;1mMAKE ALL OK \033[0m \\n"
	@echo "\033[32;1m      ___           ___           ___           ___                  \033[0m"
	@echo "\033[32;1m     /\__\         /\  \         /\  \         /\  \                 \033[0m"
	@echo "\033[32;1m    /:/ _/_       |::\  \       /::\  \       /::\  \         ___    \033[0m"
	@echo "\033[32;1m   /:/ /\  \      |:|:\  \     /:/\:\  \     /:/\:\__\       /|  |   \033[0m"
	@echo "\033[32;1m  /:/ /::\  \   __|:|\:\  \   /:/ /::\  \   /:/ /:/  /      |:|  |   \033[0m"
	@echo "\033[32;1m /:/__\/\:\__\ /::::|_\:\__\ /:/_/:/\:\__\ /:/_/:/__/___    |:|  |   \033[0m"
	@echo "\033[32;1m \:\  \ /:/  / \:\~~\  \/__/ \:\/:/  \/__/ \:\/:::::/  /  __|:|__|   \033[0m"
	@echo "\033[32;1m  \:\  /:/  /   \:\  \        \::/__/       \::/~~/~~~~  /::::\  \   \033[0m"
	@echo "\033[32;1m   \:\/:/  /     \:\  \        \:\  \        \:\~~\      ~~~~\:\  \  \033[0m"
	@echo "\033[32;1m    \::/  /       \:\__\        \:\__\        \:\__\          \:\__\ \033[0m"
	@echo "\033[32;1m     \/__/         \/__/         \/__/         \/__/           \/__/ \033[0m"
	@echo "\\n"

server: $(NAME)

$(NAME): $(OBJ)
	make -C minilibx_linux
	$(CC) -o $(NAME) $(OBJ) -L minilibx_linux -lmlx -lX11 -lXext
	@echo "\\n\033[32;1mSERVER OK \033[0m \\n"

%.o: %.c
	$(CC) $(CFLAGS) -Ofast -c $< 

clean:
	@echo "\\n\033[38;5;202;1mDeleting Objects... \033[0m \\n"
	rm -rf $(OBJ)
	make -C minilibx_linux clean
	@echo "\\n\033[32;1mDeleting OK \033[0m \\n"

fclean: clean
	@echo "\\n\033[38;5;202;1mCLEANING ALL... \033[0m \\n"
	make -C minilibx_linux clean
	rm -rf $(NAME)
	@echo "\\n\033[32;1mOK \033[0m \\n"

re: fclean all

.PHONY: all clean fclean re libft server client

.SILENT:
