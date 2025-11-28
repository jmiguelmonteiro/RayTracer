#ifndef COLOR_H
# define COLOR_H

typedef struct	s_color
{
	double	red;
	double	green;
	double	blue;
}	t_color;

t_color	color(double red, double green, double blue);
t_color	add_color(t_color a, t_color b);
t_color	subtract_color(t_color a, t_color b);
t_color	multiply_color(t_color a, double b);
t_color	hadamart_product(t_color a, t_color b);

#endif
