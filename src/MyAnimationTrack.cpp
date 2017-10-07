#include "MyAnimationTrack.h"

#include <algorithm>

#include "MyDefines.h"
#include "MyMath.h"

MyAnimationTrack::MyAnimationTrack(MyObject3D * obj, unsigned int const & frameCount) :
	object(obj)
{
	keyframeIndices = new std::list<unsigned int>();
	keyframeIndices->push_back(0);

	lastKeyframeIndex = 0;

	frames = new std::vector<MyKeyframe *>();
	frames->push_back(new MyKeyframe());
	if (frameCount != 0)
	{
		for (unsigned int i = 0; i < frameCount - 1; i++)
		{
			frames->push_back(0);
		}
	}
}

MyAnimationTrack::~MyAnimationTrack()
{
	keyframeIndices->clear();
	MyDelete(keyframeIndices);

	for (std::vector<MyKeyframe *>::iterator it = frames->begin(); it != frames->end(); ++it)
	{
		MyDelete(*it);
	}
	frames->clear();
	MyDelete(frames);
}

void MyAnimationTrack::Update(float const & frameTime, bool looping)
{
	if (frames->size() > 0 && keyframeIndices->size() > 0)
	{
		std::list<unsigned int>::iterator lastKeyframe = std::find(keyframeIndices->begin(), keyframeIndices->end(), lastKeyframeIndex);
		std::list<unsigned int>::iterator nextKeyframe = (std::next(lastKeyframe) != keyframeIndices->end()) ?
			std::next(lastKeyframe) : keyframeIndices->begin();


		if (frameTime > *nextKeyframe)
		{
			if (*nextKeyframe < *lastKeyframe && frameTime < *lastKeyframe)
			{
				lastKeyframe = keyframeIndices->begin();
				if (++nextKeyframe == keyframeIndices->end())
				{
					nextKeyframe = keyframeIndices->begin();
				}
			}
			else if (*nextKeyframe > *lastKeyframe)
			{
				if (++lastKeyframe == keyframeIndices->end())
				{
					lastKeyframe = keyframeIndices->begin();
				}
				if (++nextKeyframe == keyframeIndices->end())
				{
					nextKeyframe = keyframeIndices->begin();
				}
			}
			lastKeyframeIndex = *lastKeyframe;
		}

		float t;
		bool interp = true;

		if (*nextKeyframe > *lastKeyframe)
		{
			t = (frameTime - *lastKeyframe) / (*nextKeyframe - *lastKeyframe);
		}
		else
		{
			if (looping)
			{
				t = (frameTime - *lastKeyframe) / (*nextKeyframe + frames->size() - *lastKeyframe);
			}
			else
			{
				interp = false;
			}
		}
		MyVector3D p1 = (*frames)[*lastKeyframe]->GetPosition();
		MyVector3D p2 = (*frames)[*nextKeyframe]->GetPosition();
		MyVector3D r1 = (*frames)[*lastKeyframe]->GetRotation();
		MyVector3D r2 = (*frames)[*nextKeyframe]->GetRotation();
		MyVector3D s1 = (*frames)[*lastKeyframe]->GetScale();
		MyVector3D s2 = (*frames)[*nextKeyframe]->GetScale();

		if (interp)
		{
			object->SetPosition(MyVector4D(LerpF(p1.GetX(), p2.GetX(), t), LerpF(p1.GetY(), p2.GetY(), t), LerpF(p1.GetZ(), p2.GetZ(), t)));
			object->SetRotation(MyVector4D(LerpF(r1.GetX(), r2.GetX(), t), LerpF(r1.GetY(), r2.GetY(), t), LerpF(r1.GetZ(), r2.GetZ(), t)));
			object->SetScale(MyVector4D(LerpF(s1.GetX(), s2.GetX(), t), LerpF(s1.GetY(), s2.GetY(), t), LerpF(s1.GetZ(), s2.GetZ(), t)));
		}
		else
		{
			object->SetPosition(p1);
			object->SetRotation(r1);
			object->SetScale(s1);
		}
	}
}

const MyObject3D * MyAnimationTrack::GetObject() const
{
	return object;
}

void MyAnimationTrack::SetObject(MyObject3D * obj)
{
	object = obj;
}

void MyAnimationTrack::SetFrameCount(unsigned int const & frameCount)
{
	while (frames->size() < frameCount)
	{
		frames->push_back(0);
	}
	while (frames->size() > frameCount)
	{
		MyDelete((*frames)[frames->size() - 1]);
		frames->pop_back();
	}
}

void MyAnimationTrack::RewindTrack()
{
	lastKeyframeIndex = 0;
}

void MyAnimationTrack::AddKeyFrame(unsigned int index, MyKeyframe * keyFrame)
{
	if (index < frames->size())
	{
		bool push = false;
		if (keyframeIndices->size() == 0)
		{
			keyframeIndices->push_back(index);
		}
		else
		{
			for (std::list<unsigned int>::iterator it = keyframeIndices->begin(); it != keyframeIndices->end(); ++it)
			{
				if (index == *it)
				{
					break;
				}
				if (index < *it)
				{
					keyframeIndices->insert(it, index);
					break;
				}
				if (std::next(it) == keyframeIndices->end())
				{
					push = true;
				}
			}
		}
		if (push)
		{
			keyframeIndices->push_back(index);
		}
		MyDelete((*frames)[index]);
		(*frames)[index] = keyFrame;
	}
}

void MyAnimationTrack::RemoveKeyFrame(unsigned int index)
{
	if (index != 0 && index < frames->size())
	{
		keyframeIndices->remove(index);
		MyDelete((*frames)[index]);
	}
}
