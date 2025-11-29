#include "raytracer.h"

typedef struct s_projectile
{
	t_tuple	position;
	t_tuple	velocity;
}	t_projectile;

typedef struct s_environment
{
	t_tuple	gravity;
	t_tuple	wind;
}	t_environment;

t_projectile	tick(t_environment e, t_projectile p)
{
	t_projectile	ret;
	t_tuple			pos;
	t_tuple			vel;

	pos = add(p.position, p.velocity);
	vel = add(p.velocity, add(e.gravity, e.wind));
	ret.position = pos;
	ret.velocity = vel;
	return (ret);
}

int	main(void)
{
	t_projectile	p;
	t_environment	e;
	t_canvas		*c;

	p.position = point(0, 1, 0);
	p.velocity = multiply(normalize(vector(1, 1.8, 0)), 11.25);
	e.gravity = vector(0, -0.1, 0);
	e.wind = vector(-0.01, 0, 0);

	c = canvas(900, 550);
	
	int i = 0;
	// printf("Tick: %d pos x: %f y: %f\n", i, p.position.x, p.position.y);
	write_pixel(c, p.position.x, c->height - p.position.y, color(1,0,0));
	while (p.position.y > 0)
	{
		i++;
		p = tick(e, p);
		// printf("Tick: %d pos x: %f y: %f\n", i, p.position.x, p.position.y);
		write_pixel(c, p.position.x, c->height - p.position.y, color(1,0,0));
	}
	// printf("\n");

	canvas_to_ppm(c);

	free_canvas(c);
}

/*
# projectile starts one unit above the origin.
# velocity is normalized to 1 unit/tick.
p ← projectile(point(0, 1, 0), normalize(vector(1, 1, 0)))
# gravity -0.1 unit/tick, and wind is -0.01 unit/tick.
e ← environment(vector(0, -0.1, 0), vector(-0.01, 0, 0))
*/