#include "file.h"

void loadSystemFromFile(System *sys, const char *filename)
{
	FILE *fptr = fopen(filename, "r");

	if (!fptr)
	{
		fprintf(stderr, "Failed to open file: %s\n", filename);
		exit(1);
	}

	char name[50];
	f64 x, y, vx, vy, ax, ay, mass;

	while (fscanf(fptr, "%s %lf %lf %lf %lf %lf %lf %lf", name, &x, &y, &vx, &vy, &ax, &ay, &mass) > 0)
		addObject(
			sys,
			(Vec2_f64){ x, y },
			(Vec2_f64){ vx, vy },
			(Vec2_f64){ ax, ay },
			mass
		);

	fclose(fptr);
}
