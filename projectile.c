#include "rt.h"

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

t_projectile	tick(t_environment e, t_projectile p);

t_projectile	tick(t_environment e, t_projectile p)
{
	t_projectile	ret;
	t_tuple			pos;
	t_tuple			vel;

	pos = add(p.position + p.velocity);
	vel = add(p.velocity + add(e.gravity, e.wind));
	return (ret);
}
