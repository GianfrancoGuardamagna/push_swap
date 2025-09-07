NAME = push_swap

PRINTF_DIR = printf
LIBFT_DIR = libft

PRINTF = $(PRINTF_DIR)/libftprintf.a
LIBFT = $(LIBFT_DIR)/libft.a

CC = cc
CFLAGS = -Wall -Wextra -Werror

PUSH_SWAP_SRCS = main.c \
	utils/error_checker.c \
	utils/utils.c \
	instructions/push.c \
	instructions/swap.c \
	instructions/rotate.c \
	instructions/reverse_rotate.c \
	small_analisis.c \
	big_analisis/big_analisis.c \
	big_analisis/execute_cheapest_move.c \
	big_analisis/utils.c

PUSH_SWAP_OBJS = $(PUSH_SWAP_SRCS:.c=.o)

INCLUDES = -I . -I $(PRINTF_DIR) -I $(LIBFT_DIR)

all: $(NAME)

$(NAME): $(LIBFT) $(PRINTF) $(PUSH_SWAP_OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(PUSH_SWAP_OBJS) $(PRINTF) $(LIBFT)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(PRINTF): $(LIBFT)
	$(MAKE) -C $(PRINTF_DIR)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(PUSH_SWAP_OBJS)
	$(MAKE) -C $(PRINTF_DIR) clean
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(PRINTF_DIR) fclean
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re