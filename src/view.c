#include "view.h"

ViewState *createView()
{
	ViewState *vs = malloc(sizeof(ViewState));
	vs->cam_pos = DEFAULT_CAM_POS;
	vs->pix_per_au = DEFAULT_PIX_PER_AU;
	vs->time_scale = DEFAULT_TIME_SCALE;
	vs->dt = 0;
	vs->last_mouse = GetMousePosition();
	return vs;
}

void destroyView(ViewState *vs)
{
	free(vs);
}

Vec2_f64 world_to_screen(Vec2_f64 world, ViewState *vs)
{
	return (Vec2_f64){
		.x = (world.x + vs->cam_pos.x) * vs->pix_per_au + (GetRenderWidth() / 2.0f),
		.y = (world.y + vs->cam_pos.y) * vs->pix_per_au + (GetRenderHeight() / 2.0f)
	};
}

Vec2_f64 screen_to_world(Vec2_f64 screen, ViewState *vs)
{
	return (Vec2_f64){ 
		.x = (screen.x - (GetRenderWidth() / 2.0f)) / vs->pix_per_au - vs->cam_pos.x,
		.y = (screen.y - (GetRenderWidth() / 2.0f)) / vs->pix_per_au - vs->cam_pos.y
	};
}

void updateView(ViewState *vs)
{
	// update delta time
	vs->dt = GetFrameTime();

	// update zoom level
	f32 scroll = GetMouseWheelMove();
	if (scroll)
		vs->pix_per_au *= pow(ZOOM_SPEED, scroll);

	if (IsMouseButtonDown(MOUSE_LEFT_BUTTON))
	{
		Vector2 mouse = GetMousePosition();
		Vector2 delta = {mouse.x - vs->last_mouse.x, mouse.y - vs->last_mouse.y};
		vs->cam_pos.x += delta.x / vs->pix_per_au;
		vs->cam_pos.y += delta.y / vs->pix_per_au;
		vs->last_mouse = mouse;
	}
	else
	{
		vs->last_mouse = GetMousePosition();
	}

	// update time scale
	if (IsKeyPressed(KEY_LEFT_BRACKET))
		vs->time_scale /= 2;
	else if (IsKeyPressed(KEY_RIGHT_BRACKET))
		vs->time_scale *= 2;
}
