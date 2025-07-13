#ifndef DEF_H
#define DEF_H

#include "raylib.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

// window initialisation
#define WIDTH 1000
#define HEIGHT 450
#define TITLE "nbody project"
#define MAXIMIZE
#define HIDE_INFO

// view constants
#define DEFAULT_CAM_POS (Vec2_f64){ 0, 0 }
#define DEFAULT_PIX_PER_AU 100
#define DEFAULT_TIME_SCALE 64
#define ZOOM_SPEED 1.1
#define DRAG_SPEED 100
#define OBJ_RADIUS(obj_mass) (log10((obj_mass) * 0.05 + 1.2) * 20.0 / DEFAULT_PIX_PER_AU)

// physics sim constants
#define G 8.898e-10
#define TIME_SUBSTEP 0.1

// types
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
