#ifndef MYANIMATIONTRACK_H
#define MYANIMATIONTRACK_H

#include "MyKeyframe.h"
#include "MyObject3D.h"

#include <list>
#include <vector>

class MyAnimationTrack
{
public:
	MyAnimationTrack(MyObject3D *obj = 0, unsigned int const & frameCount = 0);
	~MyAnimationTrack();

	virtual void Update(float const & frameTime, bool looping);

	// Getters
	virtual const MyObject3D *GetObject() const;

	// Setters
	virtual void SetObject(MyObject3D *obj);
	virtual void SetFrameCount(unsigned int const & frameCount);
	virtual void RewindTrack();

	virtual void AddKeyFrame(unsigned int index, MyKeyframe *keyFrame);
	virtual void RemoveKeyFrame(unsigned int index);

private:
	std::list<unsigned int> *keyframeIndices;
	unsigned int lastKeyframeIndex;
	std::vector<MyKeyframe *> *frames;
	MyObject3D *object;

};

#endif // MYANIMATIONTRACK_H
