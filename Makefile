all:
	gcc gnl.c main.c point.c libft/libft.a -o fdf \
		-lmlx -framework OpenGL -framework AppKit
