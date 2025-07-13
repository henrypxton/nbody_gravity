#include "system.h"

System *createSystem()
{
	System* sys = (System*) malloc(sizeof(System));
	sys->len = 0;
	sys->objs = (void*) NULL;
	return sys;
}

void destroySystem(System *sys)
{
	free(sys->objs);
	free(sys);
}

void addObject(System *sys, Vec2_f64 pos, Vec2_f64 vel, Vec2_f64 acc, f64 mass)
{
	sys->len++;
	sys->objs = (Object*) realloc(sys->objs, sizeof(Object)*sys->len);
	sys->objs[sys->len-1] = (Object){ pos, vel, acc, mass };
}

void printSystem(System *sys)
{
	printf("System:\n");
	for (size_t i=0; i<sys->len; i++)
	{
		printf("  Object %lu:\n", i);
		printf("    position:     (%+lf, %+lf)\n", sys->objs[i].pos.x, sys->objs[i].pos.y);
		printf("    velocity:     (%+lf, %+lf)\n", sys->objs[i].vel.x, sys->objs[i].vel.y);
		printf("    acceleration: (%+lf, %+lf)\n", sys->objs[i].acc.x, sys->objs[i].acc.y);
		printf("    mass:         %lf\n", sys->objs[i].mass);
	}
}

void renderSystem(System *sys, ViewState *vs)
{
	for (size_t i=0; i<sys->len; i++)
	{
		Object *obj = sys->objs + i;
		Vec2_f64 screen_coord = world_to_screen(obj->pos, vs);
		DrawCircle(screen_coord.x, screen_coord.y, OBJ_RADIUS(obj->mass) * vs->pix_per_au, RAYWHITE);
	}
}

void updateSystem(System *sys, ViewState *vs)
{
	f64 total_dt = vs->dt * vs->time_scale;
	u32 steps = (u32)(total_dt / TIME_SUBSTEP) + 1;
	f64 subset_dt = total_dt / steps; 
	
	for (u32 s=0; s<steps; s++)
	{
		// update position: x(t + dt) = x(t) + v(t) dt + 1/2 a(t) dt^2
		for (size_t i=0; i<sys->len; i++)
		{
			Object *a = sys->objs + i;
			a->pos.x = a->pos.x + a->vel.x * subset_dt + 0.5 * a->acc.x * subset_dt * subset_dt;
			a->pos.y = a->pos.y + a->vel.y * subset_dt + 0.5 * a->acc.y * subset_dt * subset_dt;
		}

		// store current acceleration
		Vec2_f64 old_accs[sys->len];
		for (size_t i=0; i<sys->len; i++)
			old_accs[i] = sys->objs[i].acc;

		// calculate new acceleration: a = G * m / r^2
		for (size_t i=0; i<sys->len; i++)
		{
			Object *a = sys->objs + i;
			a->acc = (Vec2_f64){ 0, 0 };
			for (size_t j=0; j<sys->len; j++)
			{
				if (i==j) continue;

				Object *b = sys->objs + j;

				f64 dx = b->pos.x - a->pos.x;
				f64 dy = b->pos.y - a->pos.y;
				f64 dist_sqr = dx * dx + dy * dy;
				f64 dist = sqrt(dist_sqr);
				f64 acc = G * b->mass / dist_sqr;
				
				a->acc.x += acc * dx / dist;
				a->acc.y += acc * dy / dist;
			}
		}

		// calculate velocity: v(t + dt) = v(t) + 1/2 ( a(t) + a(t + dt) ) * dt;
		for (size_t i=0; i<sys->len; i++)
		{
			Object *a = sys->objs + i;
			a->vel.x = a->vel.x + 0.5 * ( old_accs[i].x + a->acc.x ) * subset_dt;
			a->vel.y = a->vel.y + 0.5 * ( old_accs[i].y + a->acc.y ) * subset_dt;
		}
	}
}
