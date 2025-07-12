#include "view.h"

void updateView(ViewState *vs)
{
	vs->dt = GetFrameTime();
	vs->pix_per_au += GetMouseWheelMove() * ZOOM_SPEED;

	if (IsMouseButtonDown(MOUSE_LEFT_BUTTON))
	{
		Vector2 mouse = GetMousePosition();
		Vector2 delta = {mouse.x - vs->last_mouse.x, mouse.y - vs->last_mouse.y};
		vs->cam_pos.x += delta.x / vs->pix_per_au * MOVE_SPEED;
		vs->cam_pos.y += delta.y / vs->pix_per_au * MOVE_SPEED;
		vs->last_mouse = mouse;
	}
	else
	{
		vs->last_mouse = GetMousePosition();
	}

	if (IsKeyPressed(KEY_LEFT_BRACKET))
		vs->time_scale /= 2;
	else if (IsKeyPressed(KEY_RIGHT_BRACKET))
		vs->time_scale *= 2;
}
