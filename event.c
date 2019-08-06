#include "fdf.h"
#include "draw.h"
#include "matrice.h"
#include "event.h"

static int default_color = 0x0000ff;

void set_default_color(int color)
{
	default_color = color;
}

void free_3dpnt_array(t_pnt3d **array, t_uint32 length)
{
	t_uint32 i;

	i = 0;
	while (i < length)
		free(array[i++]);
	free(array);
}

void draw_map(t_env *env, int color, t_pnt3d **redf)
{
	t_uint32 i = 0;
	t_uint32 j;

	while (i < env->mat->length)
	{
		j = 0;
		while (j < env->mat->width)
		{
			if (j != (env->mat->width - 1))
				draw_line(env->mlx, env->win, redf[i][j],redf[i][j + 1],color);
			if(i != (env->mat->length - 1))
				draw_line(env->mlx, env->win, redf[i][j],redf[i + 1][j],color);
			j++;
		}
		i++;
	}
}

void	to_do(long spacing,long verti,long horiz,long z_incr,float angleX,float angleY,float angleZ,t_env *env, int color)
{
	t_pnt3d **tab_red;
	t_pnt3d	**restabloX;
	t_pnt3d **restabloY;
	t_pnt3d **restabloZ;
	t_pnt3d **f;
	t_pnt3d **redf;

	tab_red = redim(env->mat->base,env->mat->length,env->mat->width,spacing,z_incr);
	restabloX = rotationX(tab_red, env->mat->length, env->mat->width , angleX);
	restabloY = rotationY(restabloX, env->mat->length, env->mat->width, angleY);
	restabloZ = rotationZ(restabloY, env->mat->length, env->mat->width , angleZ);
	f = projestion(restabloZ ,env->mat->length, env->mat->width, 'i');
	redf = redim2d(f, env->mat->length, env->mat->width,horiz,verti);
	draw_map(env, color, redf);
	free_3dpnt_array(tab_red, env->mat->length);
	free_3dpnt_array(restabloX, env->mat->length);
	free_3dpnt_array(restabloY, env->mat->length);
	free_3dpnt_array(restabloZ, env->mat->length);
	free_3dpnt_array(f, env->mat->length);
	free_3dpnt_array(redf, env->mat->length);
}

int key_press(int keycode, void *param)
{
	t_env *env;
	env = param;
	static long spacing = 33;
	static long verti = 150;
	static long horiz = 650;
	static long z_incr = 0;
	static float angleX = -0.2;
	static float angleY = 0;
	static float angleZ = -0.5;


	if(keycode == -1 || keycode == 126 || keycode == 125 || keycode == 124 || keycode == 123 || keycode == 69 ||
	   keycode == 78 || keycode == 32 || keycode == 35 || keycode == 0 || keycode == 2 ||
	   keycode == 7 || keycode == 13 || keycode == 12 || keycode == 14)
	{
		to_do(spacing, verti, horiz, z_incr, angleX, angleY, angleZ, env, 0x000000);
		if (keycode == 126)
			verti-=10;
		if (keycode == 125)
			verti+=10;
		if (keycode == 123)
			horiz-=10;
		if (keycode == 124)
			horiz+=10;
		if (keycode == 69)
			spacing+=10;
		if (keycode == 78)
			spacing-=10;
		if (keycode == 35)
			z_incr+=2;
		if (keycode == 32)
			z_incr-=2;
		if (keycode == 0)
			angleY-=0.01;
		if (keycode == 2)
			angleY+=0.01;
		if (keycode == 7)
			angleX+=0.01;
		if (keycode == 13)
			angleX-=0.01;
		if (keycode == 12)
			angleZ+=0.01;
		if (keycode == 14)
			angleZ-=0.01;
		to_do( spacing, verti, horiz, z_incr, angleX, angleY, angleZ, env, default_color);
	}

	return(0);
}
