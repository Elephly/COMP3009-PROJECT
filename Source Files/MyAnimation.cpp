#include "MyAnimation.h"

#include "MyDefines.h"
#include "MyStringUtil.h"

MyAnimation::MyAnimation(unsigned int const & numFrames, float const & framesPerSecond, bool const & loop) :
	playing(false), elapsedTime(0), frameCount(numFrames), frameRate(framesPerSecond), looping(loop)
{
	frameRate = max(frameRate, 0.0f);
	tracks = new std::map<char *, MyAnimationTrack *>();
}

MyAnimation::~MyAnimation()
{
	for (std::map<char *, MyAnimationTrack *>::iterator it = tracks->begin(); it != tracks->end(); ++it)
	{
		MyDelete(it->second);
	}
	tracks->clear();
	MyDelete(tracks);
}

void MyAnimation::Update(float const & deltaTime)
{
	if (playing)
	{
		elapsedTime += deltaTime;

		float frameTime = elapsedTime * frameRate;

		if (frameTime > frameCount)
		{
			if (looping)
			{
				elapsedTime = deltaTime - ((frameTime - (float)frameCount) / frameRate);
				frameTime = elapsedTime * frameRate;
			}
			else
			{
				playing = false;
				elapsedTime = 0.0f;
				return;
			}
		}

		for (std::map<char *, MyAnimationTrack *>::iterator it = tracks->begin(); it != tracks->end(); ++it)
		{
			it->second->Update(frameTime, looping);
		}
	}
}

const bool MyAnimation::IsPlaying() const
{
	return playing;
}

const bool MyAnimation::IsLooping() const
{
	return looping;
}

const int MyAnimation::GetFrameCount() const
{
	return (int)frameCount;
}

const float MyAnimation::GetFrameRate() const
{
	return frameRate;
}

void MyAnimation::Play()
{
	playing = true;
}

void MyAnimation::Pause()
{
	playing = false;
}

void MyAnimation::Stop()
{
	playing = false;
	elapsedTime = 0.0f;
}

void MyAnimation::SetLooping(bool const & loop)
{
	looping = loop;
}

void MyAnimation::SetFrameCount(unsigned int const & frames)
{
	frameCount = frames;
	for (std::map<char *, MyAnimationTrack *>::iterator it = tracks->begin(); it != tracks->end(); ++it)
	{
		it->second->SetFrameCount(frames);
	}
}

void MyAnimation::SetFrameRate(float const & framesPerSecond)
{
	frameRate = max(framesPerSecond, 0.0f);
}

void MyAnimation::AddTrack(char *trackName, MyAnimationTrack * track)
{
	if (tracks->find(trackName) != tracks->end())
	{
		MyDelete((*tracks)[trackName]);
	}
	(*tracks)[trackName] = track;
	track->SetFrameCount(frameCount);
}

void MyAnimation::RemoveTrack(char * trackName)
{
	MyDelete((*tracks)[trackName]);
	tracks->erase(trackName);
}
