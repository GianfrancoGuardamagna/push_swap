NAME = push_swap

LIBFT_DIR = libft
PRINTF_DIR = printf

LIBFT = $(LIBFT_DIR)/libft.a
PRINTF = $(PRINTF_DIR)/libftprintf.a

CC = cc
CFLAGS = -Wall -Wextra -Werror

PUSH_SWAP_SRCS = main.c \
	utils.c \
	instructions/push.c \
	instructions/swap.c \
	instructions/rotate.c \
	instructions/reverse_rotate.c \
	small_analisis.c \
	error_checker.c \
	big_analisis/big_analisis.c \
	big_analisis/execute_cheapest_move.c \
	big_analisis/utils.c \

PUSH_SWAP_OBJS = $(PUSH_SWAP_SRCS:.c=.o)

INCLUDES = -I$(LIBFT_DIR) -I$(PRINTF_DIR) -I.

RM = rm -f

all: $(NAME)

$(NAME): $(PUSH_SWAP_OBJS) $(LIBFT) $(PRINTF)
	$(CC) $(CFLAGS) -o $(NAME) $(PUSH_SWAP_OBJS) $(LIBFT) $(PRINTF)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)


$(PRINTF):
	$(MAKE) -C $(PRINTF_DIR)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(PUSH_SWAP_OBJS)
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(PRINTF_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(MAKE) -C $(PRINTF_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
