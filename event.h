#include "fdf.h"

typedef struct s_env
{
	void *mlx;
	void *win;
	t_fdf_data *mat;
}				t_env;

int key_press(int keycode, void *param);
