CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRC_CLIENT = client.c 
SRC_SERVER = server.c
OBJ_CLIENT = $(SRC_CLIENT:.c=.o)
OBJ_SERVER = $(SRC_SERVER:.c=.o)
NAME_CLIENT = client
NAME_SERVER = server

all: client server
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

client: $(NAME_CLIENT)

server: $(NAME_SERVER)

$(NAME_CLIENT): $(OBJ_CLIENT) libft
	$(CC) -o $(NAME_CLIENT) $(OBJ_CLIENT) -Llibft -lft
	@echo "\\n\033[32;1mCLIENT OK \033[0m \\n"

$(NAME_SERVER): $(OBJ_SERVER) libft
	$(CC) -o $(NAME_SERVER) $(OBJ_SERVER) -Llibft -lft
	@echo "\\n\033[32;1mSERVER OK \033[0m \\n"

%.o: %.c
	$(CC) $(CFLAGS) -c $< 

libft:
	make -C libft

clean:
	@echo "\\n\033[38;5;202;1mDeleting Objects... \033[0m \\n"
	rm -rf $(OBJ_CLIENT) $(OBJ_SERVER)
	make -C libft clean
	@echo "\\n\033[32;1mDeleting OK \033[0m \\n"

fclean: clean
	@echo "\\n\033[38;5;202;1mCLEANING ALL... \033[0m \\n"
	rm -rf $(NAME_CLIENT) $(NAME_SERVER) libft/libft.a
	@echo "\\n\033[32;1mOK \033[0m \\n"

re: fclean all

.PHONY: all clean fclean re libft server client

.SILENT:
