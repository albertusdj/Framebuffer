#ifndef FRAMEBUFFER_h
#define FRAMEBUFFER_h

class Framebuffer{
public:
	Framebuffer();
	int GetXOffset();
	int GetYOffset();
	int GetBitsPerPixel();
	int GetLineLength();
	char * GetFbp();


private:
	int fbfd_;
	struct fb_var_screeninfo *vinfo_;
	struct fb_fix_screeninfo *finfo_;
	long int screensize_;
	char *fbp_;
};

#endif