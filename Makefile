NAME	= fdf
RM		= rm -f

DEPS	= libft.h
SRCS	= $(shell find . -type f -name "*.c")
OBJS	= $(patsubst %.c, %.o, $(SRCS))

CC		= gcc
CFLAGS	= -Wall -Wextra
LDFLAGS = -lm -lmlx -framework OpenGL -framework AppKit

$(NAME): all $(OBJS)
	gcc -o $(NAME) $(OBJS) $(LDFLAGS) libft/libft.a

all:
	make -C ./libft

%.o: %.c $(DEPS)
	$(CC) $(CFLAGS) -c $< -o $@ $(LDFLAGS)

clean:
	make -C ./libft clean
	$(RM) $(OBJS)

fclean: clean
	make -C ./libft fclean
	$(RM) $(NAME)

re: fclean all
