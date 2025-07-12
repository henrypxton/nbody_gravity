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

void renderSystem(System *sys, f64 pix_per_au, Vec2_f64 cam_pos)
{
	for (size_t i=0; i<sys->len; i++)
	{
		Object *obj = sys->objs + i;
		DrawCircle(obj->pos.x * pix_per_au + cam_pos.x, obj->pos.y * pix_per_au + cam_pos.y, log10(obj->mass * 0.05 + 1.2)*20, RAYWHITE);
	}
}

void updateSystem(System *sys);
