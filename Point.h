#ifndef POINT_H
#define POINT_H

#include "Framebuffer.h"

class Point{
public:
	Point(int x, int y, int red, int green, int blue, Framebuffer framebuffer);
	void draw();

private:
	int x_;
	int y_;
	int red_;
	int green_;
	int blue_;
	Framebuffer framebuffer_;
};

#endif