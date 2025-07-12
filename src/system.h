#ifndef SYSTEM_H
#define SYSTEM_H

#include "def.h"

struct s_object
{
	Vec2_f64 pos;
	Vec2_f64 vel;
	Vec2_f64 acc;
	f64 mass;
};
typedef struct s_object Object;

struct s_system
{
	size_t len;
	Object *objs;
};
typedef struct s_system System;

System *createSystem();
void destroySystem(System *sys);
void addObject(System *sys, Vec2_f64 pos, Vec2_f64 vel, Vec2_f64 acc, f64 mass);
void printSystem(System *sys);
void renderSystem(System *sys, f64 pix_per_au, Vec2_f64 cam_pos);
void updateSystem(System *sys);

#endif
