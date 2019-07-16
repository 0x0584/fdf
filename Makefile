all:
	gcc gnl.c main.c point.c libft/libft.a -lm -o fdf \
		-lmlx -framework OpenGL -framework AppKit
