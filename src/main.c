#include "system.h"
#include "view.h"

int main()
{
	#ifdef HIDE_INFO
	SetTraceLogLevel(LOG_WARNING);
	#endif

	InitWindow(WIDTH, HEIGHT, TITLE);

	#ifdef MAXIMIZE
	ToggleFullscreen();
	#endif

	System *sys = createSystem();

	// PLANET      | INITAL POSITION      | INITIAL VELOCITY         | INITIAL ACCELERATION | MASS
	// --=========================================================================================--
	// sun
	addObject(sys, (Vec2_f64){0.00,0.00}, (Vec2_f64){0.0000,0.0000}, (Vec2_f64){0.00,0.00}, 333000); 
	// earth
	addObject(sys, (Vec2_f64){1.00,0.00}, (Vec2_f64){0.0000,0.0172}, (Vec2_f64){0.00,0.00}, 1.0000);
	// jupiter
	addObject(sys, (Vec2_f64){5.20,0.00}, (Vec2_f64){0.0000,0.0075}, (Vec2_f64){0.00,0.00}, 318.00);

	ViewState vs = (ViewState){ 
		{ GetScreenWidth()/2, GetScreenHeight()/2 },
		PIX_PER_AU,
		TIME_SCALE,
		0,
		(Vector2){0}
	};

	while(!WindowShouldClose())
	{
		updateView(&vs);
		updateSystem(sys, vs.dt, vs.time_scale);

		BeginDrawing();
			ClearBackground(BLACK);
			renderSystem(sys, vs.pix_per_au, vs.cam_pos);
		EndDrawing();
	}

	destroySystem(sys);

	CloseWindow();
	return 0;
}
