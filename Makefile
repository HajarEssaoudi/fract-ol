CC = cc
CFLAGS =
NAME = fractol

SRCS = main.c Handle_errors.c render.c events.c
OBJS = $(SRCS:.c=.o)

LIB1 = libft/libft.a
LIB2 = ft_printf/libftprintf.a
MLX = -Lmlx_linux -lmlx_Linux -L/usr/include/minilibx-linux -lXext -lX11 -lm -lz

all: $(NAME)

$(NAME): $(LIB1) $(LIB2) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIB1) $(LIB2) $(MLX) -o $(NAME)

$(LIB1):
	make -C libft

$(LIB2):
	make -C ft_printf

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)
	make -C libft clean
	make -C ft_printf clean

do: all clean

fclean: clean
	rm -f $(NAME)
	make -C libft fclean
	make -C ft_printf fclean

do: all clean

re: fclean all

.PHONY: all clean fclean re
