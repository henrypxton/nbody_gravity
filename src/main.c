#include "file.h"

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

	loadSystemFromFile(sys, SYSTEM_FILE);

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
