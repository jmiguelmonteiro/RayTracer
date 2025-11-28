#include "raytracer.h"

t_color	color(double red, double green, double blue)
{
	t_color	r;

	r.red = red;
	r.green = green;
	r.blue = blue;
	return (r);
}

t_color	add_color(t_color a, t_color b)
{
	t_color	r;
	
	r.red = a.red + b.red;
	r.green = a.green + b.green;
	r.blue = a.blue + b.blue;
	return (r);
}

t_color	subtract_color(t_color a, t_color b)
{
	t_color	r;
	
	r.red = a.red - b.red;
	r.green = a.green - b.green;
	r.blue = a.blue - b.blue;
	return (r);
}

t_color	multiply_color(t_color a, double b)
{
	t_color	r;
	
	r.red = a.red * b;
	r.green = a.green * b;
	r.blue = a.blue * b;
	return (r);
}

t_color	hadamart_product(t_color a, t_color b)
{
	t_color	r;
	
	r.red = a.red * b.red;
	r.green = a.green * b.green;
	r.blue = a.blue * b.blue;
	return (r);
}
