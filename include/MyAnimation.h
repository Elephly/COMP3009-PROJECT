#ifndef MYANIMATION_H
#define MYANIMATION_H

class MyObject3D;

#include "MyAnimationTrack.h"

#include <map>

class MyAnimation
{
public:
	MyAnimation(unsigned int const & numFrames = 0, float const & framesPerSecond = 30, bool const & loop = false);
	~MyAnimation();

	virtual void Update(float const & deltaTime);

	// Getters
	virtual const bool IsPlaying() const;
	virtual const bool IsLooping() const;
	virtual const int GetFrameCount() const;
	virtual const float GetFrameRate() const;

	// Setters
	virtual void Play();
	virtual void Pause();
	virtual void Stop();
	virtual void SetLooping(bool const & loop);
	virtual void SetFrameCount(unsigned int const & frames);
	virtual void SetFrameRate(float const & framesPerSecond);

	virtual void AddTrack(const char *trackName, MyAnimationTrack *track);
	virtual void RemoveTrack(const char *trackName);

private:
	bool playing;
	bool looping;
	float elapsedTime;
	unsigned int frameCount;
	float frameRate;
	std::map<const char *, MyAnimationTrack *> *tracks;

};

#endif // MYANIMATION_H
