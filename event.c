#include "fdf.h"
#include "draw.h"
#include "matrice.h"
#include "event.h"

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
	int i = 0;
	int j;

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

int key_press(int keycode, void *param)
{
	t_env *env;
	env = param;

	t_pnt3d **tab_red;
	t_pnt3d	**restabloX;
	t_pnt3d **restabloY;
	t_pnt3d **restabloZ;
	t_pnt3d **f;
	t_pnt3d **redf;

	static long spacing = 33;
	static long verti = 150;
	static long horiz = 650;
	static long z_incr = 0;
	static float angleX = -0.2;
	static float angleY = 0; 
	int i = 0;
	int j;

	if(keycode == 126 || keycode == 125 || keycode == 124 || keycode == 123 || keycode == 69 || 
		keycode == 78 || keycode == 32 || keycode == 35 || keycode == 0 || keycode == 2 || 
			keycode == 7 || keycode == 13)
	{
		tab_red = redim(env->mat->base,env->mat->length,env->mat->width,spacing,z_incr);
		restabloX = rotationX(tab_red, env->mat->length, env->mat->width , angleX);
		restabloY = rotationY(restabloX, env->mat->length, env->mat->width, angleY);
		restabloZ = rotationZ(restabloY, env->mat->length, env->mat->width , -0.5);
		f = projestion(restabloZ ,env->mat->length, env->mat->width, 'i');
		redf = redim2d(f, env->mat->length, env->mat->width,horiz,verti);

		draw_map(env, 0x000000, redf);

		free_3dpnt_array(tab_red, env->mat->length);
		free_3dpnt_array(restabloX, env->mat->length);
		free_3dpnt_array(restabloY, env->mat->length);
		free_3dpnt_array(restabloZ, env->mat->length);
		free_3dpnt_array(f, env->mat->length);
		free_3dpnt_array(redf, env->mat->length);

		i = 0;
		switch (keycode)
		{
			case 126:verti-=10; //up
				break;
			case 125:verti+=10; //down
				break;
			case 123:horiz-=10; //left
				break;
			case 124:horiz+=10; //ritgh
				break;
			case 69:spacing+=10; //+
				break;
			case 78:spacing-=10; //-
				break;
			case 35:z_incr+=2; //p
				break;
			case 32:z_incr-=2; //u
				break;
			case 0:angleY-=0.01; //a
				break;
			case 2:angleY+=0.01; //d
				break;
			case 7:angleX+=0.01; //x
				break;
			case 13:angleX-=0.01; //w
				break;
		}	

		tab_red = redim(env->mat->base,env->mat->length,env->mat->width,spacing,z_incr);
		restabloX = rotationX(tab_red, env->mat->length, env->mat->width , angleX);
		restabloY = rotationY(restabloX, env->mat->length, env->mat->width, angleY);
		restabloZ = rotationZ(restabloY, env->mat->length, env->mat->width , -0.5);
		f = projestion(restabloZ ,env->mat->length, env->mat->width, 'i');
		redf = redim2d(f, env->mat->length, env->mat->width,horiz,verti);

		draw_map(env, 0xff0000, redf);

		free_3dpnt_array(tab_red, env->mat->length);
		free_3dpnt_array(restabloX, env->mat->length);
		free_3dpnt_array(restabloY, env->mat->length);
		free_3dpnt_array(restabloZ, env->mat->length);
		free_3dpnt_array(f, env->mat->length);
		free_3dpnt_array(redf, env->mat->length);
	}

	return(0);
}

