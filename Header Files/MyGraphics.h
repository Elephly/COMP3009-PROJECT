#ifndef MYGRAPHICS_H
#define MYGRAPHICS_H

class MyColorRGBA
{
public:
	MyColorRGBA(float red = 0.0f, float green = 0.0f, float blue = 0.0f, float alpha = 1.0f);
	~MyColorRGBA();

	// Getters
	float GetRed() const;
	float GetGreen() const;
	float GetBlue() const;
	float GetAlpha() const;
	const float &GetRedAddr() const;
	const float &GetGreenAddr() const;
	const float &GetBlueAddr() const;
	const float &GetAlphaAddr() const;

	// Setters
	void SetRed(float const & red);
	void SetGreen(float const & green);
	void SetBlue(float const & blue);
	void SetAlpha(float const & alpha);

private:
	float r;
	float g;
	float b;
	float a;
};

class MyColors
{
public:
	static const MyColorRGBA CornflowerBlue;
};

#endif // MYGRAPHICS_H
