#ifndef MYGRAPHICS_H
#define MYGRAPHICS_H

class MyColors
{
public:
	//static const MyColorRGBA CornflowerBlue;
};

class MyColorRGBA
{
public:
	MyColorRGBA(float red = 0.0f, float green = 0.0f, float blue = 0.0f, float alpha = 1.0f);
	~MyColorRGBA();

	// Getters
	float &GetRed();
	float &GetGreen();
	float &GetBlue();
	float &GetAlpha();

	// Setters
	void SetRed(float red);
	void SetGreen(float green);
	void SetBlue(float blue);
	void SetAlpha(float alpha);

private:
	float r;
	float g;
	float b;
	float a;
};

#endif // MYGRAPHICS_H
