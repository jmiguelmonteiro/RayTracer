#ifndef CANVAS_H
# define CANVAS_H

#include "color.h"

#define WIDTH_MAX 1920
#define HEIGHT_MAX 1080

typedef struct	s_canvas
{
	int		width;
	int		height;
	t_color	*pixel_color;
}	t_canvas;

t_canvas	*canvas(int width, int height);
void		write_pixel(t_canvas *c, int x, int y, t_color color);
void		canvas_to_ppm(t_canvas *c);
void		free_canvas(t_canvas *c);

#endif
