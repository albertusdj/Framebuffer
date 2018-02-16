#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <linux/fb.h>
#include <sys/mman.h>
#include <sys/ioctl.h>
#include <math.h>
#include <limits.h>
#include <time.h>
#include <pthread.h>
#include "Point.h"
#include "Framebuffer.h"

Point::Point(int x, int y, int red, int green, int blue, Framebuffer framebuffer){
	x_ = x;
	y_ = y;
	red_ = red;
	green_ = green;
	blue_ = blue;
	framebuffer = framebuffer_;
}

void Point::draw(){
    long int location = (x_+framebuffer_.GetXOffset()) * (framebuffer_.GetBitsPerPixel()/8) + 
            (y_+ framebuffer_.GetYOffset()) * framebuffer_.GetLineLength();
    *(framebuffer_.GetFbp() + location) = red_;
    *(framebuffer_.GetFbp() + location + 1) = green_;
    *(framebuffer_.GetFbp() + location + 2) = blue_;
}