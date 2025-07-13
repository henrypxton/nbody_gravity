#include "system.h"

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
	// mars
	addObject(sys, (Vec2_f64){1.52,0.00}, (Vec2_f64){0.0000,0.0139}, (Vec2_f64){0.00,0.00}, 0.1070);
	// jupiter
	addObject(sys, (Vec2_f64){5.20,0.00}, (Vec2_f64){0.0000,0.0075}, (Vec2_f64){0.00,0.00}, 318.00);
	// saturn
	addObject(sys, (Vec2_f64){9.58,0.00}, (Vec2_f64){0.0000,0.0056}, (Vec2_f64){0.00,0.00}, 95.160);
	// uranus
	addObject(sys, (Vec2_f64){19.2,0.00}, (Vec2_f64){0.0000,0.0039}, (Vec2_f64){0.00,0.00}, 14.540);
	// neptune
	addObject(sys, (Vec2_f64){30.2,0.00}, (Vec2_f64){0.0000,0.0031}, (Vec2_f64){0.00,0.00}, 17.150);

	ViewState *vs = createView();

	while(!WindowShouldClose())
	{
		updateView(vs);
		updateSystem(sys, vs);

		BeginDrawing();
			ClearBackground(BLACK);
			renderSystem(sys, vs);
		EndDrawing();
	}

	destroyView(vs);
	destroySystem(sys);

	CloseWindow();
	return 0;
}
