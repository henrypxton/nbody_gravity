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

	// PLANET      | INITAL POSITION      | INITIAL VELOCITY     | INITIAL ACCELERATION | MASS
	// --====================================================================================--
	// sun
	addObject(sys, (Vec2_f64){0.00,0.00}, (Vec2_f64){0.00,0.00}, (Vec2_f64){0.00,0.00}, 333000); 
	// earth
	addObject(sys, (Vec2_f64){1.00,0.00}, (Vec2_f64){0.00,0.00}, (Vec2_f64){0.00,0.00}, 1.0000);
	// jupiter
	addObject(sys, (Vec2_f64){5.20,0.00}, (Vec2_f64){0.00,0.00}, (Vec2_f64){0.00,0.00}, 318.00);

	printSystem(sys);

	while(!WindowShouldClose())
	{
		BeginDrawing();
		ClearBackground(BLACK);
		renderSystem(sys, 100, (Vec2_f64){WIDTH/2, HEIGHT/2});
		EndDrawing();
	}

	destroySystem(sys);

	CloseWindow();
	return 0;
}
