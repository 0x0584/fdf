#include "fdf.h"
#include "draw.h"
#include "matrice.h"
#include "event.h"

int		default_color(int color)
{
	static int default_color;

	if (color == -1)
		return default_color;
	default_color = color;
	return default_color;
}

void	apply_projection(t_info *ifdf, t_env *env, int color)
{
	t_pnt3d **tab_red;
	t_pnt3d	**restabloX;
	t_pnt3d **restabloY;
	t_pnt3d **restabloZ;
	t_pnt3d **f;
	t_pnt3d **redf;

	tab_red = redim(env->mat->base, ifdf, env);
	ft_putendl("before redim");
	restabloX = rotation(tab_red, ifdf , ROT_X, env);
	restabloY = rotation(restabloX, ifdf , ROT_Y, env);
	restabloZ = rotation(restabloY, ifdf , ROT_Z, env);
	f = projection(restabloZ, ifdf, env);
	redf = redim2d(f, ifdf, env);
	draw_map(env, color, redf);
	point_free_array(tab_red, env->mat->length);
	point_free_array(restabloX, env->mat->length);
	point_free_array(restabloY, env->mat->length);
	point_free_array(restabloZ, env->mat->length);
	point_free_array(f, env->mat->length);
	point_free_array(redf, env->mat->length);
}

int key_press(int keycode, void *param)
{
	static t_info *ifdf = NULL;
	t_env *env;

	env = param;
	if (ifdf == NULL)
	{
		t_pnt3d pnt = {450, 450, 0, BLACK};
		ifdf = get_fdf_info();
		draw_color_square(env, pnt, 350);
	}
	if (keycode == KEY_ESC)
	{
		mlx_clear_window(env->mlx, env->win);
		mlx_destroy_window(env->mlx, env->win);
		exit(0);
	}

	if(keycode == KEY_DEFAULT || key_is_direc(keycode) || key_is_zoom(keycode)
	   || key_is_z_incr(keycode) || key_is_rot(keycode) || key_is_proj(keycode))
	{
		apply_projection(ifdf, env, BLACK);
		if (keycode == KEY_UP || keycode == KEY_DOWN)
			ifdf->verti += (keycode == KEY_UP ? -DEF_VERTI : DEF_VERTI);
		if (keycode == KEY_LEFT || keycode == KEY_RIGHT)
			ifdf->horiz += (keycode == KEY_LEFT ? -DEF_HORIZ : DEF_HORIZ);
		if (key_is_zoom(keycode))
			ifdf->spacing += (keycode == KEY_ZOOM_UP ?
							  DEF_SPACING : -DEF_SPACING);
		if (key_is_z_incr(keycode))
			ifdf->z_incr += (keycode == KEY_Z_INCR ? DEF_Z_INCR : -DEF_Z_INCR);
		if (keycode == KEY_ROT_Y_UP || keycode == KEY_ROT_Y_DOWN)
			ifdf->angle[ROT_Y] += (keycode == KEY_ROT_Y_UP ?
										-DEF_ANGLE_Y : DEF_ANGLE_Y);
		if (keycode == KEY_ROT_X_DOWN || keycode == KEY_ROT_X_UP)
			ifdf->angle[ROT_X] += (keycode == KEY_ROT_X_UP ?
										-DEF_ANGLE_X : DEF_ANGLE_X);
		if (keycode == KEY_ROT_Z_DOWN || keycode == KEY_ROT_Z_UP)
			ifdf->angle[ROT_Z] += (keycode == KEY_ROT_Z_UP ?
										-DEF_ANGLE_Z : DEF_ANGLE_Z);
		if (keycode == KEY_PROJ_PARA || keycode == KEY_PROJ_ISO)
		{
			ifdf->z_incr = 0;
			ifdf->proj_type =  keycode == KEY_PROJ_ISO ? 'i' : 'p';
		}
		apply_projection(ifdf, env, default_color(-1));
		draw_edge(env);
	}

	return(0);
}

bool			key_is_direc(t_keycode code)
{
	return (code == KEY_LEFT || code == KEY_RIGHT
			|| code == KEY_UP || code == KEY_DOWN);
}

bool			key_is_zoom(t_keycode code)
{
	return (code == KEY_ZOOM_UP || code == KEY_ZOOM_DOWN);
}

bool			key_is_z_incr(t_keycode code)
{
	return (code == KEY_Z_INCR || code == KEY_Z_DECR);
}

bool			key_is_rot(t_keycode code)
{
	return (code == KEY_ROT_X_UP || code == KEY_ROT_X_DOWN
			|| code == KEY_ROT_Y_UP || code == KEY_ROT_Y_DOWN
			|| code == KEY_ROT_Z_UP || code == KEY_ROT_Z_DOWN);
}

bool			key_is_proj(t_keycode code)
{
	return (code == KEY_PROJ_ISO || code == KEY_PROJ_PARA);
}
