#include "raytracer.h"

t_canvas	*canvas(int width, int height)
{
	t_canvas	*r;

	// Allocate main struct
	r = malloc(sizeof(t_canvas));
	if (!r)
		return (NULL);
	r->width = width;
	r->height = height;

	// Allocate rows
	r->pixel_color = malloc(width * sizeof(t_color *));
	if (!r->pixel_color)
		return (free(r), NULL);

	// Allocate cols
	for (int i = 0; i < width; i++)
	{
		r->pixel_color[i] = malloc(height * sizeof(t_color));
		if (!r->pixel_color[i])
		{
			while (i--)
				free(r->pixel_color[i]);
			free(r->pixel_color);
			return (free(r), NULL);
		}
	}
	for (int y = 0; y < height; y++)
		for (int x = 0; x < width; x++)
			r->pixel_color[x][y] = color(0, 0, 0);
	return (r);
}

void	write_pixel(t_canvas *c, int x, int y, t_color color)
{
	if (x < 0 || x >= c->width || y < 0 || y >= c->height)
		return ;
	c->pixel_color[x][y] = color;
}

t_color	read_pixel(t_canvas *c, int x, int y)
{
	if (x < 0 || x >= c->width || y < 0 || y >= c->height)
		return color(0, 0, 0) ;
	return (c->pixel_color[x][y]);
}

int	scale_color(double value)
{
	return ((int)(fmax(fmin(value, 1.0), 0.0) * 255));
}

void	canvas_to_ppm(t_canvas *c)
{
	int		line_len;
	int		value_len;
	char	str[4];

	printf("P3\n%d %d\n255\n", c->width, c->height);
	for (int y = 0; y < c->height; y++)
	{
		line_len = 0;
		for (int x = 0; x < c->width; x++)
		{
			value_len = sprintf(str, "%d", scale_color(c->pixel_color[x][y].red));
			if ((value_len + line_len) > 70)
			{
				printf("\n");
				line_len = 0;
			}
			line_len += printf("%s", str);
			if (line_len != 70)
				line_len += printf(" ");

			value_len = sprintf(str, "%d", scale_color(c->pixel_color[x][y].green));
			if ((value_len + line_len) > 70)
			{
				printf("\n");
				line_len = 0;
			}
			line_len += printf("%s", str);
			if (line_len != 70)
				line_len += printf(" ");

			value_len = sprintf(str, "%d", scale_color(c->pixel_color[x][y].blue));
			if ((value_len + line_len) > 70)
			{
				printf("\n");
				line_len = 0;
			}
			line_len += printf("%s", str);
			if ((x != (c->width - 1)) && (line_len != 70))
				line_len += printf(" ");
		}
		printf("\n");
	}
	printf("\n");
}

void	free_canvas(t_canvas *c)
{
	for (int i=0; i < c->height; i++)
		free(c->pixel_color[i]);
	free(c->pixel_color);
	free (c);
}
