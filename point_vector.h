#ifndef POINT_VECTOR_H
# define POINT_VECTOR_H

typedef struct	s_tuple
{
	double	x;
	double	y;
	double	z;
	double	w;
}	t_tuple;

t_tuple	point(double x, double y, double z);
t_tuple	vector(double x, double y, double z);
t_tuple	add(t_tuple a, t_tuple b);
t_tuple	subtract(t_tuple a, t_tuple b);
t_tuple	negate(t_tuple a);
t_tuple	multiply(t_tuple a, double b);
t_tuple	divide(t_tuple a, double b);
double	magnitude(t_tuple a);
t_tuple	normalize(t_tuple a);
double	dot(t_tuple a, t_tuple b);
t_tuple	cross(t_tuple a, t_tuple b);

#endif
