#ifndef VIEW_H
#define VIEW_H

#include "def.h"

struct s_view_state
{
	Vec2_f64 cam_pos;
	f64 pix_per_au;
	f32 time_scale;
	f64 dt;
	Vector2 last_mouse;
};
typedef struct s_view_state ViewState;

void updateView(ViewState *vs);

#endif
