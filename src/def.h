#ifndef DEF_H
#define DEF_H

#include "raylib.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define WIDTH 1000
#define HEIGHT 450
#define TITLE "nbody project"
#define MAXIMIZE
#define HIDE_INFO

#define G 8.898e-10
#define TIME_SUBSTEP 0.1

typedef int i32;
typedef unsigned int u32;
typedef float f32;
typedef double f64;

struct s_vec2_f64
{
	f64 x;
	f64 y;
};
typedef struct s_vec2_f64 Vec2_f64;

#endif
