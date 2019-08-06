
NAME	= fdf
RM		= rm -f

DEPS	= libft.h
SRCS	= $(shell find . -type f -name "*.c")
OBJS	= $(patsubst %.c, %.o, $(SRCS))

CC		= gcc
CFLAGS	= -Wall -Wextra
LDFLAGS = -lm -Llibft -lft -lmlx -framework OpenGL -framework AppKit

all: $(NAME)
	make -C ./libft 

$(NAME): $(OBJS)
	gcc -o $(NAME) $^ $(LDFLAGS)

%.o: %.c $(DEPS)
	$(CC) $(CFLAGS) -c $< -o $@ $(LDFLAGS)

clean:
	make -C ./libft clean
	$(RM) $(OBJS)

fclean: clean
	make -C ./libft fclean
	$(RM) $(NAME)

re: fclean all
