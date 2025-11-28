#include "raytracer.h"

t_canvas	*canvas(int width, int height)
{
	t_canvas	*r;

	r = malloc(sizeof(t_canvas));
	if (!r)
		return (NULL);
	r->width = width;
	r->height = height;
	r->pixel_color = malloc(width * height * sizeof(t_color));
	if (!r->pixel_color)
		return (free(r), NULL);
	for (int y = 0; y < height; y++)
		for (int x = 0; x < width; x++)
			r->pixel_color[x * width + y] = color(0, 0, 0);
	return (r);
}

void	write_pixel(t_canvas *c, int x, int y, t_color color)
{
	if (x < 0 || x >= c->width || y < 0 || y >= c->height)
		return ;
	c->pixel_color[x * c->width + y] = color;
}

void	canvas_to_ppm(t_canvas *c)
{
	printf("P3\n%d %d\n255\n", c->width, c->height);
	// for (int y = 0; y < c->height; y++)
	// {
	// 	for (int x = 0; x < c->width; x++)
	// 		printf("%d %d %d ", c->pixel_color[x * c->height + y].red,
	// 			c->pixel_color[x * c->height + y].green,
	// 			c->pixel_color[x * c->height + y].blue);
	// 	printf("\n");
	// }
}

void	free_canvas(t_canvas *c)
{
	free(c->pixel_color);
	free (c);
}
