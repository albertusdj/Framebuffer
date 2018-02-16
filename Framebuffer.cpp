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
#include "Framebuffer.h"

Framebuffer::Framebuffer(){
	fbfd_ = open("/dev/fb0", O_RDWR);
    if (fbfd_ == -1) {
        perror("Error: cannot open framebuffer device");
        exit(1);
    }
    printf("The framebuffer device was opened successfully.\n");

    // Get fixed screen information
    if (ioctl(fbfd_, FBIOGET_FSCREENINFO, finfo_) == -1) {
        perror("Error reading fixed information");
        exit(2);
    }

    // Get variable screen information
    if (ioctl(fbfd_, FBIOGET_VSCREENINFO, vinfo_) == -1) {
        perror("Error reading variable information");
        exit(3);
    }

    printf("%dx%d, %dbpp\n", vinfo_->xres, vinfo_->yres, vinfo_->bits_per_pixel);

    // Figure out the size of the screen in bytes
    long int screensize = vinfo_->xres * vinfo_->yres * vinfo_->bits_per_pixel / 8;

    // Map the device to memory
    fbp_ = (char *)mmap(0, screensize, PROT_READ | PROT_WRITE, MAP_SHARED,
                        fbfd_, 0);
    if ((long)fbp_ == -1) {
        perror("Error: failed to map framebuffer device to memory");
        exit(4);
    }
    printf("The framebuffer device was mapped to memory successfully.\n");
}

int Framebuffer::GetXOffset(){
    return vinfo_->xoffset;
}

int Framebuffer::GetYOffset(){
    return vinfo_->yoffset;
}

int Framebuffer::GetBitsPerPixel(){
    return vinfo_->bits_per_pixel;
}

int Framebuffer::GetLineLength(){
    return finfo_->line_length;
}

char * Framebuffer::GetFbp(){
    return fbp_;
}