#pragma once
#include<stdlib.h>
#include<math.h>
#include"include/raylib.h"

typedef struct Circles {

	Color color;
	float radius;
	float rodLenght;
	float w;
	float wPosition;
	float ParentX;
	float ParentY;
}Circles;

Circles* CircleCreate(Color color, float radius, float rodLength, float w, float parentX, float parentY);




int randomize_circle_rodLenght(int min, int max);
int randomize_circle_w(int min, int max);
int randomize_circle_radius(int min, int max);
Color randomize_circle_Color();