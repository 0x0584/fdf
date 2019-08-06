#include "matrice.h"
#include <stdio.h>

t_pnt3d    projetion_iso(t_pnt3d point)
{
    t_pnt3d ret2d;
    ret2d.x = (point.x - point.y) * cos(0.523599);
    ret2d.y = (point.x + point.y) * sin(0.523599) - point.z;
    ret2d.color = point.color;
    return (ret2d);
}

t_pnt3d    **projestion(t_pnt3d **matrix, t_uint32 length, t_uint32 width, char project_methode)
{
    t_pnt3d **projected;
    t_uint32 i = 0;
    t_uint32 j;
    /*********************************************************/
	projected = (t_pnt3d**)malloc(sizeof(t_pnt3d*) * length);
	while(i < length)
	{
		projected[i] = (t_pnt3d*)malloc(sizeof(t_pnt3d) * width);
		i++;
	}
    /*********************************************************/
    i = 0;
    while(i < length)
    {
        j = 0;
        while (j < width)
        {   
            if (project_methode == 'i')
                projected[i][j] = projetion_iso(matrix[i][j]);
            j++;
        }
        i++;
    }
    return (projected);
}
t_pnt3d    produit_matrix(t_pnt3d point, float rot_matrix[3][3])
{
    t_pnt3d ret_pnt;
    t_uint32 i;
    t_uint32 j;
    long tab[3] = {point.x, point.y, point.z};
    long ret[3] = {0,0,0};
    i = 0;
    while (i < 3)
    {
        j = 0;
        while (j < 3)
        {
			//printf("+++%f+++",rot_matrix[i][j]);
            ret[i] = ret[i] + (tab[j] * rot_matrix[i][j]);
            j++;
        }
	//	printf("--%ld--",ret[i]);
        i++;
    }
    ret_pnt.x = ret[0];
    ret_pnt.y = ret[1];
    ret_pnt.z = ret[2];
    ret_pnt.color = point.color;
    return (ret_pnt);
}

t_pnt3d **rotationX(t_pnt3d **matrix, t_uint32 length, t_uint32 width ,float angle)
{

    t_pnt3d **ret_mat;
	/************ allocation ret_mat ****************/
	t_uint32 i = 0;
	ret_mat = (t_pnt3d**)malloc(sizeof(t_pnt3d*) * length);
	while(i < length)
	{
		ret_mat[i] = (t_pnt3d*)malloc(sizeof(t_pnt3d) * width);
		i++;
	}
	/************************************************/
    float rot_matrix_x[3][3] = {{1,0,0},
                              {0,cos(angle),-sin(angle)},
                              {0,sin(angle),cos(angle)}};
    t_uint32 j;
    i = 0;
    while(i < length)
    {
        j = 0;
        while (j < width)
        {   
          //  printf("%ld %ld %ld | ", matrix[i][j].x,matrix[i][j].y,matrix[i][j].z);
            ret_mat[i][j] = produit_matrix(matrix[i][j], rot_matrix_x);
       //     printf("%ld %ld %ld\n",ret_mat[i][j].x, ret_mat[i][j].y,ret_mat[i][j].z);
            j++;
        }
        i++;
    }
	return (ret_mat);
}
t_pnt3d    **rotationY(t_pnt3d **matrix, t_uint32 length, t_uint32 width, float angle)
{
    t_pnt3d **ret_mat;
	/************ allocation ret_mat ****************/
	t_uint32 i = 0;
	ret_mat = (t_pnt3d**)malloc(sizeof(t_pnt3d*) * length);
	while(i < length)
	{
		ret_mat[i] = (t_pnt3d*)malloc(sizeof(t_pnt3d) * width);
		i++;
	}
	/************************************************/
    float rot_matrix_y[3][3] = {{cos(angle),0,sin(angle)},
                              {0, 1, 0},
                              {-sin(angle), 0,cos(angle)}};
    t_uint32 j;
    i = 0;
    while(i < length)
    {
        j = 0;
        while (j < width)
        {
            ret_mat[i][j] = produit_matrix(matrix[i][j], rot_matrix_y);
            j++;
        }
        i++;
    }
    	return (ret_mat);
}

t_pnt3d    **rotationZ(t_pnt3d **matrix, t_uint32 length, t_uint32 width, float angle)
{
    t_pnt3d **ret_mat;
	/************ allocation ret_mat ****************/
	t_uint32 i = 0;
	ret_mat = (t_pnt3d**)malloc(sizeof(t_pnt3d*) * length);
	while(i < length)
	{
		ret_mat[i] = (t_pnt3d*)malloc(sizeof(t_pnt3d) * width);
		i++;
	}
	/************************************************/
    float rot_matrix_z[3][3] = {{cos(angle), -sin(angle), 0},
                              {sin(angle), cos(angle), 0},
                              {0, 0, 1}};
    t_uint32 j;
    i = 0;
    while(i < length)
    {
        j = 0;
        while (j < width)
        {
           ret_mat[i][j] = produit_matrix(matrix[i][j], rot_matrix_z);
            j++;
        }
        i++;
    }
    return (ret_mat);
}

t_pnt3d **redim(t_pnt3d **matrix, t_uint32 length, t_uint32 width, long spacing, long z_incr)
{
    t_pnt3d **ret_mat;
	/************ allocation ret_mat ****************/
	t_uint32 i = 0;
	ret_mat = (t_pnt3d**)malloc(sizeof(t_pnt3d*) * length);
	while(i < length)
	{
		ret_mat[i] = (t_pnt3d*)malloc(sizeof(t_pnt3d) * width);
		i++;
	}
	/************************************************/
    t_uint32 j;
    i = 0;
    while (i < length)
	{
		j = 0;
		while (j < width) 
		{
			ret_mat[i][j] = (t_pnt3d){
                matrix[i][j].x+j*spacing,
                matrix[i][j].y+i*spacing,
                (matrix[i][j].z != 0) ? (matrix[i][j].z + z_incr * matrix[i][j].z) : (matrix[i][j].z),
                matrix[i][j].color
                };
			j++;
		}
		i++;
	}
    return(ret_mat);
}
t_pnt3d    **redim2d(t_pnt3d **matrix, t_uint32 length, t_uint32 width,long horiz, long verti)
{
    t_pnt3d **ret_mat;
	/************ allocation ret_mat ****************/
	t_uint32 i = 0;
	ret_mat = (t_pnt3d**)malloc(sizeof(t_pnt3d*) * length);
	while(i < length)
	{
		ret_mat[i] = (t_pnt3d*)malloc(sizeof(t_pnt3d) * width);
		i++;
	}
	/************************************************/
    t_uint32 j;
    i = 0;
    while(i < length)
    {
        j = 0;
        while (j < width)
        {   
            ret_mat[i][j] = (t_pnt3d){
                matrix[i][j].x+horiz,
                matrix[i][j].y+verti,
                0,
                matrix[i][j].color
            };
            j++;
        }
        i++;
    }
    return (ret_mat);
}