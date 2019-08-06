# include "point.h"
# include <math.h>

t_pnt3d projetion_iso(t_pnt3d point);
t_pnt3d **rotationX(t_pnt3d **matrix, t_uint32 length, t_uint32 width ,float angle);
t_pnt3d **rotationY(t_pnt3d **matrix, t_uint32 length, t_uint32 width, float angle);
t_pnt3d **rotationZ(t_pnt3d **matrix, t_uint32 length, t_uint32 width, float angle);
t_pnt3d    **projestion(t_pnt3d **matrix, t_uint32 length, t_uint32 width, char project_methode);
t_pnt3d    projetion_iso(t_pnt3d point);
t_pnt3d    produit_matrix(t_pnt3d point, float rot_matrix[3][3]);
t_pnt3d **redim(t_pnt3d **matrix, int length,int width, long spacing, long z_incr);
t_pnt3d    **redim2d(t_pnt3d **matrix, t_uint32 length, t_uint32 width,long horiz, long verti);


