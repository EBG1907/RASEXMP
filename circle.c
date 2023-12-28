
#include "circle.h"


Circles* CircleCreate(Color color, float radius, float rodLength, float w, float ParentX, float ParentY) {

		Circles* PtrCircle = malloc(sizeof(Circles));
		PtrCircle->color = color;
		PtrCircle->radius = radius;
		PtrCircle->rodLenght = rodLength;
		PtrCircle->w = w*(PI/180);
		PtrCircle->wPosition = 0;
		PtrCircle->ParentX = ParentX+rodLength*cos(PtrCircle->wPosition);
		PtrCircle->ParentY = ParentY + rodLength * sin(PtrCircle->wPosition);

		return PtrCircle;




}
int randomize_circle_rodLenght(int min,int max) {

	return rand() % (max - min + 1) + min;
}
int randomize_circle_w(int min, int max) {
	return rand() % (max - min + 1) + min;

}
Color randomize_circle_Color() {
	Color color;
	
	color.r = rand() % 256;
	color.g = rand() % 256;
	color.b = rand() % 256; 
	return color;
}

int randomize_circle_radius(int min, int max) {

	return rand() % (max - min + 1) + min;
}


