#ifndef MYGRAPHICS_H
#define MYGRAPHICS_H

class MyColorRGBA
{
public:
	MyColorRGBA(float red = 0.0f, float green = 0.0f, float blue = 0.0f, float alpha = 1.0f);
	~MyColorRGBA();

private:
	float r;
	float g;
	float b;
	float a;
};

#endif // MYGRAPHICS_H
