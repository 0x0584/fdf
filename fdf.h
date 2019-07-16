/*  
    fdf.h 
    created: july 16, 06:47
*/

#ifndef FDF_H
# define FDF_H

#include "point.h"


typedef struct	s_fdf_data
{
	t_pnt           **base;
	t_uint32        length;
	t_uint32        width;
}				t_fdf_data;

t_fdf_data *point_read_fdf(const int fd);

#endif