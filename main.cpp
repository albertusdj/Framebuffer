#include "Framebuffer.h"
#include "Point.h"

int main(){
	Framebuffer framebuffer();

	Point p1(500, 500, 255, 0, 0, framebuffer);
	p1.draw();
}