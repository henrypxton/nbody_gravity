#ifndef VIEW_H
#define VIEW_H

#include "def.h"

struct s_view_state
{					    // UNITS:
	Vec2_f64 cam_pos;   // AU
	f64 pix_per_au;     // pix / AU
	f32 time_scale;     // day / s
	f64 dt;             // s
	Vector2 last_mouse; // pix
};
typedef struct s_view_state ViewState;

ViewState *createView();
void destroyView(ViewState *vs);
Vec2_f64 world_to_screen(Vec2_f64 world, ViewState *vs);
Vec2_f64 screen_to_world(Vec2_f64 screen, ViewState *vs);
void updateView(ViewState *vs);

#endif
