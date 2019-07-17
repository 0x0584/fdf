all:
	gcc *.c -o fdf -lm -Llibft -lft -lmlx \
			-framework OpenGL -framework AppKit
test: all
	./fdf maps/42.fdf
