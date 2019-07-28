# include "point.h"
# include <math.h>

t_pnt2d **projetion_matrice(t_pnt3d matrice, t_uint32 length, t_uint32 width);
t_pnt3d    **rotationX(t_pnt3d **matrix, t_uint32 length, t_uint32 width ,float angle);
t_pnt3d    **rotationY(t_pnt3d **matrix, t_uint32 length, t_uint32 width, float angle);
t_pnt3d    **rotationZ(t_pnt3d **matrix, t_uint32 length, t_uint32 width, float angle);


