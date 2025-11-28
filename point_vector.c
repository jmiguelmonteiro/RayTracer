	#include "raytracer.h"

t_tuple	point(double x, double y, double z)
{
	t_tuple	t;

	t.x = x;
	t.y = y;
	t.z = z;
	t.w = 1;
	return (t);
}

t_tuple	vector(double x, double y, double z)
{
	t_tuple	t;
	
	t.x = x;
	t.y = y;
	t.z = z;
	t.w = 0;
	return (t);
}

t_tuple	add(t_tuple a, t_tuple b)
{
	t_tuple	t;
	
	t.x = a.x + b.x;
	t.y = a.y + b.y;
	t.z = a.z + b.z;
	t.w = a.w + b.w;
	return (t);
}

t_tuple	subtract(t_tuple a, t_tuple b)
{
	t_tuple	t;
	
	t.x = a.x - b.x;
	t.y = a.y - b.y;
	t.z = a.z - b.z;
	t.w = a.w - b.w;
	return (t);
}

t_tuple	negate(t_tuple a)
{
	t_tuple	t;
	
	t.x = -a.x;
	t.y = -a.y;
	t.z = -a.z;
	t.w = -a.w;
	return (t);
}

t_tuple	multiply(t_tuple a, double b)
{
	t_tuple	t;
	
	t.x = a.x * b;
	t.y = a.y * b;
	t.z = a.z * b;
	t.w = a.w * b;
	return (t);
}

t_tuple	divide(t_tuple a, double b)
{
	t_tuple	t;
	
	t.x = a.x / b;
	t.y = a.y / b;
	t.z = a.z / b;
	t.w = a.w / b;
	return (t);
}

double	magnitude(t_tuple a)
{
	double	r;

	r = sqrt(pow(a.x, 2) + pow(a.y, 2) + pow(a.z, 2) + pow(a.w, 2));
	return (r);
}

t_tuple	normalize(t_tuple a)
{
	t_tuple	t;
	double	m;

	m = magnitude(a);
	t.x = a.x / m;
	t.y = a.y / m;
	t.z = a.z / m;
	t.w = a.w / m;
	return (t);
}

double	dot(t_tuple a, t_tuple b)
{
	double	r;

	r = a.x * b.x + a.y * b.y + a.z * b.z + a.w * b.w;
	return (r);
}

t_tuple	cross(t_tuple a, t_tuple b)
{
	t_tuple	t;

	t = vector(a.y * b.z - a.z * b.y,
			a.z * b.x - a.x * b.z,
			a.x * b.y - a.y * b.x);
	return (t);
}
